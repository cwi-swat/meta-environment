
require 'target'
require 'empty-shell'






class SimpleItem
  attr_reader :dep_items, :revision

  def initialize(revision, dep_items)
    @revision = revision
    @dep_items = dep_items
    @success = false
  end

  def set_success(bool)
    @success = bool
  end

  def set_progress(bool)
    @in_progress = bool
  end

  def add_action_result(action, command, result)
    
  end
end

# Refactor this class hierarchy: LocalTarget < Target, CITarget < Target

class LocalTarget < Target
  def obtain_item(store)
    @item = SimpleItem.new(@revision, @dep_items)
  end

  def save(store)
  end
end

class LocalTargetFactory < TargetFactory
  def target(checkout, dep_items)
    return LocalTarget.new(checkout, dep_items, @config, @session, @log)
  end
end
