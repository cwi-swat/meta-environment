module Building

  require 'yaml'
  require 'fileutils'
  require 'logger'

  require 'utils/empty-shell'

  class ConfigurationManager
    include FileUtils

    def initialize(svn_host, svn_url, svn_user, svn_password, 
                   svn_port = 3960, tunnel_host = nil, 
                   tunnel_port = svn_port, 
                   tunnel_user = ENV['USER'])
      @svn_host = svn_host
      @svn_url = svn_url
      @svn_user = svn_user
      @svn_password = svn_password
      @svn_port = svn_port
      @tunnel_user = tunnel_user
      @tunnel_host = tunnel_host
      @tunnel_port = tunnel_port
      @path = checkout_path
      @shell = Utils::CommandSpecificShell.new('subversion')
    end

    def log
      if @log.nil? then
        # Private log
        @log = Logger.new(STDERR)
        @log.level = Logger::INFO
      end
      return @log
    end
    
    def set_log(log)
      @log = log
    end

    def checkout_path
      name = `hostname `.chomp   
      pid = Process.pid
      return File.join(Dir.getwd, ".sisyphus_at_#{name}_with_pid_#{pid}")
    end

    def cleanup_checkout
      rm_rf(checkout_path)
    end

    def synchronize_checkout(time)
      time = svn_time(time)
      remove_existing_checkout
      create_new_checkout(time)
    end

    def create_new_checkout(time)
      if @svn_user == nil and @svn_password == nil then
        svn_command("co #{svn_url} -r {#{time}} #{@path}")
      elsif @svn_user != nil and @svn_password != nil then
        svn_command("co #{svn_url} --non-interactive --username #{@svn_user} --password #{@svn_password} -r {#{time}} #{@path}")
      else
        raise RuntimeError.new("User or password given without the other.")
      end
    end

    def remove_existing_checkout
      if test(?d, @path) then
        log.warn("Warning: #{@path} exists and is removed!")
        rm_r @path
      end
    end
    
    def svn_time(time)
      return time.strftime("%Y%m%dT%H%M")
    end
    
    def svn_url
      url = "svn://"
      if tunnel_needed? then
        url += 'localhost'
      else
        url +=  @svn_host
      end
      return "#{url}/#{@svn_url}"
    end

    def tunnel_needed?
      return !@tunnel_host.nil?
    end

    def tunneled
      if tunnel_needed? then
        ssh_pid = fork do 
          exec('ssh', '-l', @tunnel_user, @tunnel_host, 
               '-L',  "3690:#{@svn_host}:3690", '-N')
        end
        sleep(3)
        yield
        Process.kill('SIGTERM', ssh_pid)
      else
        yield
      end
    end

    def svn_command(options)
      tunneled do 
        command = "svn #{options}"
        log.info("executing: #{command}")
        @shell.execute(command)
      end
    end
    
    def version_of(path)
      # assert synchronized here???
      info = @shell.read("svn info #{path}")
      info.split("\n").each do |line|
        if line =~ /Last Changed Rev: ([0-9]+)/ then
          return $1.to_i
        end
      end
      raise RuntimeError.new("subversion didn't behave as expected: #{info.split.inspect}")
    end

    def rel_to_checkout(path)
      return File.join(@path, path)
    end

    def source_configuration(time)
      synchronize_checkout(time)
      config_dir = rel_to_checkout('config')
      sources = config_item(config_dir, 'sources')   
      return sources
    end

    def configuration(profile_name, time)
      synchronize_checkout(time)
      config_dir = rel_to_checkout('config')
      sources = config_item(config_dir, 'sources')
      profile = config_item(rel_to_checkout('profiles'), profile_name)
      script = nil
      if profile.properties.has_key?('script') then
        script = ConfigurationItem.new('script', 0, profile.properties['script'])
      else
        script = config_item(config_dir, 'script')
      end
      validate_script(script)
      return Configuration.new(profile, sources, script)
    end

    def validate_script(script)
      missing_entries = []
      script.properties['order'].each do |action|
        if not script.properties['templates'].has_key?(action) then
          missing_entries << action
        end
      end
      if missing_entries != [] then
        raise RuntimeError.new("missing templates for actions: #{missing_entries.inspect}")
      end
      templates_but_no_order = script.properties['templates'].keys - script.properties['order']
      if templates_but_no_order != [] then
        raise RuntimeError.new("templates defined but no actions in order: #{templates_but_no_order}")
      end
    end

    def config_item(dir, name)
      path = File.join(dir, "#{name}.yml")
      props = nil
      File.open(path) do |f|
        props = YAML.load(f)
      end
      version = version_of(path)
      return ConfigurationItem.new(name, version, props)
    end

  end


  class Configuration
    attr_reader :profile, :sources, :script
    
    def initialize(profile, sources, script)
      @profile = profile
      @sources = sources
      @script = script
    end

    def profile_value(name)
      if not @profile.properties.has_key?(name) then
        raise RuntimeError.new("no #{name} configured in profile: #{@profile}")
      end
      return @profile.properties[name]
    end

    def actions
      return script.properties['order']
    end

    def action_template(action)
      return script.properties['templates'][action]
    end

    def eql?(configuration)
      return @profile.eql?(configuration.profile) &&
        @sources.eql?(configuration.sources) &&
        @script.eql?(configuration.script)
    end

    def ==(configuration) 
      return (configuration.profile == @profile) &&
        (configuration.sources == @sources) &&
        (configuration.script == @script)
    end

    def hash
      s = "#{@profile.hash}#{@sources.hash}#{@script.hash}"
      return s.hash
    end

    def to_s
      return "<#{@profile}, #{@sources}, #{@script}>"
    end

    def environment
      return profile_value('environment')
    end

    def distributes?
      return profile_value('distributes')
    end

    def binary_dist_dir
      return profile_value('binary_dist_dir')
    end

    def collect_url   
      return profile_value('collect_url')
    end

    def source_dist_dir
      return profile_value('source_dist_dir')
    end

    def build_dir
      return profile_value('build_dir')
    end

    def install_dir
      return profile_value('install_dir')
    end

    def user
      return profile_value('user')
    end

  end

  class ConfigurationItem
    attr_reader :version, :properties, :name

    def initialize(name, version, properties)
      @name = name
      @version = version
      @properties = properties
    end

    def ==(conf_item)
      return (conf_item.name == @name) &&
        (conf_item.version == @version)
    end

    def eql?(conf_item)
      return @name.eql?(conf_item.name) &&
        @version.eql?(conf_item.version)
    end

    def hash
      s = "#{@name.hash}#{@version.hash}"
      return s.hash
    end

    def to_s
      return "<#{@name}, #{@version}>"
    end

  end

end
