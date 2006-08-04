
require 'active_record'

class Project < ActiveRecord::Base
  has_many :sources
  has_many :profiles
  has_and_belongs_to_many :components
  validates_presence_of :name
  validates_uniqueness_of :name

  def components_with_sources
    return sources.collect do |source|
      source.component
    end
  end

  def roots
    return components
  end

  def sources_for_name(name)
    sources.each do |source|
      if source.name == name then
        return source
      end
    end
  end

  def sources_for_designator(designator)
    sources.each do |source|
      if source.designator == designator then
        return source
      end
    end
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

  protected


  def validate
    root_components_must_be_in_sources
    components_must_have_unique_sources
  end

  def root_components_must_be_in_sources
    cs = components_with_sources
    components.each do |component|
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
