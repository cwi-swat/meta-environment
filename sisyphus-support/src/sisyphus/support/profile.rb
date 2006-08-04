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

  def designation(tree)
    # this works because of the constraints on project/profile
    project_sources.each do |source|
      if tree.designator == source.designator then
        return source.component
      end
    end
    raise "Consistency error: #{tree} has no designation in #{self}!"
  end

  def project_sources
    result = []
    projects.each do |project|
      result += project.sources
    end
    return result
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
