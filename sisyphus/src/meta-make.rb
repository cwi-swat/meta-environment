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
    return default_steps + [:uninstall, :maintainer_mode]
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

  def configure(deps)
    cmd = "./configure --prefix=#{prefix} "
    cmd += deps.collect do |dep|
      "--with-#{dep}=#{prefix}"
    end.join(' ')
    return cmd
  end

  def maintainer_mode(deps)
    configure(deps) + " --enable-maintainer-mode"
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
      f.each_line do |line|
        if line =~ /^Requires:(.*)$/ then
          return $1.strip.split(',')
        end
      end
    end
    return []
  end

  def can_read? 
    !pkgconfig(@dir).nil?
  end

  private

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

  def each_ordered
    deps.tsort.each do |pkg|
      yield subdir(pkg), deps[pkg]
    end
  end

  private

  def subdir(pkg)
    File.join(root, pkg)
  end

  def extract_deps
    Dir[File.join(root, '*')].each do |file|
      if File.directory?(file) then
        extract_package_deps(file)
      end
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
      execute_step(subdir, actions.command(step, deps))
    end
  end
    
  def execute_step(subdir, cmd)
    Dir.chdir(subdir) do
      cmd = with_binpath(cmd)
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

  def initialize(opts)
    @opts = opts # the parser
    @options = OpenStruct.new
    @options.prefix = nil
    @options.root = Dir.getwd
    @options.help = false
    @options.steps = GNUBuildActions.default_steps
  end

  def parse(args)
    header
    prefix_option
    root_option
    steps_option
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
              "Installation prefix for all packages (required)") do |prefix|
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
