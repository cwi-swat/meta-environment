module Building

  require 'model/db'

  class Builder
    def initialize(store, forced, config, log)
      @store = store
      @forced = forced
      @config = config
      @log = log
    end

    def build(target)
      @log.info("checking if #{target} needs a build")
      if not requires_build?(target) then
        @log.info("revision #{target} needs no build")
        return @store.last_item_for_target(target)
      end
      @log.info("it needs one...")
      
      return new_build_for_target_if_not_released(target)
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

    def build_target(target, item)
      if target.deps_are_successful? then
        target.fire
      else
        @log.info("dependencies in this session have failed, trying older ones...")
        older_item = Model::SiItem.find(:first, :conditions => ["id < ? and success = 'true' and si_revision_id = ? and si_host_id = ?",
                                                                item.id, item.si_revision.id, item.si_host.id],
                                        :order => 'id desc')
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
            end
            @log.warn("But not all prefixes are still there...")
          end
        end
        @log.warn("no suitable dependencies were found; no build performed.")
        target.not_tried
      end
    end
  end

end
