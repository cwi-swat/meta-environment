

require 'optparse'
require 'ostruct'
require 'yaml'
require 'time'
require 'irb'

require 'scenarios'


module SisyphusDemo
  
  class DemoOptions
    def self.parse(args)
      options = OpenStruct.new
      options.config = nil
      options.sources = nil
      options.dbconf = nil
      
      opts = OptionParser.new do |opts|
        opts.banner = "Usage: sisyphus-demo-console [options]"
        opts.separator ""
        opts.separator "Options:"

        opts.on("-c Config", "--config Config",
                "Subversion URL pointing to Sisyphus config files") do |config|
          options.config = config
        end

        opts.on("-s Sources", "--sources Sources",
                "Subversion URL pointing to source repository") do |sources|
          options.sources = sources
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
        
        if options.config.nil? or 
            options.sources.nil? or
            options.dbconf.nil? then
          puts opts
          exit(1)
        end
        
        return options
      end
    end
  end

  def self.main(args)
    options = DemoOptions.parse(args)
    repo = options.sources
    s = Scenarios.new(repo)
    IRB.start
  end
 
end







if $0 == __FILE__ then
  SisyphusDemo::main(ARGV)
end
