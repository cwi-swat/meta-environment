module Versioning

  require 'fileutils'
  require 'tempfile'
  require 'time'
  require 'tmpdir'

  require 'utils/empty-shell'



  class RepositoryFactory

    def initialize(repositories = nil)
      @repositories = repositories
    end

    def repository(name, repositories = @repositories)
      repositories.each do |repo|
        if repo['components'].include?(name) then
          return make_repository(repo['type'], repo['protocol'], repo['location'])
        end
      end
      raise RuntimeError.new("cannot find module #{name} in #{repositories.inspect}")
    end

    def make_repository(type, protocol, location)
      if type == 'cvs' then
        return CVSRepository.new(protocol, location)
      elsif type == 'subversion' then
        return SVNRepository.new(protocol, location)
      end
      raise RuntimeError.new("unknown repository type: #{type}")    
    end
  end


  class Repository
    include FileUtils

    def initialize(protocol, location)
      @protocol = protocol
      @location = location
    end

    def prepare(targetdir, dirname)
      path = File.join(targetdir, dirname)
      cd(targetdir) do
        if test(?d, dirname) then
          if ['.', '/', '~/', ENV['HOME']].include?(dirname) then
            raise "Invalid dirname: #{dirname}"
          end 
          backup_path = File.join(Dir.tmpdir, dirname)
          # $stderr << "WARNING: checkout exists: #{path} moved to #{backup_path}.\n"
          `chmod -R 0700 #{dirname}`
          #`cp -r -f #{dirname} #{backup_path}`
          `rm -r #{dirname}`
        end
        yield
      end
    end


    def trunk_prepare(targetdir, dirname)
      path = File.join(targetdir, dirname)
      cd(targetdir) do
        if not test(?d, path) then
          yield
        else
          $stderr << "Checkout #{path} exists; skipped.\n"
        end
      end
    end

  end

  class CVSRepository < Repository
    def initialize(protocol, location)
      super(protocol, location)
      @shell = Utils::CommandSpecificShell.new('cvs')
    end

    def trunk_checkout(user, modulename, targetdir, dirname = modulename)
      path = File.join(targetdir, dirname)
      cd(targetdir) do
        if not test(?d, dirname) then
          cvs_command(user, "co #{modulename}")
          if modulename != dirname then
            mv(modulename, dirname)
          end
        end
      end
      return CVSCheckout.new(self, path)    
    end

    def checkout(user, time, modulename, targetdir, dirname = modulename)
      cvs_time = convert_to_gmt(time)
      path = File.join(targetdir, dirname)
      cd(targetdir) do
        if test(?d, dirname) then
          if ['.', '/', '~/', ENV['HOME']].include?(dirname) then
            raise "Invalid dirname: #{dirname}"
          end 
          backup_path = File.join(Dir.tmpdir, dirname)
          # $stderr << "WARNING: checkout exists: #{path} moved to #{backup_path}.\n"
          `chmod -R 0700 #{dirname}`
          #`cp -r -f  #{dirname} #{backup_path}`
          `rm -r #{dirname}`
        end
        cvs_command(user, "co -D \"#{cvs_time}\" #{modulename}")
        if modulename != dirname then
          mv(modulename, dirname)
        end
      end
      return CVSCheckout.new(self, path)
    end

    def convert_to_gmt(time)
      cvs_time = time.clone
      cvs_time.gmtime
      return cvs_time
    end

    def empty_file?(path)
      return !test(?s, path)
    end

    def cvs_url(user)
      if @protocol == 'ssh' then
        return ":ext:#{user}@#{@location}"
      end
      raise RuntimeError.new("unsupported CVS protocol: #{@protocol}")
    end

    def cvs_command(user, options)
      url = cvs_url(user)
      @shell.execute("cvs -Q -d #{url} #{options}")
    end
    
    def to_s
      return "cvs+#{@protocol}://#{@location}"
    end

  end

  class SVNRepository < Repository

    def initialize(protocol, location)
      super(protocol, location)
      @shell = Utils::CommandSpecificShell.new('svn_ssh')
    end
    

    def svn_url(path)
      if @protocol == 'svn+ssh' or
          @protocol == 'svn' or
          @protocol == 'file' then 
        return File.join("#{@protocol}://#{@location}", path)
      end
      raise RuntimeError.new("unsupported SVN protocol: #{@protocol}")
    end

    def svn_time(time)
      return time.strftime("%Y%m%dT%H%M")
    end

    def svn_checkout(user, path, time, dirname)
      url = svn_url(path)
      @shell.execute("svn --username #{user} checkout --revision {#{time}} #{url}/trunk #{dirname}")
    end

    def svn_trunk_checkout(user, path, dirname)
      url = svn_url(path)
      @shell.execute("svn --username #{user} checkout #{url}/trunk #{dirname}")
    end

    def checkout_path(targetdir, dirname)
      return File.join(targetdir, dirname)
    end
    
    def trunk_checkout(user, path, targetdir, dirname = File.basename(path))  
      trunk_prepare(targetdir, dirname) do 
        svn_trunk_checkout(user, path, dirname)
      end
      return SVNCheckout.new(self, checkout_path(targetdir, dirname))
    end



    def checkout(user, time, path, targetdir, dirname = File.basename(path))
      prepare(targetdir, dirname) do 
        svn_checkout(user, path, svn_time(time), dirname)
      end
      return SVNCheckout.new(self, checkout_path(targetdir, dirname))
    end
    
  end

  class BOMReader
    def initialize(path)
      File.open(path) do |f|
        @bom = f.read
      end
    end
    
  end

  class PackageBOMReader < BOMReader
    def version
      if @bom =~ /version\s*=\s*([0-9\.a-bA-Z_\-]+)/m then
        return $1
      end
      raise RuntimeError.new("error parsing version in: #{text}")
    end

    def dependencies
      requires = @bom
      requires.sub!(/.*requires/m, '')
      requires.sub!(/configuration.*/m, '')
      requires.squeeze!("\n")
      requires.strip!
      return remove_versions(requires.split("\n"))
    end

    private

    def remove_versions(deps)
      return deps.collect do |dep|
        dep.split[0]
      end.uniq
    end  

  end

  class PKGConfigBOMReader < BOMReader
    def version
      if @bom =~ /Version\s*:\s*([0-9\.a-bA-Z_\-]+)/m then
        return $1
      end
      raise RuntimeError.new("error parsing version in: #{@bom}")
    end

    def dependencies
      if @bom =~ /^Requires\s*:\s*(.*)$/m then
        return $1.split
      end
      raise RuntimeError.new("error parsing dependencies in: #{@bom}")
    end

  end
  


  class Checkout
    attr_reader :path, :repository

    def initialize(repository,  path)
      @repository = repository
      @path = path
    end

    def version
      raise RuntimeError.new("class Checkout is abstract!")
    end

    def changelog
      s = ''
      File.open(File.join(@path, 'ChangeLog')) do |f|
        s = f.read
      end
      return s.gsub("\0", ' ')
    end

    def bom_reader
      pkg_files = Dir["#{@path}/*.pc.in"] 
      if pkg_files.empty? then
        return PackageBOMReader.new(depfile_path(@path))
      else
        return PKGConfigBOMReader.new(pkg_files[0])
      end
    end

    def extract_deps
      return bom_reader.dependencies
    end

    def extract_version
      return bom_reader.version
    end

    def depfile_path(root)
      path = File.join(root, 'package')
      if not test(?f, path) then
        pattern = File.join(root, "*.pkg")
        pkgs = Dir[pattern]
        path = pkgs == [] ? nil : pkgs[0]
      end
      if path.nil? then
        raise RuntimeError.new("no dependency file found in #{root}!")
      end
      return path
    end 

    def to_s
      return "#{path}@#{repository}"
    end

  end

  class CVSCheckout < Checkout
    def version
      return time_of_last_commit.to_i
    end

    def time_of_last_commit
      sorted_dates = entry_dates(@path).sort
      return sorted_dates.at(-1)
    end

    def entry_dates(path)
      dates = []
      pattern = File.join(path, '**', 'Entries')
      Dir[pattern].each do |entries_path|
        dates += parse_dates(entries_path)
      end
      return dates
    end  
    
    def parse_dates(entries_path)
      dates = []
      File.open(entries_path) do |f|
        f.each_line do |line|
          if  /^\/.*\/.*\/(.*) ([0-9]{4})\/.*\// =~ line then
            dates << Time.parse("#{$1} GMT #{$2}")
          end
        end
      end
      return dates
    end   
  end

  class SVNCheckout < Checkout
    def initialize(repository,  path)
      super(repository, path)
      @shell = Utils::CommandSpecificShell.new('subversion')
    end
    
    def version
      info = @shell.read("svn info #{@path}")
      info.split("\n").each do |line|
        if line =~ /Last Changed Rev: ([0-9]+)/ then
          return $1.to_i
        end
      end
      raise RuntimeError.new("subversion didn't behave as expected: #{info.split.inspect}")
    end
  end

end
