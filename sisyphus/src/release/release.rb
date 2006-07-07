
require 'model/db'
require 'building/config'
require 'versioning/vcs'
require 'versioning/revision'
require 'versioning/component'

def parse_package_file(path)
  # Note: these commands should be evaluated with CommandSpecificShell.
  table = '/ufs/sen1/software/installed/autobundle-0.12/linux/i386/share/autobundle/Autobundle.tbl'
  implode = '/ufs/sen1/software/installed/strategoxt-0.10/linux/i686/bin/implode-asfix -S'
  sglr= '/ufs/sen1/software/installed/strategoxt-0.10/linux/i686/bin/sglr -2'
  #sglr= 'sglr'
  #implode = 'implodePT -t'
  system("#{sglr} -p #{table} -i #{path} | #{implode} > #{path}.af")
end


if __FILE__ == $0 then
  # This dir should contain .tar.gz, .pkg  files
  dist_location = '/export/scratch1/storm/sisyphus/temp'
  workdir = './bla'

  system("mkdir -p #{workdir}")
  

  dbconf = nil
  # Just for testing now...
  File.open('../../doc/dbconf.yml') do |f|
    dbconf = YAML.load(f)
  end

  store = Model::DBStore.new(dbconf)
  store.connect

  # editor plugin
  root = Model::SiItem.find(16465)

  # big: 
  #i = Model::SiItem.find(1643)

  bom = []
  root.as_nodes do |n|
    bom |= [n]
  end

  packages = bom.collect do |build|
    build.name + '-' + build.si_revision.informative_version.strip +
      'pre.' + build.si_revision.version.to_s + '.' + build.id.to_s
  end

  map = {}
  bom.each do |build|
    map[build.si_revision.informative_version.strip +
        'pre.' + build.si_revision.version.to_s + '.' + build.id.to_s] =
      build.si_revision.informative_version.strip
  end
  
  Dir.chdir(workdir) do 

    packages.each do |pkg|
      system("cp #{dist_location}/#{pkg}.tar.gz .")
      system("cp #{dist_location}/#{pkg}.pkg .")
    end


    packages.each do |pkg|
      system("tar zxvf #{pkg}.tar.gz")
      system("rm #{pkg}.tar.gz")
    end
    map.each_key do |version|
      puts("rename #{version} #{map[version]} *")
      system("rename #{version} #{map[version]} *")
      packages = packages.collect do |pkg|
        pkg.gsub(version, map[version])
      end
    end

    # "Packages" now contains the new names
    packages.each do |pkg|
      system("tar zcvf #{pkg}.tar.gz #{pkg}")
      system("rm -r #{pkg}")
      pkgdef = nil
      pkgfile = pkg + '.pkg'
      File.open(pkgfile) do |f|
        pkgdef = f.read
      end
      map.each_key do |version|
        pkgdef.gsub!(version, map[version])
      end
      File.open(pkgfile, 'w') do |f|
        f.write(pkgdef)
      end
      parse_package_file(pkgfile)
    end 

    autobundle = '/ufs/sen1/software/installed/autobundle-0.12/linux/i386/bin/autobundle'
    packages.each do |pkg|
      name, version = pkg.split('-')
      system("#{autobundle} -I #{workdir} -p #{name} -v #{version} -o #{workdir}")
    end
  end

end
