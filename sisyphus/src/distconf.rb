module Distribution

  require 'udir'

  NUM_OF_SLASHES = 256

  class DistributionConfiguration
    include Utils::UnameDir

    attr_reader :platform_root, :platform_candidates, :platform_latest


    def initialize(repository_url)
      @repository_url = repository_url
      @platform_root = File.join(@repository_url, uname_dir)
      @platform_latest = File.join(@platform_root, 'latest')
      @platform_candidates = File.join(@platform_root, 'candidates')
      ensure_svn_url(@platform_root)
      ensure_svn_url(@platform_latest)
      ensure_svn_url(@platform_candidates)
    end

    def enlarge_path(path, num = NUM_OF_SLASHES)
      return ('/' * num) + path
    end

    def ensure_svn_url(url)
      if `svn info #{url}`.rstrip =~ /\(Not a valid URL\)/ then
        dirname = File.dirname(url)
        if dirname != url then
          ensure_svn_url(dirname)
        end
        # @log.info("svn mkdir #{url} -m \"Creating url: #{url}\"")
        `svn mkdir #{url} -m "Creating url: #{url}"`
      end   
    end


    def svn_list(url)
      return `svn list #{url}`.split.collect {|x| x.chop}
    end

    def available_packages
      svn_list(@platform_candidates)
    end
    
    def available_revisions(pkg)
      svn_list(File.join(@platform_candidates, pkg))
    end

    def available_candidates(pkg, revision)
      svn_list(File.join(File.join(@platform_candidates, pkg), revision))
    end

    def package_candidates(pkg)
      table = {}
      available_revisions(pkg).each do |rev|
        table[rev.to_i] = available_candidates(pkg, rev).collect do |build|
          build.to_i
        end
      end
      return table
    end
    
    def url_for(p, r, c)
      url = File.join(File.join(File.join(@platform_candidates, p), r.to_s), c.to_s)
      return url
    end
    

    def checkout_latest(latest_checkout)
      if not File.exist?(latest_checkout) then
        `svn co #{platform_latest} #{latest_checkout}`
      else
        `svn update #{latest_checkout}`
      end
    end


    def bill_of_materials(item, latest_checkout)
      # Contstruct the prototypical bom
      bom = {}
      begin
        bom = read_bom(item.name, latest_checkout)
      rescue
        bom['files'] = []
        bom['dirs'] = []
      end
      bom['identification'] = {}
      bom['identification']['name'] = item.name
      bom['identification']['revision'] = item.version
      bom['identification']['build'] = item.id
      bom['identification']['session'] = item.si_session.time
      bom['identification']['prefix'] = prefix
      bom['identification']['host'] = item.si_host.uname
      bom['checksums'] = {}
      return bom
    end

    def save_bill_of_materials(item, latest_checkout)
      bomfile = bom_path(item, latest_checkout)
      File.open(bomfile, 'w') do |f|
        YAML.dump(bom, f)
      end
    end

    def bom_files_and_dirs(item, latest_checkout)
      todo = [name]
      files = []
      dirs = []
      while todo != [] do
        name = todo.pop
        files << bom_file_name(name)
        File.open(bom_path(item, latest_checkout)) do |f|
          bom = YAML.load(f)
          files |= bom['files']
          dirs |= bom['dirs']
          todo |= bom['deps']
        end
      end
      return files, dirs
    end

    def read_bom(pkg, prefix)
      filename = File.join(prefix, pkg)
      if not File.exists?(filename)
        filename += '.bom'
        if not File.exists?(filename) then
          raise "No bom found for #{pkg} in #{prefix}."
        end
      end
      bom = nil
      File.open(filename) do |f|
        bom = YAML.load(f)
      end
      return bom
    end
    
    def read_boms_below(pkg, prefix)
      boms = {}
      todo = [pkg]
      done = []
      while todo != [] do
        pkg = todo.pop
        bom = read_bom(pkg, prefix)
        boms[pkg] = bom
        done << pkg     

        bom['deps'].each do |dep|
          if not done.include?(dep) then
            todo |= [dep]
          end
        end
      end
      return boms
    end

    def prefixes(pkg, boms)
      prefixes = []
      todo = [pkg]
      while todo != [] do
        pkg = todo.pop
        prefixes << boms[pkg]['identification']['prefix']
        todo |= boms[pkg]['deps']
      end
      return prefixes.uniq
    end


    def bom_path(item, latest_checkout)
      File.join(latest_checkout, bom_file_name(item.name))
    end

    def bom_file_name(name)
      return "#{name}.bom"
    end


  end


end
