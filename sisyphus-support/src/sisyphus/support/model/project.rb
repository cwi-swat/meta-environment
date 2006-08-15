
require 'active_record'

class Project < ActiveRecord::Base
  has_many :sources
  has_many :profiles
  has_and_belongs_to_many :roots, :join_table =>, 'project_roots', :class_name => 'Component'
  validates_presence_of :name
  validates_uniqueness_of :name

  def components_with_sources
    return sources.collect do |source|
      source.component
    end
  end

  def target_for_component(component, time)
    target = Target.find_or_create_by_component_and_source_and_tree(component, 
                                                                    source_for_component(component),
                                                                    tree_for_component(component, time))
    return target
  end

  def tree_for_component(component, time)
    return source_for_component(component).tree(time)
  end

  def trees_for_components(components, time)
    return components.collect do |component|
      tree_for_component(component, time)
    end
  end

  def trees_for_root_components(time)
    return trees_for_components(roots)
  end

  def source_for_name(name)
    sources.each do |source|
      if source.name == name then
        return source
      end
    end
    raise "Inconsistency: no source found for #{name}"
  end

  def source_for_designator(designator)
    sources.each do |source|
      if source.designator == designator then
        return source
      end
    end
    raise "Inconsistency: no source found for #{designator}"
  end

  def source_for_component(component)
    sources.each do |source|
      if source.component == component then
        return source
      end
    end
    raise "Inconsistency: no source found for #{component}"
  end

  def repositories
    sources.collect do |source|
      source.repostory
    end.uniq
  end

  def designators
    sources.collect do |source|
      source.designator
    end
  end

  def to_s
    return name
  end

  def <=>(o)
    return name <=> o.name
  end

  protected


  def validate
    root_components_must_be_in_sources
    components_must_have_unique_sources
  end

  def root_components_must_be_in_sources
    cs = components_with_sources
    roots.each do |component|
      if not cs.include?(component) then
        errors.add('sources', "root component #{component} has no source")
      end
    end
  end
  
  def components_must_have_unique_sources
    cs = components_with_sources
    set = cs.uniq
    diff = cs - set
    if not diff.empty? then
      diff.each do |component|
        errors.add('sources', "component #{component} has duplicate sources")
      end
    end
  end
    
end
