
require 'tmpdir'
require 'ostruct'
require 'yaml'
require 'time'
require 'model/db'
require 'optparse'
require 'tsort'
require 'bundle'

class Hash
  include TSort
  alias tsort_each_node each_key
  def tsort_each_child(node, &block)
    fetch(node).each(&block)
  end
end

class CommandLineParser
  def self.parse(args)
    options = OpenStruct.new
    options.build = nil
    options.workdir = Dir.tmpdir
    options.dbconf = nil
    options.dists = nil
    options.rc = nil
    options.exclude = []
    
    opts = OptionParser.new do |opts|
      opts.banner = "Usage: ophion [options]"
      opts.separator ""
      opts.separator "Options:"

      opts.on("-r build", "--release Build",
              "Build to be released") do |build|
        options.build = build.to_i
      end

      opts.on("-x Pkgs", "--exclude Pkgs",
              "Packages to be excluded (sep. by commas)") do |pkgs|
        options.exclude = pkgs.split(',')
      end

      opts.on("-c Candidate", "--candidate Candidate",
              "Release candidate identifier") do |rc|
        options.rc = rc
      end
      

      opts.on("-w Workdir", "--workdir Workdir",
              "Absolute dir to put distributions (#{options.workdir}).") do |workdir|
        options.workdir = workdir
      end
 
      opts.on("-p Path", "--path Path", "Location of dists.") do |p|
        options.dists = p
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

      if options.build.nil? or 
          options.dbconf.nil? or
          options.dists.nil?
      then
        puts opts
        exit(1)
      end
      
      return options
    end
    
  end
  
end

def release_version(build, rc)
  version = build.informative_version
  if rc then
    version += rc
  end
  return version
end

class BuildBundlePackage < BundlePackage
  attr_reader :build
  def initialize(build, path, rc)
    super(build.name, release_version(build, nil))
    @path = path
    @build = build
  end
 
  def dist_path
    return File.join(@path, @build.targz)
  end

  def release_dist
    return "#{@build.name}-#{version}.tar.gz"
  end

  def copy_as_released(destination)
    dest_file = File.join(destination, release_dist)
    if File.exist?(dest_file) then
      puts "Archive #{release_dist} already created; reusing that one."
    else
      cmd = "cp #{dist_path} #{dest_file}"
      puts "Transforming #{dist_path} to #{dest_file}."
      system(cmd)
      Dir.chdir(destination) do 
        system("tar zxvf #{dest_file}")
        system("rm #{dest_file}")
        new_name = "#{@build.name}-#{version}"
        system("mv #{@build.name}-#{@build.targz_version} #{new_name}")
        system("tar zcvf #{dest_file} #{new_name}")
      end
    end
  end

  def release
    print "Sure to release: #{name}-#{version}? [Yn]"
    if gets.chomp != 'n' then
      Model::SiItem.transaction do
        @build.released = true
        @build.save
      end
      puts "Done."
    end
  end

end

def bundle_packages_for_build(build, path, excluded, rc)
  deps = {}
  puts "Computing transitive closure for build #{build.id} of revision #{build.version} of #{build.name}..."
  build.edges.each do |x, y|
    px = BuildBundlePackage.new(x, path, rc)
    py = BuildBundlePackage.new(y, path, rc)
    if not excluded.include?(px.name) then
      deps[px] ||= []
    end
    if not excluded.include?(py.name) then
      deps[py] ||= []
    end
    if !excluded.include?(px.name) &&
        !excluded.include?(py.name) then
      deps[px] << py
    end
  end
  puts "Done."
  return deps
end

if $0 == __FILE__ then
  options = CommandLineParser.parse(ARGV)
  store = Model::DBStore.new(options.dbconf)
  store.connect
  build = Integer(options.build)
  root = Model::SiItem.find(build)  
  deps = bundle_packages_for_build(root, options.dists, options.exclude, options.rc)
  pkgs = deps.tsort
  pkgs.each do |pkg|
    pkg.copy_as_released(options.workdir)
  end

  url = "file://#{options.workdir}"
  version = release_version(root, options.rc)
  bundle = Bundle.new(root.name, version, pkgs, deps, url)

  dest_dir = "."
  gen = BundleGenerator.new(bundle, dest_dir)
  if File.exist?(gen.bundle_targz) then
    puts "Bundle #{gen.bundle_targz} already exists; generation skipped."
  else
    puts "Generating #{gen.bundle_targz}"
    gen.generate
    puts "Done."
  end

  collected_bundle = "#{gen.bundle_stem}-precollected.tar.gz"
  if File.exist?(collected_bundle) then
    puts "Collected bundle #{collected_bundle} exists; generation skipped."
  else 
    puts "Creating #{File.join(dest_dir, collected_bundle)}."
    bundle_dir = File.join(dest_dir, gen.bundle_stem)
    puts "Running ./collect.sh in #{bundle_dir}."
    Dir.chdir(bundle_dir) do
      system("./collect.sh")
    end
    Dir.chdir(dest_dir) do 
      system("tar zcvf #{collected_bundle} #{gen.bundle_stem}")
    end
    puts "Done."
  end
  
  print "Release? [NO|yes] "
  answer = gets
  if answer.chomp == 'yes' then
    errors = false
    pkgs.each do |pkg|
      item = pkg.build
      query =<<EOQ
select si_items.* 
from si_items, si_revisions 
where 
  si_items.si_revision_id = si_revisions.id and
  si_component_id = #{item.si_revision.si_component.id} and 
  released = true and 
  informative_version = '#{item.informative_version}'
EOQ
      puts "Checking if #{pkg} has not been released earlier as #{item.informative_version}..."
      released_items_with_same_version = Model::SiItem.find_by_sql(query)
      if not released_items_with_same_version.empty? then
        puts "Yes."
        print "Is this a problem? [NO|yes]"
        if gets.chomp != 'yes' then
        else
          errors = true
        end
      else
        puts "No."
      end
    end
    if errors then
      exit(1)
    else
      pkgs.each do |pkg|
        pkg.release
      end
    end
  end

end
