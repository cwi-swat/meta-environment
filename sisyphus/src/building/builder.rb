module Building

  require 'model/db'


  class SuccessCursor
    def initialize(store, target)
      @store = store
      @target = target
      @max = max
      @cursor = @max
      @current = nil
    end

    def max(below_id = nil)        
      h, c, r = @store.host_config_revision(@target.host, 
                                            @target.config, 
                                            @target.revision)
      query = "select max(id) from si_items where success = 't' and si_host_id = #{h.id} and si_config_id = #{c.id}"
      if below_id then
        query += " and id < #{below_id}"
      end
      puts "Query: #{query}"
      m = Model::SiItem.count_by_sql(query)
      puts "MAX: m = #{m}"      
      return m
    end

    def restart
      @cursor = max(@cursor)
    end
    
    def next
      item = nil
      puts "current = #{@current.inspect}, max = #{@max}"
      if @max == 0 then # means: no successful builds at all        
        return nil
      end
      if not @current then
        item = Model::SiItem.find(@max)
        if item.nil? then
          return nil
        end
      else
        m = max(@current)
        if m == 0 then
          return nil
        end
        item = Model::SiItem.find(m)
      end
      @current = item.id
      return item
    end
  end


  class Builder
    def initialize(store, forced, config, backtracking, log)
      @store = store
      @forced = forced
      @config = config
      @backtracking = backtracking
      @log = log
    end

    def build(target)
      if @backtracking then
        build_using_backtracking(target)
        return target.item
      end
      @log.info("checking if #{target} needs a build")
      if not requires_build?(target) then
        @log.info("revision #{target} needs no build")
        return @store.last_item_for_target(target)
      end
      @log.info("it needs one...")
      item = new_build_for_target_if_not_released(target)
      garbage_collect_older_items_if_success(item)
      return item
    end

    def garbage_collect_older_items_if_success(item)
      # Clean earlier build of the same revision with prefixes items here 
      # if the build was successful (Garbage collect):
      if not item.success? then
        return
      end

      query =<<EOQ
select si_items.* from si_items, si_revisions 
where 
   si_items.id < #{item.id} and
   si_items.si_revision_id = si_revisions.id and
   si_items.si_host_id = #{item.si_host.id} and
   si_revisions.si_component_id = #{item.si_revision.si_component.id}  
EOQ
      stale_items = Model::SiItem.find_by_sql(query)
      stale_items.each do |stale_item|
        prefix = stale_item.prefix(@config.install_dir)
        if File.exist?(prefix) then
          @log.info("deleting stale build #{stale_item} at #{prefix}")
          @log.info("executing: rm -rf #{prefix}")
          system("rm -rf #{prefix}")
        end       
      end
    end

    def delete_stale_build_item_if_any(target)
      item = @store.last_item_for_target(target)
      if not item.nil? and item.in_progress? then
        remove_stale_build_items(item)        
      end
    end

    def remove_stale_build_items(item)
      Model::SiItem.transaction do 
        item.si_deps = []
        item.save
        item.si_results.each do |res|
          Model::SiResult.destroy(res.id)
        end
        item.save
        Model::SiItem.destroy(item.id)
      end
    end

    def requires_build?(target)
      #if `uname -n`.chomp == 'verfrol.sen.cwi.nl' then
      #  return true
      #end

      ## ALWAYS remove stale buiild items.
      item = @store.last_item_for_target(target)
      if not item.nil? and item.in_progress? then
        @log.info("cleaning up stale build item: #{item}")
        remove_stale_build_items(item)
        return requires_build?(target)
      end

      if @forced.include?(target.name) then
        return true
      end

      if not @store.has_item_for_target?(target) then
        return true
      end

      if target.deps_have_changed? then
        return true
      end

     
      return false
    end
    
    def new_build_for_target_if_not_released(target)
      component = target.revision.component
      version = target.revision.checkout.extract_version
      @log.info("**************##### Package: #{component}-#{version}")
      if @store.has_release_for_package_version(component, version) then
        @log.warn("Package #{component} has been released already as version #{version}!")      
        #item = @store.item_for_target(target, target.dep_items)
        #item.set_success(false)
        #item.set_progress(false)
        #item.save
        #return item
        #else
      end
      item = target.obtain_item(@store)
      build_target(target, item)
      target.save(@store)
      return target.item
    end

    def compatible?(deps1, deps2)
      names1 = deps1.collect { |d| d.name }
      names2 = deps2.collect { |d| d.name }
      return names1.sort == names2.sort
    end

    def prefixes_still_exist?(dep_items)
      dep_items.each do |item|
        prefix = item.prefix(@config.install_dir)
        if not File.exist?(prefix) then
          @log.info("found no prefix for #{item} at #{prefix}")
          return false
        end       
      end
      return true
    end

    def simple_backtracking(target, item)
      @log.info("dependencies in this session have failed, trying older ones...")
      older_item = Model::SiItem.find(:first, :conditions => ['id < ? and success = \'t\' and si_revision_id = ? and si_host_id = ?', item.id, item.si_revision.id, item.si_host.id], :order => 'id desc')
      
      if older_item then
        if compatible?(older_item.dep_items, item.dep_items) then
          @log.info("found older build with compatible dependencies #{older_item.dep_items.join(', ')}")
          if prefixes_still_exist?(older_item.dep_items)
            target.item.si_deps = []
            target.item.save
            older_item.dep_items.each do |i|
              target.item.si_deps << i
            end
            target.item.save
            #target.item.si_deps = older_item.dep_items
            #target.obtain_new_item(@store, older_item.dep_items)
            target.fire
            return
          else
            @log.warn("But not all prefixes are still there...")
          end
        else
          @log.warn("no suitable dependencies were found; no build performed.")
        end
      else
        @log.warn("no earlier build of the same revision exists.")
      end
      target.not_tried
    end


    def workingset(components, success)
      if components.empty? then
        return [], []
      end
      loop do
        current = []
        todo = components.clone
        while !todo.empty? do
          @log.info("todo = #{todo.inspect}")
          build = success.next
          @log.info("build = #{build}")
          return nil if build.nil?
          component = build.si_revision.si_component.name
          @log.info("component = #{component.inspect}")
          if todo.include?(component) then
            current |= [build]
            todo -= [component]
          end
        end
        closure = pure_workingset?(current)
        if closure then
          return current, closure
        end
        success.restart
      end
    end



    def pure_workingset?(w)
      components = []
      items = []
      @log.info("checking for purity")
      w.each do |item|
        @log.info("getting closure of #{item}")
        clos = item.closure
        @log.info("it is: #{clos.join(', ')}")
        items += clos
        components += clos.collect do |item|
          item.si_revision.si_component
        end
      end
      total = items.uniq
      if components.uniq.length == total.length then
        return total
      else
        return nil
      end
    end

    def build_using_backtracking(target)
      @log.info("Target: \"#{target}\"")
      success = SuccessCursor.new(@store, target)
      revision = target.revision
      @config.build_env_packages.each do |implicit_dep|
        if implicit_dep == revision.name then
          # if revision is an implicit_dep itself
          # add only implicit deps "until" revision.name
          break
        end
        revision.add_dep(Versioning::Component.new(implicit_dep))
      end
      dep_names = revision.deps.collect {|x| x.name }
      @log.info("depnames: #{dep_names.inspect}")
      ws, closure = workingset(dep_names, success)
      if ws then
        @log.info("WS = #{ws.join(', ')}")
        @log.info("CLOSURE = #{closure.join(', ')}")
        @log.info("ws != nil")
        if @store.has_item_for_target?(target) then
          @log.info("store has item for #{target}")
          if closure.sort == @store.last_item_for_target(target).trans_closure.sort then
            @log.info("closure == last_item_for_target.closure")
            @log.info("don't build because the build is the same.")
            @log.info("but it may be forced...")
            if @forced.include?(target.name) then
              @log.info("yes it is forced, so build it anyway.")
              build_target_using_workingset(target, ws)
            end
          else
            @log.info("closures are different.")
            build_target_using_workingset(target, ws)
          end
        else
          @log.info("no item in db for #{target}; so build it.")
          build_target_using_workingset(target, ws)
        end
      end
    end

    def build_target_using_workingset(target, w)
      target.item = @store.item_for_target(target, w)
      target.dep_items = w
      if prefixes_still_exist?(w)
        @log.info("prefixes for #{w.join(', ')} still exist...")
        @log.info("firing target #{target}.")
        target.fire
        @log.info("Target has fired: #{target.item}")
        garbage_collect_older_items_if_success(target.item)
      else
        @log.info("target #{target} not tried")
        target.not_tried
      end
    end
    
    def build_target(target, item)
      if target.deps_are_successful? then
        target.fire
      else
        simple_backtracking(target, item)
      end
    end


  end
  
end
