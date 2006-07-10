
require 'model/db'
require 'building/config'
require 'versioning/vcs'
require 'versioning/revision'
require 'versioning/component'

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
      system("cp #{sisyphus_dist_location}/#{pkg}.pkg .")
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


def rename_package_definitions_in_archives(map, packages)
  packages.each do |pkg|
    system("tar zcvf #{pkg}.tar.gz #{pkg}")
    system("rm -r #{pkg}")
    pkgdef = nil
    pkgfile = pkg + '.pkg'
    in_place(pkgfile) do |pkgdef|
      map.each_key do |version|
        pkgdef = pkgdef.gsub(version, map[version])
      end
      pkgdef
    end
    parse_package_file(pkgfile)
  end 
end



def create_bundle_for_build(root)    
  name = root.name
  version = root.si_revision.informative_version.strip
  bundle_name = autobundle(name, version)
  return bundle_name
end

def collect_bundle(bundle_name, temp_collect_url, trg_collect_url)
  system("tar zxvf #{bundle_name}.tar.gz")
  Dir.chdir(bundle_name) do
    pkglistfile = 'pkg-list'
    pkglist = nil
    in_place(pkglistfile) do |pkglist|
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
  return File.join(bundle_name, bundle_name + '.tar.gz')
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
  workdir = options.workdir


  #dist_host = 'build-www.cwi.nl'
  #bundles_dir = '/cwi/www/sites/www.cwi.nl/projects/MetaEnv/bundles'
  #packages_dir = '/cwi/www/sites/www.cwi.nl/projects/MetaEnv'
  #collect_url = 'http://www.cwi.nl/projects/MetaEnv'

  # This dir should contain .tar.gz, .pkg  files
  #sisyphus_dist_location = '/ufs/daybuild/sisyphus-www/wo-sisyphus/public/downloads'
  #src_collect_url = 'http://sisyphus.sen.cwi.nl:8080/downloads'

  #db_config_file = '../../doc/dbconf.yml'

  # editor plugin
  #build_to_be_released = 16465
  #build_to_be_released = 16446

  #dbconf = nil
  # Just for testing now...
  #File.open(db_config_file) do |f|
  #  dbconf = YAML.load(f)
  #end

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
    packages = rename_packages_and_archives(map, packages)
    rename_package_definitions_in_archives(map, packages)
  
    if options.bundle then
      bundle_name = create_bundle_for_build(root)
      collect_bundle(bundle_name, 'file://' + workdir, collect_url)
      bundle_archive = integrate_bundle(bundle_name)
      copy_bundle_archive(bundle_archive, host, bundles_dir)
    end

  end
    

end
