module Distribution

  require 'versioning/boms'

  class SourceDister

    def initialize(item, checkout_root, source_dist_dir, collect_url, log)
      @item = item
      @checkout_root = checkout_root
      @source_dist_dir = source_dist_dir
      @collect_url = collect_url
      @log = log
    end

    def make_source_dists
      dist = build_dist_path(@item)
      @log.info("extracting #{dist}")
      `gunzip -c #{dist} | tar xf -`
      subdir = File.basename(dist, '.tar.gz')
      newdir = "#{@item.name}-#{pkg_version(@item)}"
      @log.info("Renaming #{subdir} to #{newdir}")
      `mv #{subdir} #{newdir}`
      @log.info("Creating #{source_dist_path(@item)}")
      `tar cf - #{newdir} | gzip > #{source_dist_path(@item)}`
      generate_package_file(@item)
    end

    private

    # bundling: autobundle -I . -p aterm-java-1132152437.pkg.af  -v 1132152437  -o .
    
    def build_dist_path(item)
      subdir = checkout_path(item)
      return Dir[File.join(subdir, "#{item.name}-[0-9.]*.tar.gz")][0]
    end

    def checkout_path(item)
      subdir = File.join(@checkout_root, item.name)
      return subdir
    end

    ## NB: This is duplicated from Checkout class :-(
    ## Need serious refactoring.


    def bom_reader
      pkg_files = Dir["#{@path}/*.pc.in"] 
      if pkg_files.empty? then
        return Versioning::PackageBOMReader.new(depfile_path(@path))
      else
        return Versioning::PKGConfigBOMReader.new(pkg_files[0])
      end
    end

    def extract_deps
      return bom_reader.dependencies
    end

    def extract_version
      return bom_reader.version
    end

    def depfile_path(root)
      path = File.join(root, 'package')
      if not test(?f, path) then
        pattern = File.join(root, "*.pkg")
        pkgs = Dir[pattern]
        path = pkgs == [] ? nil : pkgs[0]
      end
      if path.nil? then
        raise RuntimeError.new("no dependency file found in #{root}!")
      end
      return path
    end 


    # NB: configuration invariant:
    # source_dist_dir must coincide with collect_url
    # and collect_url must be world accessible over http.

    def pkg_version(item)
      v = extract_version(item)
      return "#{v}pre.#{item.version}.#{item.id}"
    end

    def dist_name(item)
      return "#{item.name}-#{pkg_version(item)}.tar.gz"
    end

    def source_dist_path(item)
      return File.join(@source_dist_dir, dist_name(item))
    end
    
    def collect_url(item)
      return File.join(@collect_url, dist_name(item))
    end

    def generate_package_file(item)
      path = File.join(@source_dist_dir, "#{item.name}-#{pkg_version(item)}.pkg")
      File.open(path, 'w') do |f|
        f.puts('package')
        f.puts('identification')
        f.puts("name=#{item.name}")
        f.puts("version=#{pkg_version(item)}")
        f.puts("location=#{@collect_url}")
        f.puts("info=")
        f.puts("description=")
        f.puts("keywords=")
        f.puts("configuration interface")
        f.puts("requires")
        item.dep_items.each do |dep|
          f.puts("#{dep.name} #{pkg_version(dep)}")
        end
      end
      parse_package_file(path)
    end

    def parse_package_file(path)
      # Note: these commands should be evaluated with CommandSpecificShell.
      table = '/ufs/sen1/software/installed/autobundle-0.12/linux/i386/share/autobundle/Autobundle.tbl'
      implode = '/ufs/sen1/software/installed/strategoxt-0.10/linux/i686/bin/implode-asfix'
      sglr= '/ufs/sen1/software/installed/strategoxt-0.10/linux/i686/bin/sglr'
      `#{sglr} -2 -p #{table} -i #{path} | #{implode} -S > #{path}.af`
    end

  end

end
