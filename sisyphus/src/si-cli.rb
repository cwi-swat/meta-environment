module Sisyphus

  require 'model/db'
  require 'model/dblog'

  require 'versioning/vcs'
  require 'versioning/revision'
  require 'building/target'
  require 'building/config'
  require 'building/visitor'
  require 'building/session'
  require 'building/builder'
  require 'utils/ilogger'
  require 'utils/options'
  require 'utils/mailer'

  require 'tmpdir'
  require 'time'

  class SisyphusClient 
    def initialize(host, config_manager, profile_name, interval, roots, store, verbose, quiet, days, after, before, mailer, forced, command_line)
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
      @forced = forced
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
      ignore_signal("USR1")
      loop do
        check_if_updated
        do_iteration
        trapping_signal("USR1") do 
          wait_interval
        end
      end
    end

    def trapping_signal(signal)
      Signal.trap(signal) do
        run
      end
      begin
        yield
      ensure
        ignore_signal(signal)
      end
    end

    def ignore_signal(signal)
      Signal.trap(signal, "IGNORE")        
    end

    def db_host
      @store.db_host(@host)  
    end

    def deprecated_ensure_log(time)
      if @quiet then
        hostname = `hostname`.chomp
        timestr = time.strftime("%Y%m%dT%H%M")
        @log_device = File.join(Dir.tmpdir, "sisyphus_log_on_#{hostname}_#{timestr}")
        $stderr << "Logging to #{@log_device}\n"
      end

      @log = Utils::IndentedDBLogger.new(db_host, @log_device)
      @log.level = Logger::WARN

      if @verbose then
        @log.level = Logger::INFO
      end
      @log.info("Log initialized: #{time}\n")

      @store.set_log(@log)
      @config_manager.set_log(@log)
    end

    def start_iteration(time)
      if @quiet then
        #  hostname = `hostname`.chomp
        #  timestr = time.strftime("%Y%m%dT%H%M")
        #  @log_device = File.join(Dir.tmpdir, "sisyphus_log_on_#{hostname}_#{timestr}")
        #  $stderr << "Logging to #{@log_device}\n"
        @log_device = File.open('/dev/null', 'w')
      end

      @store.connect

      db_session = Model::SiSession.new(:time => time)
      session = Building::Session.new(time, @host, db_session)

      @log = Utils::IndentedDBLogger.new(db_host, session.db_session, @log_device)
      @log.level = Logger::WARN


      if @verbose then
        @log.level = Logger::INFO
      end
      @log.info("Log initialized: #{time}\n")

      @store.set_log(@log)
      @config_manager.set_log(@log)
      return session
    end

    def record_failure(e)
      line = e.inspect
      add_log_line(line + "\n" + e.backtrace.join("\n"))
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
          session = start_iteration(time)
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
      @mailer.mail(session)
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
      @builder = Building::Builder.new(@store, @forced, config, @log)
      visitor = Building::Visitor.new(target_factory, revision_factory, @roots, @builder, @log, config, @store)
      visitor.build_roots
    end

    def wait_interval
      sleep(@interval)
    end

    
  end

end



if __FILE__ == $0 then
  options = Utils::Sisyphus::SisyphusClientCommandlineParser.parse(ARGV)
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

  mailer = Utils::DummySessionMailer.new
  if options.email then
    mailer = Utils::SessionMailer.new(options.from,
                                      options.smtp_host, 
                                      options.smtp_port)
  end

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
                                        options.forced,
                                        options.command_line)
  client.run
end


