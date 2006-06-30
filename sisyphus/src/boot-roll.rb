module BootRoll

  require 'building/config'
  require 'versioning/vcs'
  require 'versioning/component'
  require 'verisioning/revision'

  require 'yaml'
  require 'ostruct'
  require 'optparse'

  require 'utils/rcfiles'

  $bootrc_example = """
boot_roll: 
  build_dir: ./bla
  install_dir: /tmp
  vcs_user: storm
sisyphus:
  url: sisyphus-configuration
  host: sjofar.sen.cwi.nl
  protocol: svn
  port: 3960
  user: daybuild
  password: daybuild
  tunnel:
    host: ssh.cwi.nl
    user: storm
templates:
  install: make install

Note: the tunnel section is optional.
"""

  class CommandlineParser
    def self.parse(args)
      options = OpenStruct.new
      options.sources = nil

      opts = OptionParser.new do |opts|

        opts.banner = """Usage: boot-roll [options] <roots>

      roots represents one or more top components.
"""
        opts.separator ""    
        opts.separator "Options:"


        opts.on("-s Sources", "--sources Sources",
                "Override sources configuration") do |sources|
          if File.exists?(sources) then
            File.open(sources) do |f|
              options.sources = YAML.load(f)
            end
          else
            $stderr << "error: file #{sources} does not exist.\n"
            exit(1)
          end
        end

        opts.on("-h", "--help",  "Display usage") do |x|
          puts opts
          exit(1)
        end

      end
      
      opts.parse!(args)
      return options
    end
  end




  def BootRoll.checkout_all(roots, revision_factory)
    todo = roots
    done = []
    graph = {}
    while todo != [] do
      component = todo.shift
      revision = revision_factory.trunk_revision(component)
      if not revision.virtual? then
        $stderr << "checked out #{component}\n"
        graph[revision] ||= []
        done << component
        
        deps = revision.deps
        if deps.nil? then
          $stderr << "Warning: deps == nil for #{revision}; assuming []\n"
          deps = []
        end

        graph[revision] = deps
        todo |= deps.reject do |dep|
          done.include?(dep)
        end
      end
    end
    return graph
  end

  def BootRoll.component_deps(locations, graph)
    deps = {}
    graph.each_key do |r|
      deps[r.name] = graph[r].collect do |component|
        if locations.has_key?(component.name)
          component.name
        else
          nil
        end
      end.compact
    end
    return deps
  end

  def BootRoll.component_locations(graph)
    locations = {}
    graph.each_key do |r|
      if not r.virtual? then
        locations[r.name] = File.expand_path(r.checkout_path)
      end
    end
    return locations
  end

  def BootRoll.make_roll_configuration(graph)
    conf = {}
    locations = component_locations(graph)
    conf['locations'] = locations
    conf['dependencies'] = component_deps(locations, graph)
    return conf
  end

  def BootRoll.ensure_dir(dir)
    if not File.exists?(dir) then
      $stderr << "Directory #{dir} does not exist; shall I create it? [Yn] "
      answer = $stdin.gets.chomp
      if answer != 'n' then
        `mkdir -p #{dir}`
      else
        exit(0)
      end
    end
  end

  def BootRoll.obtain_checkouts(conf, roots, options)
    s = conf['sisyphus']
    config_manager = nil
    if s.has_key?('tunnel') then
      config_manager = Building::ConfigurationManager.new(s['host'],
                                                          s['url'],
                                                          s['user'],
                                                          s['password'],
                                                          s['port'],
                                                          s['tunnel']['host'],
                                                          s['tunnel']['port'],
                                                          s['tunnel']['user'])
    else
      config_manager = Building::ConfigurationManager.new(s['host'],
                                                          s['url'],
                                                          s['user'],
                                                          s['password'],
                                                          s['port'])
    end
    log = Logger.new(STDERR)
    log.level = Logger::WARN
    config_manager.set_log(log)
    

    time = Time.now
    sources = nil
    if options.sources.nil? then
      sources = config_manager.source_configuration(time).properties
    else
      sources = options.sources
    end
    repositories = sources['repositories']
    externals = sources['externals']

    b = conf['boot_roll']
    build_dir = b['build_dir']
    revision_factory = Versioning::RevisionFactory.new(repositories, 
                                                       externals,
                                                       Versioning::RepositoryFactory.new,
                                                       b['vcs_user'],
                                                       build_dir,
                                                       time)
    ensure_dir(build_dir)
    root_components = roots.collect do |root|
      Versioning::Component.new(root)
    end
    graph = checkout_all(root_components, revision_factory)
    config_manager.cleanup_checkout
    return graph
  end





  def BootRoll.boot_roll(roots, options)
    if roots == [] then
      $stderr << "Usage: boot-roll <rootpackages>\n"
      exit(1)
    end

    if not File.exists?(Utils::Roll::boot_roll_rcfile) then
      $stderr << "File #{boot_roll_rcfile} does not exist.\n"
      $stderr << "Create it, like this:\n"
      $stderr << $bootrc_example
      exit(1)
    end
    boot_conf = nil
    File.open(Utils::Roll::boot_roll_rcfile) do |f|
      boot_conf = YAML.load(f)
    end

    if boot_conf['sisyphus']['protocol'] != 'svn' then
      $stderr << "Protocol not supported: #{protocol} (only svn)\n"
      exit(1)
    end


    rcfile = Utils::Roll::roll_rcfile()
    if File.exists?(rcfile) then
      $stderr << "File #{rcfile} exists; overwrite? [Yn] "
      answer = $stdin.gets.chomp
      if answer == 'n' then
        exit(1)
      end
    end

    graph = obtain_checkouts(boot_conf, roots, options)
    conf = make_roll_configuration(graph)
    conf['config'] = {}
    conf['config']['install_dir'] = boot_conf['boot_roll']['install_dir']
    conf['config']['build_dir'] = boot_conf['boot_roll']['build_dir']
    conf['config']['templates'] = boot_conf['templates']
    conf['config']['roots'] = roots
    File.open(rcfile, 'w') do |f|
      YAML.dump(conf, f)
    end    

  end

end

if $0 == __FILE__ then
  options = BootRoll::CommandlineParser.parse(ARGV)
  roots = ARGV
  BootRoll::boot_roll(roots, options)
end
