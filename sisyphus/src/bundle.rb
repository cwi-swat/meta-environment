
require 'tsort'
require 'erb'
require 'ostruct'
require 'optparse'
require 'yaml'

require 'templates'

class Hash
  include TSort
  alias tsort_each_node each_key
  def tsort_each_child(node, &block)
    fetch(node).each(&block)
  end
end

class Bundle
  attr_reader :name, :version, :packages, :dependencies, :location
  def initialize(name, version, packages, dependencies, location)
    @name = name
    @version = version
    @packages = packages
    @dependencies = dependencies
    @location = location
  end
end

class BundleGenerator
  include BundleTemplates
  attr_reader :bundle

  AUTOCONF = 'autoconf'
  AUTOMAKE = 'automake'
  ACLOCAL = 'aclocal'


  def initialize(bundle, target_dir = '.')
    @bundle = bundle
    @target_dir = target_dir
  end

  def generate
    create_directories
    generate_readme
    generate_authors
    generate_news
    generate_changelog
    generate_prechecks_makefile_am
    generate_collect_sh
    generate_acinclude
    generate_makefile_am
    generate_configure_ac
    generate_pkg_list
    run_autotools
    make_tar_gz
    return File.join(@target_dir, bundle_targz)
  end

  def bundle_stem
    "#{bundle.name}-bundle-#{bundle.version}"
  end

  def bundle_dir
    File.join(@target_dir, bundle_stem)
  end

  def prechecks_dir
    File.join(bundle_dir, 'pre-checks')
  end

  def create_directories
    `mkdir -p #{bundle_dir}`
    `mkdir -p #{prechecks_dir}`
  end

  def write_file(dir, filename, str)
    path = File.join(dir, filename)
    File.open(path, 'w') do |f|
      f.write(str)
    end
  end
    
  def generate_readme
    write_file(bundle_dir, 'README', instantiate(README))
  end

  def generate_authors
    write_file(bundle_dir, 'AUTHORS', AUTHORS)
  end

  def generate_news
    write_file(bundle_dir, 'NEWS', instantiate(NEWS))
  end

  def generate_changelog
    write_file(bundle_dir, 'ChangeLog', instantiate(CHANGELOG))
  end

  def generate_prechecks_makefile_am
    write_file(prechecks_dir, 'Makefile.am', PRE_CHECKS_MAKEFILE_AM)
  end

  def generate_collect_sh
    write_file(bundle_dir, 'collect.sh', COLLECT_SH)
    `chmod +x #{File.join(bundle_dir, 'collect.sh')}`
  end

  def generate_acinclude
    write_file(bundle_dir, 'acinclude.m4', ACINCLUDE)
  end

  def generate_makefile_am
    write_file(bundle_dir, 'Makefile.am', MAKEFILE_AM)    
  end

  def generate_configure_ac   
    write_file(bundle_dir, 'configure.ac', instantiate(CONFIGURE_AC))
  end

  def generate_pkg_list
    write_file(bundle_dir, 'pkg-list', instantiate(PKG_LIST))
  end

  def instantiate(string)
    ERB.new(string, nil, '<>').result(binding())
  end

  def run_autotools
    `cd #{bundle_dir} ; #{ACLOCAL} ; cd - `
    `cd #{bundle_dir} ; #{AUTOCONF} ; cd -`
    `cd #{bundle_dir} ; #{AUTOMAKE} -a -c --include-deps ; cd -`
  end

  def make_tar_gz
    `cd #{@target_dir} ; tar cvf - #{bundle_stem} | gzip -c > #{bundle_targz} ; cd -`
  end

  def bundle_targz
    return "#{bundle_stem}.tar.gz"
  end
  
end

class BundlePackage
  attr_reader :name, :version

  def initialize(name, version)
    @name = name
    @version = version
  end

  def to_s
    return @name
  end

  def eql?(b)
   return name == b.name && version == b.version
  end

  def ==(b)
   return name == b.name && version == b.version
  end

  def hash
    return "#{name}#{version}".hash
  end

end


def parse_command_line(args)
  options = OpenStruct.new
  options.bundle = nil
  options.version = nil
  options.location = nil
  options.dir = '.'
  options.rollrc = nil
  opts = OptionParser.new do |opts|
    opts.banner = "Usage: bundle [options]\n"
    opts.separator ""    
    opts.separator "Options:"
    
    opts.on("-b Bundle", "--bundle Bundle",
            "Bundle name") do |bundle|
      options.bundle = bundle
    end
    
    opts.on("-v Version", "--version Version", "Version indicator for bundle") do |version|
      options.version = version
    end
    
    opts.on("-l Location", "--location Location",
            "Location of package dists (for collect.sh).") do |location|
      options.location = location
    end
    
    opts.on("-d Dir", "--dir Dir",
            "Destination dir of bundle (default: .).") do |dir|
      options.dir = dir
    end

    opts.on("-r Rollrc", "--rollrc Rollrc",
            "Roll.rc file for dependencies.") do |rollrc|
      options.rollrc = rollrc
    end
  end

  opts.parse!(args)

  if !(options.bundle &&
       options.version &&
       options.location &&
       options.rollrc) then
    puts opts
    exit(1)
  end
  return options
end

def create_bundle_packages(locations, deps)
  names = deps.tsort
  name_map = {}
  dependencies = {}
  names.each do |name|
    path = locations[name]
    version = `svn info #{path} | grep 'Last Changed Rev' | cut -d ' ' -f 4`.chomp
    bundle_package = BundlePackage.new(name, version)
    name_map[name] = bundle_package
    # this works because of top sort.
    dependencies[bundle_package] = deps[name].collect { |name| name_map[name] }
  end
  return dependencies.tsort, dependencies
end

def main(args)
  options = parse_command_line(args)
  rollrc = nil
  File.open(options.rollrc) do |f|
    rollrc = YAML.load(f)
  end
  deps = rollrc['dependencies']
  locations = rollrc['locations']
  packages, dependencies = create_bundle_packages(locations, deps)
  bundle = Bundle.new(options.bundle, options.version, packages, dependencies, options.location)
  generator = BundleGenerator.new(bundle, options.dir)
  generator.generate
end


if $0 == __FILE__ then
  main(ARGV)
end
