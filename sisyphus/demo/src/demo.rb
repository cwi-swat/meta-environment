

require 'optparse'
require 'ostruct'
require 'yaml'
require 'time'

module SisyphusDemo

  class DemoOptions
    def self.parse(args)
      options = OpenStruct.new
      options.config_url = nil
      options.dbconf = nil
      
      opts = OptionParser.new do |opts|
        opts.banner = "Usage: #{sisyphus-demo} [options]"
        opts.separator ""
        opts.separator "Options:"

        opts.on("-c Config", "--config Config",
                "Subversion URL pointing to Sisyphus config files") do |config|
          options.config_url = config
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
        
        if options.config_url.nil? or 
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
    p options
  end

end





if $0 == __FILE__ then
  SisyphusDemo::main(ARGV)
end
