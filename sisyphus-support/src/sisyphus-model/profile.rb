require 'active_record'

class Profile < ActiveRecord::Base
  has_and_belongs_to_many :repository
  has_and_belongs_to_many :component # roots
  belongs_to :environment
  has_many :actions

  validates_presence_of :name
  validates_uniqueness_of :name

end
