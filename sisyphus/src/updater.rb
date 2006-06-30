module Updating

  require 'distconf'

  require 'yaml'
  require 'logger'

  class SisyphusUpdater

    def initialize(distribution_conf, log)
      @distribution_conf = distribution_conf
      @log = log
    end

    def install_latest(pkg, prefix)
      candidate_tree = @distribution_conf.package_candidates(pkg)
      latest_revision = candidate_tree.keys.sort.last
      latest_candidate = candidate_tree[latest_revision].sort.last
      install(pkg, latest_revision, latest_candidate, prefix)
    end
    
    def install(pkg, rev, cand, prefix)
      tree = @distribution_conf.url_for(pkg, rev, cand)
      @log.info "Installing: #{pkg} version #{rev} build #{cand} in #{prefix}"
      if not File.exists?(prefix) then
        @log.info `svn checkout #{tree} #{prefix}`
      else
        @log.info `svn revert --recursive #{prefix}`
        @log.info `svn switch #{tree} #{prefix}`
      end
      relocate(pkg, prefix)
    end

    def relocate(pkg, prefix)
      @log.info "Relocating..."
      boms = @distribution_conf.read_boms_below(pkg, prefix)
      prefix = File.expand_path(prefix)
      todo = [pkg]
      done = []
      while todo != [] do
        pkg = todo.pop
        bom = boms[pkg] 
        old_prefixes = @distribution_conf.prefixes(pkg, boms)
        substitute_in_files(bom['files'], old_prefixes, prefix)
        done << pkg   
        bom['deps'].each do |dep|
          if not done.include?(dep) then
            todo |= [dep]
          end
        end
      end 
    end

    def substitute_in_files(files, old_prefixes, prefix)
      for path in files do
        substitute_in_file(path, old_prefixes, prefix)
      end
    end

    def equalize_prefixes(old_prefix, new_prefix)
      new_prefix = File.expand_path(new_prefix)
      enlarged_old = @distribution_conf.enlarge_path(old_prefix)
      num_of_slashes = enlarged_old.length - old_prefix.length
      num_of_slashes -= new_prefix.length - old_prefix.length
      enlarged_new = @distribution_conf.enlarge_path(new_prefix, num_of_slashes)
      if enlarged_new.length != enlarged_old.length then
        raise "Unequal pathlengths: old: #{enlarged_old}, new: #{enlarged_new}"
      end
      return enlarged_old, enlarged_new
    end

    def substitute_in_file(path, old_prefixes, new_prefix)
      path = File.join(new_prefix, path)
      data = nil
      File.open(path) do |f|
        data = f.read
      end
      substitute_each_prefix(path, data, old_prefixes, new_prefix)
      File.open(path, 'w') do |f|
        f.write(data)
      end
    end  

    def substitute_each_prefix(path, data, old_prefixes, new_prefix)
      old_prefixes.each do |old_prefix|
        old, new = equalize_prefixes(old_prefix, new_prefix)
        if `file #{path}`.match(/text/) then
          new = File.join(File.dirname(new), File.basename(new))
        end
        r = data.gsub!(old, new)
      end
    end

    def current_version(prefix)
      info = `svn info #{prefix}`
      if info.rstrip =~ /\(Not a versioned resource\)/ then
        return nil
      else
        url = info.split[3]
        if url =~ /^.*\/([0-9]+)\/([0-9]+)$/ then
          return $1.to_i, $2.to_i
        end
        raise "Malformed url: #{url}"
      end
    end
    
  end

end

$dist_url = 'file:///export/scratch1/storm/sisyphus-dist/glt-dists'
$install_dir = './bla'


if $0 == __FILE__ then
  pkg = 'pt-support'
  log = Logger.new(STDERR)
  log.level = Logger::INFO

  dist_conf = Distribution::DistributionConfiguration.new($dist_url)
  
  updater = Updating::SisyphusUpdater.new(dist_conf, log)
  updater.install_latest(pkg, $install_dir)
end
