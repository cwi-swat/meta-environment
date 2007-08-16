require 'tsort'

class Hash
  include TSort
  alias tsort_each_node each_key
  def tsort_each_child(node, &block)
    fetch(node).each(&block)
  end
end



module Roll

  require 'optparse'
  require 'ostruct'
  require 'yaml'
  require 'erb'

  require 'utils/rcfiles'
  require 'boot-roll'


  class CommandlineParser
    def self.read_roll_conf(tag)
      if not File.exists?(Utils::Roll::roll_rcfile(tag)) then
        $stderr << "File #{Utils::Roll::roll_rcfile(tag)} does not exist. Run boot-roll first.\n"
        exit(1)
      end
      conf = nil
      File.open(Utils::Roll::roll_rcfile(tag)) do |f|
        conf = YAML.load(f)
      end
      return conf
    end
    

    def self.update_roll_conf(conf, tag)
      $stderr << "File #{Utils::Roll::boot_roll_rcfile(tag)} is newer than #{Utils::Roll::roll_rcfile(tag)}; run boot-roll? [Yn] "
      answer = $stdin.gets.chomp
      if answer != 'n' then
        options = OpenStruct.new
        options.tag = tag
        BootRoll.boot_roll(options)
        # reread rollrc
        conf = read_roll_conf(tag)
      end
      return conf
    end



    def self.usage(opts, retval)
      puts opts
      exit(retval)
    end

    def self.inferred_package(tag)
      wd = Dir.getwd
      map = the_conf(tag)['locations']
      package = nil
      map.each do |pkg, path|
        pattern = Regexp.quote(path)
        if wd.match(/^#{pattern}\//) or
            wd.match(/^#{pattern}$/) then
          package = pkg
        end
      end
      if not package then
        $stderr << "Current directory #{wd} not managed by roll.\n"
        exit(1)
      end
      return package
    end

    def self.checked_package(conf, package)
      if conf['locations'].include?(package)
        return package
      else
        $stderr << "Unknown package #{package}; see #{Utils::Roll::roll_rcfile}.\n"
        exit(1)
      end
    end

    def self.the_conf(tag)
      if not @conf then
        @conf = read_roll_conf(tag)
      end
      if File.exists?(Utils::Roll::boot_roll_rcfile(tag)) and
          File.ctime(Utils::Roll::boot_roll_rcfile(tag)) > File.ctime(Utils::Roll::roll_rcfile(tag)) then
        @conf = update_roll_conf(@conf, tag)
      end
      return @conf
    end
    
    
    def self.parse(args)
      options = OpenStruct.new
      options.below = nil
      options.exclusive_below = false
      options.exclusive_above = false
      options.above = nil  
      options.tag = nil
      options.package = nil
      options.revert = false
      options.force = false
      options.pretend = false
      options.sequence = false
      options.deps_only = false
      options.export = nil

      opts = OptionParser.new do |opts|

        opts.banner = """Usage: roll [options] command

    Command can be an arbitrary shell command or the name
    of one of the pre-configured templates (see below).
"""
        opts.separator ""    
        opts.separator "Options:"

        opts.on("-t Tag", "--tag Tag",
                "Use .rollrc.<tag> instead of .rollrc") do |tag|
          options.tag = tag
        end

        opts.on("-p Package", "--package Package",
                "Execute only for package") do |package|
          options.package = checked_package(the_conf(options.tag), package)
        end

        opts.on("-c", "--current", "Derive package from working dir") do 
          options.package = inferred_package(options.tag)
        end

        opts.on("-a Package", "--above Package",
                "Execute actions above Package") do |above|
          options.above = checked_package(the_conf(options.tag), above)
        end
        
        opts.on("-b Package", "--below Package",
                "Execute actions below Package") do |below|
          options.below = checked_package(the_conf(options.tag), below)
        end
        
        opts.on("-x", "--exclusive-below",
                "Interpret --below exclusively") do |x|
          options.exclusive_below = x
        end

        opts.on("-y", "--exclusive-above",
                "Interpret --above exclusively") do |y|
          options.exclusive_above = y
        end

        opts.on("-r", "--revert", 
                "Reverse topological ordering") do |revert|
          options.revert = true
        end

        opts.on("-f", "--force", "Continue after action errors") do 
          options.force = true
        end

        opts.on("-s", "--sequence",
                "Sequence commandline args.") do |seq|
          options.sequence = true
        end

        opts.on("-D", "--[no-]deps-only",
                "Build only deps (transitively reachable; with -p)") do |d|
          options.deps_only = d
        end

        opts.on("-P", "--pretend", 
                "Print commands instead of execute") do |p|
          options.pretend = true
        end

        opts.on("-e Dir", "--export Dir", "Export source to given directory") do |d|
          options.export = d
        end


        opts.on("-d", "--deps", "Print out dependencies") do 
          deps = the_conf(options.tag)['dependencies']
          deps.keys.sort.each do |client|
            puts sprintf("%-24s: [%s]", client, deps[client].sort.join(', '))
          end
          exit(0)
        end

        opts.on("-l", "--list", "List available command templates") do 
          templates = the_conf(options.tag)['config']['templates']
          names = []
          if not templates.nil? then
            puts "Pre-configured templates:"
            names = templates.keys.sort
          end
          names.each do |name|
            puts sprintf("  %-16s: %s", name, templates[name])
          end
          exit(0)
        end

        opts.on("-h", "--help",  "Display usage") do |x|
          usage(opts, 0)
        end

      end
      
      if args == [] then
        usage(opts, 1)
      end  

      if options.deps_only and !options.package then
        usage(opts, 1)
      end
      
      opts.parse!(args)

      return options, the_conf(options.tag)
    end
  end

  def Roll.instantiate(component, template, graph, locations, install_dir, options)
    deps = []
    graph[component].each do |d|
      if locations.has_key?(d) then
        # e.g. graphviz has no location
        o = OpenStruct.new
        o.name = d
        if options.pretend then
          o.prefix = '${INSTALL_DIR}'
        else
          o.prefix = File.join(install_dir, d)          
        end
        deps << o
      end
    end
    deps.compact! 
    name = component
    if options.pretend then
      prefix = '${INSTALL_DIR}'
    else
      prefix = File.join(install_dir, component)          
    end
    t = ERB.new(template)
    result = t.result(binding())
    if options.pretend then
      result = "cd ${BUILD_DIR}/#{component}; #{result}; cd -"
    end
    return result
  end

  def Roll.run_command(command, options)
    if options.pretend then
      Roll.print_command(command, options)
    else
      Roll.execute_command(command, options)
    end
  end

  def Roll.print_command(command, options)
    puts command
  end

  def Roll.execute_command(command, options)
    $stderr << "Executing #{command} in #{Dir.getwd}\n"
    begin
      system(command)
    rescue Exception => e
      puts "exception"
    else
      if not options.force then
        if $?.exitstatus != 0 then
          exit($?.exitstatus)
        end
      end
    end
  end

  def Roll.make_command(action, component, templates, deps, locations, install_dir, options)
    if templates.has_key?(action) then
      return instantiate(component, templates[action], 
                         deps, locations, install_dir, options)
    else
      return action
    end
  end

  def Roll.transitive_closure(package, deps)
    todo = [package]
    result = [package]
    while todo != [] do
      cur = todo.pop
      result |= deps[cur]
      todo |= deps[cur]
    end
    return result
  end

  def Roll.run_commands(actions, locations, deps, templates, install_dir, options)
    pwd = Dir.getwd
    order = deps.tsort
    if options.revert then
      order.reverse!
    end

    if options.package then
      if options.deps_only then
        todo_set = transitive_closure(options.package, deps)
        todo = []
        order.each do |p|
          if todo_set.include?(p) then
            todo << p
          end
        end
      else
        todo = [options.package]
      end
    else
      above = 0
      below = order.length-1
      if options.above then
        above = order.index(options.above)
        if options.exclusive_above then
          above += 1
        end
      end
      if options.below then
        below = order.index(options.below)
        if options.exclusive_below then
          below -= 1
        end
      end
      todo = order[above..below]
    end

    todo.each do |component|
      dir = locations[component]
      if not File.exists?(dir) then
        $stderr << "Directory #{dir} does not exist; maybe rerun boot-roll?.\n"
        exit(1)
      end
      Dir.chdir(dir)
      if not options.sequence then 
        actions = [actions.join(' ')]
      end
      actions.each do |action|
        command = make_command(action, component, templates, deps, locations, install_dir, options)
        run_command(command, options)
      end
      Dir.chdir(pwd)
    end
  end


  def Roll.roll(conf, options, actions)
    deps = conf['dependencies']
    locations = conf['locations']
    install_dir = conf['config']['install_dir']
    build_dir = conf['config']['build_dir']
    if options.pretend then
      puts "INSTALL_DIR=#{install_dir}"
      puts "BUILD_DIR=#{build_dir}"
      install_dir = '${INSTALL_DIR}'
    end
    templates = conf['config']['templates']
    run_commands(actions, locations, deps, templates, install_dir, options)
  end

end

if $0 == __FILE__ then
  options, conf = Roll::CommandlineParser.parse(ARGV)
  if ARGV == [] then
    $stderr << "Usage: roll <command>\n"
    exit(1)
  end
  Roll::roll(conf, options, ARGV)
end

