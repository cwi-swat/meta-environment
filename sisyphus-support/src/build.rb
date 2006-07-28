require 'active_record'

class Build < ActiveRecord::Base
  belongs_to :tree
  belongs_to :host
  belongs_to :profile
  has_many :results
  has_and_belongs_to_many :dependencies,
  :class_name => 'Build',
  :join_table => 'dependencies',
  :foreign_key => 'build_id',
  :association_foreign_key => 'dep_id'
end
