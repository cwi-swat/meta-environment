require 'active_record'

class Build < ActiveRecord::Base
  belongs_to :target
  belongs_to :session

  has_many :results
  has_and_belongs_to_many :dependencies,
  :classname => 'Build',
  :join_table => 'dependencies',
  :foreign_key => 'build_id'
  :assocation_foreign-key => 'dependency_id'


  validates_presence_of :time

  def name
    return target.name
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

  protected

  def validate
    result_actions_must_be_profile_actions
    extent_must_be_homogeneous
    extent_must_be_single_hosted
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


end
