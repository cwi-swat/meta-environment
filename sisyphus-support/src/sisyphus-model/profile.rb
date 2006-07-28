require 'active_record'

class Profile < ActiveRecord::Base
  has_many :sources
  has_many :roots

  has_many :repositories, :through => :sources
  has_many :components, :through => :roots

  has_one :environment
  has_many :actions

  validates_presence_of :name
  validates_uniqueness_of :name

end
