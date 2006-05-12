
class Builder
  def initialize(store, log)
    @store = store
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
    SiItem.transaction do 
      item.si_deps = []
      item.save
      item.si_results.each do |res|
        SiResult.destroy(res.id)
      end
      item.save
      SiItem.destroy(item.id)
    end
  end

  def requires_build?(target)
    if `uname -n`.chomp == 'batatrom.sen.cwi.nl' then
      @log.warn("PACKAGES ARE ALWAYS BUILT!!! FIX BEFORE RELEASE!")
      return true
    end

    if not @store.has_item_for_target?(target) then
      return true
    end

    if target.deps_have_changed? then
      return true
    end

    item = @store.last_item_for_target(target)
    if not item.nil? and item.in_progress? then
      @log.info("cleaning up stale buid item: #{item}")
      remove_stale_build_items(item)
      return requires_build?(target)
    end
      
    return false
  end
  
  def new_build_for_target_if_not_released(target)
    component = target.revision.component
    version = target.revision.checkout.extract_version
    @log.info("**************##### Package: #{component}-#{version}")
    if @store.has_release_for_package_version(component, version) then
      @log.warn("Package #{component} has been released already as version #{version}!")      
      item = @store.item_for_target(target, target.dep_items)
      item.set_success(false)
      item.set_progress(false)
      item.save
    else
      target.obtain_item(@store)
      build_target(target)
      target.save(@store)
      return target.item
    end
  end

  def build_target(target)
    if target.deps_are_successful? then
      target.fire
    else
      target.not_tried
      @log.warn("there were failed dependencies; no build performed.")
    end
  end
end

