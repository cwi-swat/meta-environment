require 'active_record'

class Build < ActiveRecord::Base
  belongs_to :tree
  belongs_to :host
  belongs_to :profile
  has_many :results
  has_and_belongs_to_many :dependencies,
  :classname => 'Build',
  :join_table => 'dependencies',
  :foreign_key => 'build_id'
  :assocation_foreign-key => 'dependency_id'


  validates_presence_of :time

  def self.find_by_tree_and_host_and_profile(tree, host, profile)
    b = Build.find(:first, :conditions => ['tree_id = ? and host_id = ? and profile_id = ?',
                                           tree, host, profile])
    if not b then
      b = Build.new(:tree => tree, :host => host, :profile => profile)
      b.save
    end
    return b
  end

  def name
    return profile.designation(tree)
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
    extent_must_be_homogenous
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

  def homogenous?(set)
    names = set.collect do |build|
      build.name
    end
    return names.uniq.length == set.length
  end

  def extent_must_be_homogenous
    return homogenous?(extent)
  end

  def extent_must_be_single_hosted
    hosts = extent.collect do |build|
      build.host
    end
    return hosts.legnth == 1
  end


end
