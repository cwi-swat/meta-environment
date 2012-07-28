require 'active_record'

class Profile < ActiveRecord::Base
  include Enumerable
  has_one :environment
  has_one :helper
  has_one :script

  has_many :targets, :order => 'id desc'

  has_and_belongs_to_many :projects
  
  validates_presence_of :name
  
  def self.find_or_create_by_name(name)
    return self.find(:first, :conditions => ['name = ?'], 
                     :order => 'version desc')
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
 
  def builds_for_host(host)
    return builds do |build|
      build.host == host
    end
  end

  def builds_for_name(name)
    return builds do |build|
      build.name == name
    end      
  end

  def builds_for_names2(names)

  end

  def builds_for_names(names)
    return builds do |build|
      names.include?(build.name)
    end
  end

  def each
    projects.each do |project|
      yield project
    end
  end

  def sources
    return reduce_projects do |project|
      project.sources
    end
  end

  def repositories
    return reduce_projects do |project|
      project.repositories
    end
  end

  def changes_since_session(session)
    result = []
    repositories.each do |repository|
      result += repository.changes_since_session(session)
    end
    return result
  end

  def changes_between_sessions(session1, session2)
    result = []
    repositories.each do |repository|
      result += repository.changes_between_sessions(session1, session2)
    end
    return result
  end
    

  def actions
    return script.actions
  end

  def function(name)
    return helper.function(name)
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

  def to_s
    return "#{name}@#{version}"
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

  private

  def builds
    result = []
    targets.each do |target|
      target.builds.each do |build|
        if yield build then
          result << build
        end
      end
    end
    return result.uniq.compact
  end


end
