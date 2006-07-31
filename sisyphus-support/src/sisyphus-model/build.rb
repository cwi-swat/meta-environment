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

end
