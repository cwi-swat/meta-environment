#! /usr/bin/env ruby

require 'tsort'
require 'ostruct'
require 'optparse'
require 'stringio'

class Hash
  include TSort
  alias tsort_each_node each_key
  def tsort_each_child(node, &block)
    fetch(node).each(&block)
  end
end


class GNUBuildActions
  attr_reader :prefix, :deps, :pkg

  def self.all_steps
    return default_steps + [:uninstall, :maintainer_mode, :dist, :distcheck]
  end

  def self.default_steps
    return [:reconf, :configure, :make, :install]
  end

  def self.doc
    str = StringIO.new
    str << "Build steps have the following meaning:\n"
    examples.each_key do |step|
      str << "    #{step}: #{examples[step]}\n"
    end
    return str.string
  end

  def self.examples
    gnu = GNUBuildActions.new('<somewhere>')
    deps = ['<some-dep>']
    examples = {}
    all_steps.each do |step|
      examples[step] = gnu.command(step, deps)
    end
    return examples
  end

  def initialize(prefix)
    @prefix = prefix
  end

  def command(step, deps)
    return send(step, deps)
  end

  private

  def with_options(deps)
    deps.collect do |dep|
      "--with-#{dep}=#{prefix}"
    end.join(' ')
  end

  def configure(deps)
    "./configure --prefix=#{prefix} #{with_options(deps)}"
  end

  def maintainer_mode(deps)
    "#{configure(deps)} --enable-maintainer-mode"
  end

  def make(deps)
    'make'
  end

  def install(deps)
    'make install'
  end

  def uninstall(deps)
    'make uninstall'
  end

  def reconf(deps)
    './reconf'
  end

  def dist(deps)
    'make dist'
  end

  def distcheck(deps)
    "DISTCHECK_CONFIGURE_FLAGS=\"#{with_options(deps)}\" make distcheck"
  end

end



class PKGConfigReader
  def initialize(dir)
    @dir = dir
  end

  def name
    if pkgconfig(@dir) =~ /([^\/]*)\.pc\.in$/ then
      return $1
    end
    raise "Could not parse package name in #{pkgconfig(@dir)}"
  end
  
  def requires
    File.open(pkgconfig(@dir)) do |f|
      return parse_requires(f)
    end
  end

  def can_read? 
    !pkgconfig(@dir).nil?
  end

  private

  def parse_requires(stream)
    stream.inject([]) do |result, line|
      match_requires(line)
    end
  end

  def match_requires(str)
    if str =~ /^Requires:(.*)$/ then
      return $1.strip.split(',')
    end
    return []
  end

  def pkgconfig(dir)
    Dir[File.join(dir, '*.pc.in')].first
  end

end

class CheckoutCrawler
  attr_reader :deps, :root

  def initialize(root)
    @deps = {}
    @root = root
    extract_deps
  end

  def each_dependency_of(pkg, &block)
    each_from_list(ordered & transitive_dependencies_of(pkg), &block)
  end

  def each_depending_on(pkg, &block)
    each_from_list(ordered & transitively_depending_on(pkg), &block)
  end

  def each_ordered(&block)
    each_ordered_without([], &block)
  end

  def each_ordered_without(exclude, &block)
    each_from_list(ordered - exclude, &block)
  end

  private

  def each_from_list(list)
    list.each do |pkg|
      yield subdir(pkg), deps[pkg]
    end
  end


  def transitively_depending_on(pkg)
    reachable_from(pkg, inverse(deps))
  end

  def transitive_dependencies_of(pkg)
    reachable_from(pkg, deps)
  end

  def inverse(deps)
    inv = {}
    inv.default = []
    deps.each_key do |pkg|
      deps[pkg].each do |dep|
        inv[dep] += [pkg]
      end
    end
    return inv
  end

  def reachable_from(pkg, deps)
    result = []
    todo = [pkg]
    while !todo.empty? do
      pkg = todo.shift
      result << pkg
      todo |= deps[pkg]
    end
    return result
  end

  def ordered
    deps.tsort
  end

  def subdir(pkg)
    File.join(root, pkg)
  end

  def extract_deps
    Dir[File.join(root, '*')].each do |file|
      extract_deps_if_dir(file)
    end
  end

  def extract_deps_if_dir(file)
    if File.directory?(file) then
      extract_package_deps(file)
    end
  end

  def extract_package_deps(dir)
    reader = PKGConfigReader.new(dir)
    if reader.can_read? then
      pkg = reader.name
      deps[pkg] = reader.requires
    end
  end
  
end

class BuildStepFailure < RuntimeError
  def initialize(subdir, command, status)
    @subdir = subdir
    @command = command
    @status = status
  end

  def message
    "Command '#{@command}' failed with status #{@status} in #{@subdir}"
  end
end


class MetaMaker
  attr_reader :crawler, :actions, :binpath, :steps

  def initialize(options, binpath = File.join(options.prefix, 'bin'))
    @crawler = CheckoutCrawler.new(options.root)
    @actions = GNUBuildActions.new(options.prefix)
    @steps = options.steps
    @binpath = binpath
  end

  def run
    begin
      execute_for_each_package(@steps)
    rescue BuildStepFailure => detail
      $stderr << "#{detail.message}\n"
      exit(1)
    end
  end
  
  private
  
  def execute_for_each_package(steps)
    crawler.each_ordered do |subdir, deps|
      execute_steps(subdir, steps, deps)
    end
  end

  def execute_steps(subdir, steps, deps)
    steps.each do |step|
      cmd = with_binpath(actions.command(step, deps))
      execute_step(subdir, cmd)
    end
  end    

  def execute_step(subdir, cmd)
    Dir.chdir(subdir) do
      success = execute_command(cmd) 
      raise BuildStepFailure.new(subdir, cmd, $?.exitstatus) unless success
    end
  end

  def execute_command(cmd)
    log(cmd)
    system(cmd)
  end

  def log(str)
    $stderr << "#{str}\n"
  end
  
  def with_binpath(cmd)
    "PATH=#{binpath}:${PATH} #{cmd}"
  end

end

class CommandLineOptions
  attr_reader :options, :opts

  META_PREFIX_VAR = 'META_PREFIX'

  def initialize(opts)
    @opts = opts # the parser
    @options = OpenStruct.new
    @options.prefix = ENV[META_PREFIX_VAR]
    @options.root = Dir.getwd
    @options.deps_of = nil
    @options.depending_on = nil
    @options.help = false
    @options.steps = GNUBuildActions.default_steps
  end

  def parse(args)
    header
    prefix_option
    root_option
    steps_option
    clients_of_option
    deps_of_option
    help_option
    parse_and_check(args)
  end

  private

  def parse_and_check(args)
    begin
      opts.parse!(args)
    rescue OptionParser::InvalidOption
      usage(1)
    end
    usage(1) unless options.prefix
    return options
  end

  def usage(retval = 0)
    puts opts
    puts
    puts GNUBuildActions.doc
    exit(retval)
  end

  def header
      opts.banner = """Usage: meta-make [options]

    This program executes a sequence of build steps for each package directory
    found in a 'root' directory. The steps are executed in a topological order,
    based on the dependency graph that is derived from package config (.pc.in)
    files in those very directories.
"""
      opts.separator ""    
      opts.separator "Options:"
  end


  def prefix_option
    opts.on("-p Prefix" , "--prefix Prefix", 
            "Installation prefix for all packages (#{META_PREFIX_VAR})") do |prefix|
      options.prefix = prefix
    end
  end

  def root_option
    opts.on("-r Root" , "--root Root", 
            "Checkout root containing packages [#{options.root}]") do |root|
      options.root = root
      check_root(root)
    end
  end

  def steps_option
    opts.on("-s Steps", "--steps Steps", 
              "Steps to be performed [#{options.steps.join(',')}]") do |steps|
      options.steps = steps.split(',').collect do |step|
        step.intern
      end
      check_steps(options.steps)
    end
  end

  def clients_of_option
    opts.on("-c Package", "--clients-of Package",
            "Apply steps to packages (transitively) depending on package only") do |pkg| 
      options.depending_on = pkg
    end
  end

  def deps_of_option
    opts.on("-d Package", "--deps-of Package",
            "Apply steps to (transitive) package dependencies only") do |pkg| 
      options.deps_of = pkg
    end
  end

  def help_option
    opts.on("-h", "--help", "Display usage") do
      usage
    end
  end

  def check_steps(steps)
    all_steps = GNUBuildActions.all_steps
    diff = all_steps - steps
    unless diff.empty? then
      error("step(s) #{diff.join(', ')} are not included in #{all_steps.join(', ')}")
    end
  end
  
  def check_root(root)
    unless File.exists?(root) 
      error("given root #{root} does not exist")
    end
  end

  def error(message)
    $stderr << message + "\n"
    exit(1)
  end
  
end

if $0 == __FILE__ then
  options = CommandLineOptions.new(OptionParser.new).parse(ARGV)
  meta_maker = MetaMaker.new(options)
  meta_maker.run
end
