
require 'model/db'
require 'building/config'
require 'versioning/vcs'
require 'versioning/revision'
require 'versioning/component'
require 'bundle'

require 'tmpdir'

def parse_package_file(path)
  # Note: these executable do NOT work on 64bits machines.
  table = '/ufs/sen1/software/installed/autobundle-0.12/linux/i386/share/autobundle/Autobundle.tbl'
  implode = '/ufs/sen1/software/installed/strategoxt-0.10/linux/i686/bin/implode-asfix -S'
  sglr= '/ufs/sen1/software/installed/strategoxt-0.10/linux/i686/bin/sglr -2'
  system("#{sglr} -p #{table} -i #{path} | #{implode} > #{path}.af")
end

def autobundle(name, version)
  autobundle = '/ufs/sen1/software/installed/autobundle-0.12/linux/i386/bin/autobundle'
  pkg = name + '-' + version
  puts("#{autobundle} -I . -p #{pkg}.pkg.af -v #{version} -o .")
  system("#{autobundle} -I . -p #{pkg}.pkg.af -v #{version} -o .")
  return name + "-bundle-" + version
end


  def ariadne_bundle(item, output_dir = Dir.tmpdir)   
    deps = {}
    item.edges.each do |i1, i2|
      pkg1 = BundlePackage.new(i1.name, i1.targz_version)
      pkg2 = BundlePackage.new(i2.name, i2.targz_version)
      deps[pkg1] ||= []
      deps[pkg2] ||= []
      deps[pkg1] << pkg2
    end

    # Todo: from -u
    location = 'http://sisyphus.meta-environment.org/downloads'
    # The list of packages must be in topological sort!
    bundle = Bundle.new(item.name, item.targz_version, deps.tsort, deps, location)
    gen = BundleGenerator.new(bundle, output_dir)
    return gen.generate # returns path of bundle targz
  end


def package_names(builds)
  packages = builds.collect do |build|
    build.name + '-' + build.si_revision.informative_version.strip +
      'pre.' + build.si_revision.version.to_s + '.' + build.id.to_s
  end
  return packages
end

def compute_renaming_to_informative(builds)
  # NB: this map is also used in Sisyphus itself
  # when making this distribution. DRY!
  map = {}
  builds.each do |build|
    map[build.si_revision.informative_version.strip +
        'pre.' + build.si_revision.version.to_s + '.' + build.id.to_s] =
      build.si_revision.informative_version.strip
  end
  return map
end

def copy_src_dists(sisyphus_dist_location, packages)
    packages.each do |pkg|
      system("cp #{sisyphus_dist_location}/#{pkg}.tar.gz .")
      #system("cp #{sisyphus_dist_location}/#{pkg}.pkg .")
      system("tar zxvf #{pkg}.tar.gz")
      system("rm #{pkg}.tar.gz")
    end
end

def rename_packages_and_archives(map, packages)
  map.each_key do |version|
    puts("rename #{version} #{map[version]} *")
    system("rename #{version} #{map[version]} *")
    packages = packages.collect do |pkg|
      pkg.gsub(version, map[version])
    end
  end
  return packages
end


def rename_package_definitions_in_archives(map, packages, collect_url)
  packages.each do |pkg|
    system("tar zcvf #{pkg}.tar.gz #{pkg}")
    system("rm -r #{pkg}")
    pkgdef = nil
    pkgfile = pkg + '.pkg'
    in_place(pkgfile) do |pkgdef|
      map.each_key do |version|
        pkgdef = pkgdef.gsub(version, map[version])
        pkgdef = pkgdef.gsub(/^location=(.*)$/, "location=#{collect_url}/#{package_stem(pkg)}")
      end
      pkgdef
    end
    parse_package_file(pkgfile)
  end 
end



def create_bundle_for_build(root)    
  bundle_archive = ariadne_bundle(root)
  if bundle_archive =~ /^(.*)\.tar\.gz$/ then
    bundle_name = $1
  else
    bundle_name = bundle_archive
  end
  return bundle_name
end

def create_bundles_for_packages(packages)
  packages.each do |pkg|
    ariadne_bundle(pkg)
  end
end

def collect_bundle(bundle_name, temp_collect_url, trg_collect_url)
  system("tar zxvf #{bundle_name}.tar.gz")
  Dir.chdir(bundle_name) do
    pkglistfile = 'pkg-list'
    in_place(pkglistfile) do |pkglist|
      puts "SUBSTITUTING: #{temp_collect_url}"
      gets
      pkglist.gsub(/,[^,]*$/, ',' + temp_collect_url)
    end
    system('./collect.sh')    
    in_place(pkglistfile) do |pkglist|
      pkglist.gsub(temp_collect_url, trg_collect_url)
    end
  end  
end

def integrate_bundle(bundle_name)
  Dir.chdir(bundle_name) do
    system("./configure --prefix=#{Dir.tmpdir}")
    system("make install distcheck")
  end
  #return File.join(bundle_name, bundle_name + '.tar.gz')
end

def just_archive_bundle(bundle_name)
  system("tar zcvf #{bundle_name}.tar.gz #{bundle_name}")
end


def package_stem(pkg_version)
  if pkg_version =~ /^([^.]*)-.+$/ then
    return $1
  else
    raise "Could not extract package stem from release name #{pkg_version}"
  end
end

def package_version(pkg_version)
  if pkg_version =~ /^([^.]*)-(.+)$/ then
    return $2
  else
    raise "Could not extract package version from release name #{pkg_version}"
  end
end

def copy_packages(packages, dist_host, packages_dir)
  packages.each do |package|
    stem = package_stem(package)
    mkd = "ssh #{dist_host} mkdir -p #{packages_dir}/#{stem}"
    system(mkd)
    cmd = "scp #{package}.tar.gz #{dist_host}:#{packages_dir}/#{stem}"
    system(cmd)    
    cmd = "scp #{package}.pkg* #{dist_host}:#{packages_dir}/#{stem}"
    system(cmd)    
  end
end

def copy_bundle_archives(packages, dist_host, bundles_dir)
  mkd = "ssh #{dist_host} mkdir -p #{bundles_dir}"
  system(mkd)
  cmd = "scp -r *bundle*.tar.gz #{dist_host}:#{bundles_dir}"
  system(cmd)
end
    

def in_place(filename)
  content = nil
  File.open(filename) do |f|
    content = f.read
  end
  content = yield content
  File.open(filename, 'w') do |f|
    f.write(content)
  end
end

require 'release/options'

if __FILE__ == $0 then
  options = Release::CommandLineParser.parse(ARGV)

  dist_host = options.host
  bundles_dir = File.join(options.collect_path, 'bundles')
  packages_dir = options.collect_path # per package subdir
  collect_url = options.collect_url
  src_dist_location = options.src_dists
  dbconf = options.dbconf
  build_to_be_released = options.build
  workdir = File.expand_path(options.workdir)
  test = options.test

  system("mkdir -p #{workdir}")

  store = Model::DBStore.new(dbconf)
  store.connect
  root = Model::SiItem.find(build_to_be_released)


  builds = [root]
  if options.bundle then
    root.as_nodes do |n|
      builds |= [n]
    end
  end
  map = compute_renaming_to_informative(builds)
  packages = package_names(builds)    

  Dir.chdir(workdir) do 
    
    copy_src_dists(src_dist_location, packages)

    puts "Copyied source dists to #{workdir}"
    gets

    packages = rename_packages_and_archives(map, packages)

    puts "Renamed packages and archives"
    gets

    #rename_package_definitions_in_archives(map, packages, collect_url)

    bundle_name = create_bundle_for_build(root)

    puts "Created bundle #{bundle_name} for #{root}"
    gets
    

    collect_bundle(bundle_name, 'file://' + workdir, collect_url)

    puts "Collected bundle"
    gets
    

    if test then
      integrate_bundle(bundle_name)
    else
      just_archive_bundle(bundle_name)
    end

    puts "Archived bundle #{bundle_name}"
    gets

    bundle_archive = File.join(bundle_name, bundle_name + '.tar.gz')     
    #system("mv #{bundle_archive} ./#{bundle_name}-collected.tar.gz")
    system("rm -r #{bundle_name}")


    puts "Ready to release to following packages?"
    packages.each do |pkg|
      puts "* #{pkg}"
    end

    puts "Going to copy "
    packages.each do |pkg|
      puts " * #{pkg}.tar.gz to #{packages_dir}/#{package_stem(pkg)}"
    end
    puts "and "
    puts " * #{bundle_archive} to: #{bundles_dir}."
    puts "And the release bit will be set to true for all packages involved."
    $stdout << "Are you sure? [yN] "
    resp = gets
    unless resp =~ /[Yy]/ then
      puts "Exiting..."
      exit
    end


    builds.each do |build|
      if not build.released then
        build.released = true
        build.save
      else
        puts "Build #{build} has been released already."
      end
    end

    copy_packages(packages, dist_host, packages_dir)
    copy_bundle_archives(packages, dist_host, bundles_dir)


  end
end
