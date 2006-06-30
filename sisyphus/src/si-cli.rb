module Sisyphus

  require 'vcs'
  require 'db'
  require 'dblog'

  require 'revision'
  require 'target'
  require 'config'
  require 'visitor'
  require 'session'
  require 'builder'
  require 'ilogger'
  require 'options'
  require 'mailer'

  require 'tmpdir'
  require 'time'

  class SisyphusClient 
    def initialize(host, config_manager, profile_name, interval, roots, store, verbose, quiet, days, after, before, mailer, command_line)
      @host = host
      @config_manager = config_manager
      @profile_name = profile_name
      @interval = interval
      @roots = roots
      @store = store
      @repo_factory = Versioning::RepositoryFactory.new
      @verbose = verbose
      @quiet = quiet
      @days = days
      @after = after
      @before = before
      @mailer = mailer
      @log_device = STDERR
      @command_line = command_line
      @last_updated = latest_module_time
    end

    def latest_module_time
      times = []
      Dir[File.join(File.dirname(__FILE__), '*.rb')].each do |file|
        times << File.ctime(file)
      end
      return times.sort.last
    end

    def check_if_updated
      time = latest_module_time
      if @last_updated < time then
        puts "Received update: restarting..."
        exec(@command_line)
      end
    end

    def run
      loop do
        check_if_updated
        do_iteration
        wait_interval
      end
    end

    def ensure_log(time)
      if @quiet then
        hostname = `hostname`.chomp
        timestr = time.strftime("%Y%m%dT%H%M")
        @log_device = File.join(Dir.tmpdir, "sisyphus_log_on_#{hostname}_#{timestr}")
        $stderr << "Logging to #{@log_device}\n"
      end

      @log = Utils::IndentedLogger.new(@log_device)
      @log.level = Logger::WARN

      if @verbose then
        @log.level = Logger::INFO
      end
      @log.info("Log initialized: #{time}\n")

      @store.set_log(@log)
      @config_manager.set_log(@log)
    end

    def start_iteration(time)
      ensure_log(time)
      @store.connect
    end

    def record_failure(e)
      line = e.inspect
      add_log_line(line)
      @log.error(line)
    end

    def finalize_iteration
      @config_manager.cleanup_checkout
      if not @log.nil? then
        @log.info("sleeping #{@interval} seconds")
        if @log_device != STDERR then
          @log.close
        end
      end
      @store.disconnect
    end

    def do_iteration
      time = Time.now
      if eligible_time?(time) then
        begin 
          start_iteration(time)
          session = Building::Session.new(time, @host)
          @log.info("starting iteration at #{time}")
          do_the_build(session, time)
          mail_session(session)
        rescue Exception => e
          e.backtrace.each do |line|
            if @log then 
              @log.error(line)
            end
          end
          record_failure(e)
        ensure
          finalize_iteration
        end
      end
    end

    def mail_session(session)
      if session.contains_failures? then
        @mailer.mail(session)
      end
    end

    def eligible_time?(time)
      if time > Time.parse(@after) and time < Time.parse(@before) then
        s = time.to_s
        @days.each do |day|
          if s.match(/#{day}/i) then
            return true
          end
        end
      end
      return false
    end    

    def add_log_line(string)
      dbhost = @store.db_host(@host)
      log = Model::SiLog.new(:line => string, :si_host => dbhost)
      log.save
    end

    def do_the_build(session, time)
      config = @config_manager.configuration(@profile_name, time)
      revision_factory = Versioning::RevisionFactory.new(config.sources.properties['repositories'], 
                                                         config.sources.properties['externals'],
                                                         @repo_factory, config.user, config.build_dir, time)  
      target_factory = Building::TargetFactory.new(session, config, @log)
      @builder = Building::Builder.new(@store, @log)
      visitor = Building::Visitor.new(target_factory, revision_factory, @roots, @builder, @log)
      visitor.build_roots
    end

    def wait_interval
      sleep(@interval)
    end

    
  end

end



if __FILE__ == $0 then
  options = Sisyphus::SisyphusClientCommandlineParser.parse(ARGV)
  uname = `uname -n`.chomp

  svn_host = ''
  svn_url = ''
  if options.config_url =~ /^svn:\/\/([^\/]*)\/(.*)$/ then
    svn_host = $1
    svn_url = $2
  end

  config_manager = Building::ConfigurationManager.new(svn_host, 
                                                      svn_url,
                                                      options.user, 
                                                      options.password)

  store = Model::DBStore.new(options.dbconf)

  mailer = Utils::SessionMailer.new(options.addresses, 
                                    options.from,
                                    options.smtp_host, 
                                    options.smtp_port)

  client = Sisyphus::SisyphusClient.new(uname, 
                                        config_manager, 
                                        options.profile_name, 
                                        options.interval, 
                                        options.roots, 
                                        store, 
                                        options.verbose, 
                                        options.quiet, 
                                        options.days,
                                        options.after,
                                        options.before,
                                        mailer, 
                                        options.command_line)
  client.run
end


