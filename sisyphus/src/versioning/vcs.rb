module Versioning

  require 'fileutils'
  require 'tempfile'
  require 'time'
  require 'tmpdir'

  require 'utils/empty-shell'

  require 'versioning/boms'

  class RepositoryFactory

    def initialize(repositories = nil)
      @repositories = repositories
    end

    def repository(name, repositories = @repositories)
      repositories.each do |repo|
        if repo['components'].include?(name) then
          return make_repository(repo['type'], repo['protocol'], repo['location'], repo['components'])
        end
      end
      raise RuntimeError.new("cannot find module #{name} in #{repositories.inspect}")
    end


    def make_repository(type, protocol, location, components)
      if type == 'cvs' then
        return CVSRepository.new(protocol, location, components)
      elsif type == 'subversion' then
        return SVNRepository.new(protocol, location, components)
      end
      raise RuntimeError.new("unknown repository type: #{type}")    
    end
  end


  class Repository
    include FileUtils

    def initialize(protocol, location, components)
      @protocol = protocol
      @location = location
      @components = components
    end

    def prepare(targetdir, dirname)
      path = File.join(targetdir, dirname)
      cd(targetdir) do
        if test(?d, dirname) then
          if ['.', '/', '~/', ENV['HOME']].include?(dirname) then
            raise "Invalid dirname: #{dirname}"
          end 
          backup_path = File.join(Dir.tmpdir, dirname)
          `chmod -R 0700 #{dirname}`
          `rm -r #{dirname}`
        end
        yield
      end
    end


    def component_location(component)
      name = component.name
      if @components.include?(name) then
        return File.join(name, @components[name])
      end
      raise RuntimeError.new("cannot find module #{name} in #{self.inspect}")
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

  class SVNRepository < Repository

    def initialize(protocol, location, components)
      super(protocol, location, components)
      @shell = Utils::CommandSpecificShell.new('svn_ssh')
    end
    
    def svn_url(path, user = nil)
      if @protocol == 'file' then 
        return File.join("#{@protocol}://#{@location}", path)
      end

      if @protocol == 'svn+ssh' or @protocol == 'svn' then
        if user then
          return File.join("#{@protocol}://#{user}@#{@location}", path)
        else
          return File.join("#{@protocol}://#{@location}", path)
        end
      end
      raise RuntimeError.new("unsupported SVN protocol: #{@protocol}")
    end

    def iso_time(time)
      #2007-03-09T15:51:07+0100
      time.strftime("%Y-%m-%dT%H:%M:%S")
    end

    def svn_time(time)
      #t = time.strftime("%Y%m%dT%H%M%S")
      t = iso_time(time)
      return t
    end

    

    def svn_checkout_OLD_UGLY(user, path, time, dirname)
      url = svn_url(path, user)
      @shell.execute("svn checkout --revision {#{time}} #{url}/trunk #{dirname}")
    end

    def svn_trunk_checkout_OLD_UGLY(user, path, dirname)
      url = svn_url(path, user)
      @shell.execute("svn checkout #{url}/trunk #{dirname}")
    end

    def svn_checkout(user, path, time, dirname)
      url = svn_url(path, user)
      @shell.execute("svn checkout --revision {#{time}} #{url} #{dirname}")
    end

    def svn_trunk_checkout(user, path, dirname)
      url = svn_url(path, user)
      @shell.execute("svn checkout #{url} #{dirname}")
    end

    def svn_cat_pkgconfig_file(user, path, time)
      return svn_cat(user, path, time, "#{path}.pc.in")
    end

    def svn_cat(user, path, time, subpath)
      url = svn_url(path, user)
      time_str = ''
      if time then
        time_str = " --revision "
        if time.is_a?(Time) then
          time_str += "{" + svn_time(time) + "}"
        else
          time_str += time.to_s
        end
      end
      if user then
        user_str = "--username #{user}"
      else
        user_str = ''
      end
      return @shell.read("svn #{user_str} cat #{time_str} #{url}/trunk/#{subpath}") 
    end

    def checkout_path(targetdir, dirname)
      return File.join(targetdir, dirname)
    end
    
    def tagged_checkout(user, path, targetdir, tag, dirname = File.basename(path) + "_" + tag)
      trunk_checkout(user, path, targetdir, dirname)
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
      r = revision(user, time, path)
      return SVNCheckout.new(self, checkout_path(targetdir, dirname), r)
    end

    def revision(user, time, path) 
      v = version(user, time, path)
      # NB: path = component name
      c = Component.new(path)
      return Revision.new(c, v)
    end

    
    def version(user, time, path)
      url = svn_url(path, user)      
      info = @shell.read("svn info --revision {#{svn_time(time)}} #{url}/trunk")
      info.split("\n").each do |line|
        if line =~ /Last Changed Rev: ([0-9]+)/ then
          return $1.to_i
        end
      end
      raise RuntimeError.new("subversion didn't behave as expected: #{info.split.inspect}")
    end
        
  end

  


  class Checkout
    attr_reader :path, :repository

    def initialize(repository,  path, revision)
      @repository = repository
      @path = path
      @revision = revision
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

    def extract_emails
      return bom_reader.emails
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

  class SVNCheckout < Checkout
    def initialize(repository,  path, revision = nil)
      super(repository, path, revision)
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
  
    #def version
    #  return @revision.version
    #end
  end
  
end
