
require 'optparse'
require 'ostruct'
require 'yaml'
require 'time'

class SisyphusClientCommandlineParser
  def self.parse(args)
    options = OpenStruct.new
    options.profile_name = nil
    options.config_url = nil
    options.interval = 3600
    options.roots = []
    options.verbose = false
    options.user = nil
    options.password = nil
    options.dbconf = nil
    options.quiet = false
    options.options_filename = nil
    options.addresses = []
    options.smtp_host = nil
    options.smtp_port = 25
    options.from = nil
    options.days = []
    options.before = nil
    options.after = nil
    options.command_line
   
    opts = OptionParser.new do |opts|
      opts.banner = "Usage: si-cli [options]"
      opts.separator ""
      opts.separator "Options:"

      opts.on("-p Profile", "--profile Profile",
              "Name of profile used to configure build the process") do |profile_name|
        options.profile_name = profile_name
      end
      
      opts.on("-c Config", "--config Config",
              "Subversion URL pointing to Sisyphus config files") do |config|
        options.config_url = config
      end
      
      opts.on("-r Root", "--root Root",
              "Add root package to start build with.") do |root|
        options.roots << root
      end

      opts.on("-o Options", "--options Options", "YAML file containing options.") do |o|
        options.options_filename = o
      end

      opts.on("-i Interval", "--interval Interval",
              "Interval (in s) waited after build session (3600)") do |interval|
        options.interval = interval.to_i
      end

      opts.on("-d Dbconf", "--dbconf Dbconf", "Database config file.") do |d|
        File.open(d) do |f|
          options.dbconf = YAML.load(f)
        end
      end

      opts.on("-U", "--User User", "Subversion user") do |u|
	options.user = u
      end

      opts.on("-P", "--Password Password", "Subversion password") do |p|
	options.password = p
      end
      
      opts.on("-q", "--[no-]quiet", "Log all output to file on /tmp") do |q|
	options.quiet = q
      end

      opts.on("-v", "--[no-]verbose", "Run verbosely") do |v|
	options.verbose = v
      end
      
      opts.on("-m", "--mail Address", "Add email address to send mail to.") do |m|
        options.addresses << m
      end

      opts.on("-f", "--from Address", "Sender email adress.") do |m|
        options.from = m
      end

      opts.on("-s", "--smtp Host", "SMTP host to use.") do |s|
        host, port = s.split(':')
        options.smtp_host = host
        if not port.nil? then
          options.smtp_port = port
        end
      end

      opts.on("-w", "--weekday DayOfWeek", "Day(s) of week to run on.") do |d|
        options.days << d
      end
      
      opts.on("-b", "--before Time", "Time (without date) before which to run.") do |b|
        options.before = b
      end

      opts.on("-a", "--after Time", "Time (without date) after which to run.") do |a|
        options.after = a
      end 

      opts.on("-C", "--COMMAND_LINE commandline", "(Internal)") do |command_line|
        options.command_line = command_line
      end

      begin
        opts.parse!(args)
      rescue OptionParser::InvalidOption => e
        puts opts
        exit(1)
      end
      
      if not options.options_filename.nil? then
        File.open(options.options_filename) do |f|
          config = YAML.load(f)
          options.profile_name = config['options']['profile']
          options.interval = config['options']['interval']
          options.roots = config['options']['roots']
          options.verbose = config['options']['verbose']
          options.quiet = config['options']['quiet']
          options.days = config['options']['days']
          options.before = config['options']['before']
          options.after = config['options']['after']
          options.config_url = config['subversion']['url']
          options.user = config['subversion']['username']
          options.password = config['subversion']['password']
          options.dbconf = config['database']
          options.addresses = config['email']['to']
          options.from = config['email']['from']
          options.smtp_host = config['email']['host']
          options.smtp_port = config['email']['port']
        end
      end

      if options.profile_name.nil? or 
          options.config_url.nil? or 
          options.roots == [] or
          options.dbconf.nil? then
        puts opts
        exit(1)
      end
      
      if options.addresses == [] && 
          (options.smtp_host.nil? || 
           options.from.nil?) then
        puts opts
        exit(1)
      end
      
      return options
    end
  end
end
