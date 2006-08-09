require 'active_record'

class Build < ActiveRecord::Base
  belongs_to :profile
  belongs_to :session
  has_one :release
  has_many :results
  has_and_belongs_to_many :targets
  has_and_belongs_to_many :dependencies,
  :class_name => 'Build',
  :join_table => 'dependencies',
  :foreign_key => 'build_id',
  :association_foreign_key => 'dependency_id'

  def time
    return session.time
  end

  def name
    return targets.first.name
  end

  def revision
    return targets.first.revision
  end

  def component
    return targets.first.component
  end

  def designator
    return targets.first.designator
  end

  def tree
    return targets.first.tree
  end


  def version
    if release then
      return release.version
    end
    return nil
  end

  def requires
    return dependencies.collect do |dep|
      dep.name
    end
  end

  def extent
    result = [self]
    dependencies.each do |dep|
      result |= dep.extent
    end
    return extent
  end
  
  def platform
    return host.platform
  end


  def ==(o)
    return target == o.target &&
      session == o.session &&
      release == o.release &&
      id == o.id
  end

  def <=>(o)
    return session <=> o.session
  end

  def to_s
    return "#{target}@#{session}"
  end

  protected

  def validate
    result_actions_must_be_profile_actions
    extent_must_be_homogeneous
    extent_must_be_single_hosted
    targets_must_be_equal_modulo_project
  end

  def result_actions_must_be_profile_actions
    result_actions = results.collect do |result|
      result.action
    end
    result_actions.each do |action|
      if not profile.actions.include?(action) then
        errors.add('results', "Action #{action} is a result action but not declared in profile.")
      end
    end
  end

  def homogeneous?(set)
    names = set.collect do |build|
      build.name
    end
    return names.uniq.length == set.length
  end

  def extent_must_be_homogeneous
    return homogeneous?(extent)
  end

  def extent_must_be_single_hosted
    hosts = extent.collect do |build|
      build.host
    end
    return hosts.legnth == 1
  end

  def targets_must_be_equal_modulo_project
    targets.each do |t1|
      targets.each do |t2|
        if not t1.equal_modulo_project(t2) then
          return false
        end
      end
    end
    return true
  end

end
