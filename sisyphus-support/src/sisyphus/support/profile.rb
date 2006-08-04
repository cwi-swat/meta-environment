require 'active_record'

class Profile < ActiveRecord::Base
  has_one :environment
  has_one :helper
  has_one :script

  has_and_belongs_to_many :projects
  
  validates_presence_of :name
  validates_uniqueness_of :name

  def self.find_by_name(name)
    p = Profile.find(:first, :condition => ['name = ?', name], :order => 'version desc')
    if not p then
      p = Profile.new(:name => name)
    end
    return p
  end

  def designator(component)
    sources.each do |source|
      if source.component == component then
        return source.designator
      end
    end
    raise "Consistency error: #{component} has no designation in #{self}!"
  end

  def roots
    return reduce_projects do |project|
      project.components
    end
  end

  def sources
    return reduce_projects do |project|
      project.sources
    end
  end


  def ==(o)
    return name == o.name && 
      environment == o.environment &&
      helper == o.helper &&
      script == o.script
  end

  def <=>(o)
    return name <=> o.name
  end


  protected

  def reduce_projects
    result = []
    projects.each do |project|
      result += yield project
    end
    return result.uniq
  end

  def validate
    components_must_have_unique_sources_across_projects
  end
    
  def components_must_have_unique_sources_across_projects
    cs = project_sources
    set = cs.uniq
    diff = cs - set
    if not diff.empty? then
      diff.each do |component|
        errors.add('projects', "component #{component} has different sources across projects")
      end
    end
  end  

end
