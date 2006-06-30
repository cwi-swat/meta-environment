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

  require 'rcfiles'
  require 'boot-roll'


  class CommandlineParser
    def self.read_roll_conf
      if not File.exists?(Roll::roll_rcfile) then
        $stderr << "File #{Roll::roll_rcfile} does not exist. Run boot-roll first.\n"
        exit(1)
      end
      conf = nil
      File.open(Roll::roll_rcfile) do |f|
        conf = YAML.load(f)
      end
      return conf
    end
    

    def self.update_roll_conf(conf)
      $stderr << "File #{Roll::boot_roll_rcfile} is newer than #{Roll::roll_rcfile}; run boot-roll? [Yn] "
      answer = $stdin.gets.chomp
      if answer != 'n' then
        boot_roll(conf['config']['roots'])
        # reread rollrc
        conf = read_roll_conf
      end
      return conf
    end



    def self.usage(opts, retval)
      puts opts
      exit(retval)
    end

    def self.inferred_package
      wd = Dir.getwd
      map = the_conf['locations']
      package = nil
      map.each do |pkg, path|
        pattern = Regexp.quote(path)
        # Todo: fix longest match problem
        # if wd.match(/^#{pattern}\//) then
        if wd.match(/^#{pattern}/) then
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
        $stderr << "Unknown package #{package}; see #{Roll::roll_rcfile}.\n"
        exit(1)
      end
    end

    def self.the_conf
      if not @conf then
        @conf = read_roll_conf
      end
      if File.exists?(Roll::boot_roll_rcfile) and
          File.ctime(Roll::boot_roll_rcfile) > File.ctime(Roll::roll_rcfile) then
        @conf = update_roll_conf(@conf)
      end
      return @conf
    end
    
    
    def self.parse(args)
      options = OpenStruct.new
      options.below = nil
      options.exclusive_below = false
      options.exclusive_above = false
      options.above = nil  
      options.package = nil
      options.revert = false
      options.force = false
      options.sequence = false


      opts = OptionParser.new do |opts|

        opts.banner = """Usage: roll [options] command

    Command can be an arbitrary shell command or the name
    of one of the pre-configured templates (see below).
"""
        opts.separator ""    
        opts.separator "Options:"


        opts.on("-p Package", "--package Package",
                "Execute only for package") do |package|
          options.package = checked_package(the_conf, package)
        end

        opts.on("-c", "--current", "Derive package from working dir") do 
          options.package = inferred_package
        end

        opts.on("-a Package", "--above Package",
                "Execute actions above Package") do |above|
          options.above = checked_package(the_conf, above)
        end
        
        opts.on("-b Package", "--below Package",
                "Execute actions below Package") do |below|
          options.below = checked_package(the_conf, below)
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

        opts.on("-d", "--deps", "Print out dependencies") do 
          deps = the_conf['dependencies']
          deps.keys.sort.each do |client|
            puts sprintf("%-24s: [%s]", client, deps[client].sort.join(', '))
          end
          exit(0)
        end

        opts.on("-l", "--list", "List available command templates") do 
          templates = the_conf['config']['templates']
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
      
      opts.parse!(args)

      return options, the_conf
    end
  end

  def Roll.instantiate(component, template, graph, locations, install_dir)
    deps = []
    graph[component].each do |d|
      if locations.has_key?(d) then
        # e.g. graphviz has no location
        o = OpenStruct.new
        o.name = d
        o.prefix = File.join(install_dir, d)
        deps << o
      end
    end
    deps.compact! 
    prefix = File.join(install_dir, component)
    t = ERB.new(template)
    result = t.result(binding())
    return result
  end

  def Roll.run_command(command, options)
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

  def Roll.make_command(action, component, templates, deps, locations, install_dir)
    if templates.has_key?(action) then
      return instantiate(component, templates[action], 
                         deps, locations, install_dir)
    else
      return action
    end
  end

  def Roll.run_commands(actions, locations, deps, templates, install_dir, options)
    pwd = Dir.getwd
    order = deps.tsort
    if options.revert then
      order.reverse!
    end

    if options.package then
      todo = [options.package]
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
        command = make_command(action, component, templates, deps, locations, install_dir)
        run_command(command, options)
      end
      Dir.chdir(pwd)
    end
  end


  def Roll.roll(conf, options, actions)
    deps = conf['dependencies']
    locations = conf['locations']
    install_dir = conf['config']['install_dir']
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
