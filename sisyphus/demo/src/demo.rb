

require 'optparse'
require 'ostruct'
require 'yaml'
require 'time'
require 'tk'



require 'scenarios'


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

class SisyphusDemo
  attr_reader :scenarios, :transactions

  def initialize(args)
    @options = DemoOptions.parse(args)
    @scenarios = Scenarios.new(@options.sources)
    @server_pid = nil
    @client_pid = nil
    @transactions = []
    at_exit { shutdown }
  end

  def shutdown
    stop_web_server
    stop_client
    #puts "Rolling back changes."
    #@transactions.reverse.each do |trans|
    #  trans.rollback
    #end
  end

  def run
    this = self

    root = TkRoot.new() { title "Sisyphus Demo" }
    label1 = TkLabel.new(root) {
      text "Controls"
    }

    button0 = TkButton.new(root) {
      text "(Re)start Webserver"
      command proc { this.start_or_restart_web_server }
    }

    button00 = TkButton.new(root) {
      text "(Re)start client"
      command proc { this.start_or_restart_client }
    }

    button01 = TkButton.new(root) {
      text "Stop Webserver"
      command proc { this.stop_web_server }
    }

    button02 = TkButton.new(root) {
      text "Stop client"
      command proc { this.stop_client }
    }

    label2 = TkLabel.new(root) {
      text "Scenarios"
    }
    button1 = TkButton.new(root) {
      text "Cleanslate+"
      command proc { 
        t = this.scenarios.clean_slate_scenario(true)
        this.transactions << t
        t.commit  
      }
    }
    button2 = TkButton.new(root) {
      text "Cleanslate"
      command proc { 
        t = this.scenarios.clean_slate_scenario
        this.transactions << t
        t.commit  
      }
    }
    button3 = TkButton.new(root) {
      text "Build Sharing"
      command proc { 
        t = this.scenarios.build_reuse_scenario
        this.transactions << t
        t.commit  
      }
    }
    button4 = TkButton.new(root) {
      text "Change Propagation"
      command proc { 
        t = this.scenarios.change_propagation_scenario
        this.transactions << t
        t.commit  
      }
    }
    button5 = TkButton.new(root) {
      text "Backtracking"
      command proc { 
        t = this.scenarios.backtracking_scenario
        this.transactions << t
        t.commit  
      }
    }

    button6 = TkButton.new(root) {
      text "<Undo break>"
      command proc { 
        t = this.scenarios.backtracking_scenario
        t.rollback
      }
    }

    label1.pack
    button0.pack
    button00.pack
    button01.pack
    button02.pack
    label2.pack
    button1.pack
    button2.pack
    button3.pack
    button4.pack
    button5.pack
    button6.pack
    Tk.mainloop
  end
 
  def start_or_restart_web_server
    puts "(Re)starting webserver..."
    if @server_pid.nil? then
      start_web_server
    else
      restart_web_server
    end
  end

  def start_or_restart_client
    puts "(Re)starting client..."
    if @client_pid.nil? then
      start_client
    else
      restart_client
    end
  end

  def stop_web_server
    if @server_pid then
      Process.kill('TERM', @server_pid)
      @server_pid = nil
    end
  end

  def stop_client
    if @client_pid then
      Process.kill('KILL', @client_pid)
      @client_pid = nil
    end    
  end

  def start_web_server
    pid = fork()
    if pid then
      # parent
      @server_pid = pid
      Process.detach(pid)
    else
      # child
      dir = File.dirname(File.expand_path(__FILE__))
      if dir =~ /^(.*)\/share\/sisyphus\/demo/ then
        prog = File.join(File.join($1, 'bin'), 'sisyphus-demo-web')
        exec(prog)
      else
        raise "Could not find demo webserver in prefix of #{dir}."
      end
    end
  end

  def restart_client
    if @client_pid then
      Process.kill('USR1', @client_pid)
    end
  end

  def start_client
    pid = fork()
    if pid then
      # parent
      @client_pid = pid
      Process.detach(pid)
    else
      # child
      dir = File.dirname(File.expand_path(__FILE__))
      if dir =~ /^(.*)\/share\/sisyphus\/demo/ then
        prog = File.join(File.join($1, 'bin'), 'sisyphus-demo-client')
        exec(prog)
      else
        raise "Could not find demo client in prefix of #{dir}."
      end
    end
  end
  
end







if $0 == __FILE__ then
  demo = SisyphusDemo.new(ARGV)
  demo.run
end
