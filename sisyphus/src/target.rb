module Building

  require 'sourcedist'
  require 'fileutils'
  require 'empty-shell'
  require 'context'
  require 'udir'

  class ActionResult
    attr_accessor :errors, :output, :success, :environment
  end


  class Target
    include Utils::UnameDir
    include FileUtils
    attr_reader :revision, :config, :session, :item, :dep_items

    def initialize(revision, dep_items, config, session, log, dist_conf)
      @revision = revision
      @dep_items = dep_items
      @config = config
      @session = session
      @log = log
      @dist_conf = dist_conf
      @item = nil
    end

    def host
      return session.host
    end

    def time
      return session.time
    end

    def path
      return revision.checkout_path
    end

    def deps_have_changed?
      return session.has_any?(revision.deps)
    end

    def deps_are_successful?
      return dep_items.inject(true) do |cur, item|
        cur && item.success
      end
    end


    def to_s
      return revision.to_s
    end

    def obtain_item(store)
      @item = store.item_for_target(self, @dep_items)
      @log.info("Obtaining new build item from store: #{@item}")
      @log.info("With dependencies: #{@dep_items.join(', ')}")
    end

    def save(store)
      @log.info("Saving item: #{@item}")
      store.save(@item)
    end

    def set_progress(bool)
      @item.set_progress(bool)
    end

    def fire
      set_progress(true)
      do_the_build
      set_progress(false)
    end

    def do_the_build
      context = Context.new(config, @item)
      cd path do 
        execute_actions(context)
      end
      @session.add(@revision, @item)
    end

    def not_tried
      set_progress(false)
    end

    def execute_actions(context)
      @item.set_success(false)
      context.actions do |action, command|
        @log.info("Performing action #{action}: #{command}")
        if not execute_command(action, command).success then
          return
        end
      end
      # @log.info("Making #{@item} successful.")
      @item.set_success(true)
      make_dists(context)
    end


    def make_dists(context)
      if @config.distributes? then 
        @log.info("creating source distribution for #{@item} in #{@config.source_dist_dir}")
        make_source_dists(context.item)
      end
      if `uname -n`.chomp == 'batatrom.sen.cwi.nl' then
        #make_binary_dists2(context)
      end
    end


    def ensure_svn_url(url)
      if `svn info #{url}`.rstrip =~ /\(Not a valid URL\)/ then
        dirname = File.dirname(url)
        if dirname != url then
          ensure_svn_url(dirname)
        end
        @log.info("svn mkdir #{url} -m \"Creating url: #{url}\"")
        `svn mkdir #{url} -m "Creating url: #{url}"`
      end   
    end

    def bom_file_name(name)
      return "#{name}.bom"
    end

    def create_bom(latest_checkout, context)
    end

    def make_binary_dists2(context)
      dist_repo = 'file:///export/scratch1/storm/sisyphus-dist/glt-dists'
      my_platform_dists = File.join(dist_repo, uname_dir)
      my_candidates = File.join(my_platform_dists, 'candidates')
      my_latest = File.join(my_platform_dists, 'latest')

      ensure_svn_url(my_candidates)
      ensure_svn_url(my_latest)

      latest_checkout_root = '/export/scratch1/storm/sisyphus-latest'
      latest_checkout = File.join(latest_checkout_root, 'latest')


      # Checkout the tree with the latest composite installations
      if not File.exist?(latest_checkout) then
        @log.info("svn co #{my_latest} #{latest_checkout}")
        `svn co #{my_latest} #{latest_checkout}`
      else
        @log.info("svn update  #{latest_checkout}")
        `svn update #{latest_checkout}`
      end


      # Strip //// because it clutters the log output.
      prefix = File.join(File.dirname(context.prefix), File.basename(context.prefix))

      # Find the list of absolute paths that are 
      # installed in the current build 
      # (without the prefix itself)
      dist_paths = `find #{prefix}`.split("\n")
      dist_paths -= [prefix]

      # Contstruct the prototypical bom
      bom = {}
      bom['files'] = []
      bom['dirs'] = []

      # Construct its (to be) location
      bomfile = File.join(latest_checkout, bom_file_name(context.item.name))
      # If a bom already exists at the location...
      # open it to determine the set of files
      # in the previous version (see below)
      if File.exists?(bomfile) then
        File.open(bomfile) do |f|
          bom = YAML.load(f)
        end
      end

      bom['identification'] = {}
      bom['identification']['name'] = item.name
      bom['identification']['revision'] = item.version
      bom['identification']['build'] = item.id
      bom['identification']['session'] = item.si_session.time
      bom['identification']['prefix'] = prefix
      bom['identification']['host'] = item.si_host.uname
      bom['checksums'] = {}

      dist_files = []
      dist_dirs = []

      dist_paths.collect do |path|
        if File.directory?(path) then
          dist_dirs << sub_prefix(prefix, path)
        else
          dist_files << sub_prefix(prefix, path)
        end
      end

      # If there was no old bomfile, bom['files'] == []
      # so all files in dist_files will be added.
      added_files = dist_files - bom['files']   
      added_dirs = dist_dirs - bom['dirs']
      
      dist_files.each do |file|
        path = File.join(prefix, file)
        bom['files'] |= [file]
        bom['checksums'][file] =  `md5sum #{path}`.split.first
      end

      dist_dirs.each do |dir|
        bom['dirs'] |= [dir]
      end


      # Now that any new file in dist_file has been added
      # to bom['files'], the remaining ones after subtracting
      # those in dist_files can be removed.
      removed_files = bom['files'] - dist_files
      removed_dirs = bom['dirs'] - dist_dirs

      
      # Reinitialize dependencies
      bom['deps'] = []
      item = context.item
      item.si_deps.each do |dep|
        bom['deps'] << dep.name
      end

      # These files must not be overwritten
      dep_files = []
      bom['deps'].each do |dep|
        # Because of the dependency invariant, the
        # bomfiles for dependencies *must* exist.
        dep_files |= collect_bom_files(latest_checkout, dep)
      end

      # If any of the dist_files overlaps with a
      # file of one of the dependencies we cannot proceed.
      untouchable = dist_files & dep_files
      if untouchable != [] then
        raise "Error: trying to overwrite files from dependencies: #{untouchable}\n"
      end

      dist_dirs.each do |dir|
        dest_path = File.join(latest_checkout, dir)
        @log.info("mkdir -p #{dest_path}")
        `mkdir -p #{dest_path}`
      end

      # Now that it's safe to continue, copy all files to the checkout.
      # Note that dist_files does contain directories
      # whereas in the bom they are split.
      dist_files.each do |file|
        src_path = File.join(prefix, file)
        dest_path = File.join(latest_checkout, file)
        @log.info("cp #{src_path} #{dest_path}")
        if not File.exists?(dest_path) then
          @log.info("Apparently a file did not exist where it should have been overwritten.")
          @log.info("I'm copying #{src_path} to #{dest_path} and adding it to svn.")
          @log.info("This may be the result of a corrupted bom file.")
          `cp #{src_path} #{dest_path}`
          `svn add #{dest_path}`
        else
          `cp #{src_path} #{dest_path}`
        end
      end


      
      # Remove files old files from repository
      # Before any dirs are removed.
      removed_files.each do |file|
        path = File.join(latest_checkout, file)
        @log.info("svn remove #{path}")
        `svn remove #{path}`
        bom['checksums'].delete(file)
      end

      # User inverted sort on length
      # so that children of a dir
      # are removed before their parents.
      removed_dirs.each do |dir|
        path = File.join(latest_checkout, file)
        @log.info("svn remove #{path}")
        `svn remove #{path}`
      end      

      # Add the new ones. FIRST add any dirs.
      # These must be sorted a la find (and now they
      # are because of how added_dirs is computed).
      # NB: sort on length
      added_dirs.each do |dir|
        path = File.join(latest_checkout, dir)
        @log.info("svn add --non-recursive #{path}")
        `svn add --non-recursive #{path}`
      end      
      
      added_files.each do |file|
        path = File.join(latest_checkout, file)
        @log.info("svn add #{path}")
        `svn add #{path}`
      end      

      # Create the bomfile and schedule it for addition
      # if it does not exist.
      if not File.exists?(bomfile) then
        @log.info("touch #{bomfile}")
        `touch #{bomfile}`
        @log.info("svn add #{bomfile}")
        `svn add #{bomfile}`
      end
      # Write the bom to file
      File.open(bomfile, 'w') do |f|
        YAML.dump(bom, f)
      end


      # To identify the composition for the current build
      # we determine all files that are reachable from
      # the current bom by following the deps entry.
      pkg_name = context.item.name
      files_to_copy = collect_bom_files(latest_checkout, pkg_name)    
      dirs_to_copy = collect_bom_dirs(latest_checkout, pkg_name)    

      # Create a staging directory in the dist tree
      stage_dir = "stage_#{item.id}"
      # Use item.id to prevent overlapping stages for different
      # hosts trying to make a candidate release for the same thing.
      @log.info("svn mkdir #{my_candidates}/#{stage_dir} -m \"Stage directory for #{item}.\"")
      `svn mkdir #{my_candidates}/#{stage_dir} -m "Stage directory for #{item}."`

      # Create all subdirs in it that are needed.
      # These should be sorted a la find
      # NB: we can do this by sorting on the length.
      dirs_to_copy.each do |dir|
        @log.info("svn mkdir #{my_candidates}/#{stage_dir}/#{dir} -m \"Staging subdir #{dir} for #{item}\"")
        `svn mkdir #{my_candidates}/#{stage_dir}/#{dir} -m "Staging subdir #{dir} for #{item}"`
      end
      

      # Commit the change in latest checkout.
      # NB: this commit must be after the svn mkdirs, otherwise
      # the repository is changed and "version" is not the
      # correct one.
      msg = "Package #{item.name} Revision: #{item.version} Build: #{item.id}"
      @log.info("svn commit #{latest_checkout} -m \"#{msg}\"")
      version = `svn commit #{latest_checkout} -m "#{msg}"`.split.last[0..-2]
      
      # Copy all files to the staging directory.
      files_to_copy.each do |file|
        puts "svn copy --revision #{version} #{my_latest}/#{file} #{my_candidates}/#{stage_dir}/#{file} -m \"Copy of #{file} version #{version} from latest to staging area\"."
        `svn copy --revision #{version} #{my_latest}/#{file} #{my_candidates}/#{stage_dir}/#{file} -m "Copy of #{file} version #{version} from latest to staging area".`
      end

      # Setup release candidate directories for this package,
      # with this revision.
      ensure_svn_url("#{my_candidates}/#{item.name}/#{item.version}")
      
      # Move atomically the stage directory to a release candidate directory
      # identified by the build id.
      @log.info("svn move #{my_candidates}/#{stage_dir} #{my_candidates}/#{item.name}/#{item.version}/#{item.id} -m \"Release of #{item} from stage dir.\"")
      `svn move #{my_candidates}/#{stage_dir} #{my_candidates}/#{item.name}/#{item.version}/#{item.id} -m "Release of #{item} from stage dir."`
      
    end

    def collect_bom_files(root_dir, name)
      todo = [name]
      files = []
      while todo != [] do
        filename = bom_file_name(todo.pop)
        files << filename
        path = File.join(root_dir, filename)
        File.open(path) do |f|
          bom = YAML.load(f)
          files |= bom['files']
          todo |= bom['deps']
        end
      end
      return files
    end

    def collect_bom_dirs(root_dir, name)
      todo = [name]
      dirs = []
      while todo != [] do
        filename = bom_file_name(todo.pop)
        path = File.join(root_dir, filename)
        File.open(path) do |f|
          bom = YAML.load(f)
          dirs |= bom['dirs']
          todo |= bom['deps']
        end
      end
      return dirs
    end

    def sub_prefix(prefix, path)
      if path.match(/^#{prefix}\/(.*)$/) then
        return $1
      end
      return path
    end


    def make_binary_dists(context)
      binary_dist_dir = context.binary_dist_dir
      @log.info("creating distribution for #{@item} in #{binary_dist_dir}")
      bom = make_dists_recursively(binary_dist_dir, context)
      write_bom_to_file(bom, binary_dist_dir)
    end


    def make_source_dists(item)
      dister = SourceDister.new(item, @config.build_dir,
                                @config.source_dist_dir,
                                @config.collect_url,
                                @log)
      dister.make_source_dists
    end

    def make_source_dists2(item)
      dist = build_dist_path(item)
      @log.info("extracting #{dist}")
      `gunzip -c #{dist} | tar xf -`
      subdir = File.basename(dist, '.tar.gz')
      newdir = "#{item.name}-#{pkg_version(item)}"
      @log.info("Renaming #{subdir} to #{newdir}")
      `mv #{subdir} #{newdir}`
      @log.info("Creating #{source_dist_path(item)}")
      `tar cf - #{newdir} | gzip > #{source_dist_path(item)}`
      generate_package_file(item)
    end


    # bundling: autobundle -I . -p aterm-java-1132152437.pkg.af  -v 1132152437  -o .
    
    def build_dist_path(item)
      sub_build_dir = File.join(@config.build_dir, item.name)
      return Dir[File.join(sub_build_dir, "#{item.name}-[0-9.]*.tar.gz")][0]
    end

    # NB: configuration invariant:
    # source_dist_dir must coincide with collect_url
    # and collect_url must be world accessible over http.

    def pkg_version(item)
      # refactoring! :revision points to same revision as item!
      v = revision.checkout.extract_version
      return "#{v}pre.#{item.version}.#{item.id}"
    end

    def dist_name(item)
      return "#{item.name}-#{pkg_version(item)}.tar.gz"
    end

    def source_dist_path(item)
      return File.join(@config.source_dist_dir, dist_name(item))
    end
    
    def collect_url(item)
      return File.join(@config.collect_url, dist_name(item))
    end

    def generate_package_file(item)
      path = File.join(@config.source_dist_dir, "#{item.name}-#{pkg_version(item)}.pkg")
      File.open(path, 'w') do |f|
        f.puts('package')
        f.puts('identification')
        f.puts("name=#{item.name}")
        f.puts("version=#{pkg_version(item)}")
        f.puts("location=#{@config.collect_url}")
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

    def write_bom_to_file(bom, binary_dist_dir)
      bom_filename = File.join(binary_dist_dir, 'BOM')
      File.open(bom_filename, 'w') do |f|
        bom.each do |item|
          f.puts(item)
        end
      end
    end

    def make_dists_recursively(binary_dist_dir, context, bom = [])
      item = context.item
      if bom.include?(item) then
        @log.info("visited installation #{item}; skipping.")
        return bom
      end
      @log.info("creating distribution in #{binary_dist_dir}")    
      bom << item
      bom += make_dependency_dists(binary_dist_dir, context, bom)
      create_symlinks(context.prefix, binary_dist_dir)
      return bom
    end

    def make_dependency_dists(binary_dist_dir, context, bom)
      context.deps.each do |dep|
        @log.info("recursing for #{dep}")
        dep_context = Context.new(@config, dep.item)
        bom += make_dists_recursively(binary_dist_dir, dep_context, bom)
      end
      return bom
    end

    def create_symlinks(prefix, binary_dist_dir)
      Dir[File.join(prefix, '*')].each do |path|
        subdir = File.basename(path)
        new_path = File.join(binary_dist_dir, subdir)
        @log.info("making directory #{new_path}")
        `mkdir -p #{new_path}`
        Dir[File.join(path, '*')].each do |subpath|
          new_subpath = File.join(new_path, File.basename(subpath))
          `ln -s #{subpath} #{new_path}`
          #ln_s(subpath, new_path)
        end
      end
    end
    
    def execute_command(action, command)
      result = command_result(action, command)
      @item.add_action_result(action, command, result)
      return result
    end

    def command_result(action, command)
      # Please refactor.
      result = ActionResult.new  
      shell = Utils::EmptyShell.new
      begin
        output, errors, script = shell.read3(command, config.environment)
        result.success = true
      rescue Utils::EmptyShellFailure => e
        output = e.result.output
        errors = e.result.errors
        script = e.result.script
        result.success = false
      end
      log_all_output(revision.name, action, output, errors)
      result.output = output
      result.errors = errors
      result.environment = script
      return result
    end

    def log_all_output(package, action, output, errors)
      log_section('output', package, action, output)
      log_section('errors', package, action, errors)
    end
    
    def log_section(name, package, action, string)
      string.each_line do |line|
        @log.info("#{action}@#{package}/#{name}: #{line.chomp}")
      end
    end

  end



  class TargetFactory

    def initialize(session, config, log, dist_conf = nil)
      @session = session
      @config = config
      @log = log
      @dist_conf = dist_conf
    end

    def target(revision, dep_items)
      return Target.new(revision, dep_items, @config, @session, @log, @dist_conf)
    end

  end

end
