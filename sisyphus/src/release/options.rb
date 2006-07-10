
module Release

  require 'tmpdir'
  require 'optparse'
  require 'ostruct'
  require 'yaml'
  require 'time'

  class CommandLineParser
    def self.parse(args)
      options = OpenStruct.new
      options.build = nil
      options.workdir = Dir.tmpdir
      options.bundle = false
      options.src_dists = nil
      options.host = nil
      options.collect_url = nil
      options.collect_path = nil
      options.dbconf = nil
      
      opts = OptionParser.new do |opts|
        opts.banner = "Usage: sisyphus-release [options]"
        opts.separator ""
        opts.separator "Options:"

        opts.on("-r build", "--release Build",
                "Build to be released") do |build|
          options.build = build.to_i
        end

        opts.on("-w Workdir", "--workdir Workdir",
                "Working directory to test distributions (default: #{options.workdir}.") do |workdir|
          options.workdir = workdir
        end

        opts.on("-b", "--[no-]bundle", "Make bundle release") do |bundle|
          options.bundle = bundle
        end

        opts.on("-h Host", "--host Host", "Host where dists are copied to.") do |host|
          options.host = host
        end
        
        opts.on("-s Path", "--source-dists Path",
                "(Sisyphus) path containing continuous dists") do |src_dists|
          options.src_dists = src_dists
        end

        opts.on("-u URL", "--url URL",
                "Public URL used by collect (in package definitions)") do |collect_url|
          options.collect_url = collect_url
        end

        opts.on("-p Path", "--path Path",
                "Path where bundles and packages are released (= -u)") do |path|
          options.collect_path = path
        end
        
        opts.on("-d Dbconf", "--dbconf Dbconf", "Database config file.") do |d|
          File.open(d) do |f|
            options.dbconf = YAML.load(f)
          end
        end

        begin
          opts.parse!(args)
        rescue OptionParser::InvalidOption => e
          puts opts
          exit(1)
        end

        if options.src_dists.nil? or 
            options.collect_url.nil? or 
            options.collect_path.nil? or 
            options.build.nil? or
            options.host.nil? or
            options.dbconf.nil? then
          puts opts
          exit(1)
        end
        
        return options
      end
      
    end
    
  end


end
