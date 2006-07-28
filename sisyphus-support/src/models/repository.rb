require 'active_record'

class Repository < ActiveRecord::Base
  has_many :designators
  validates_presence_of :location
  validates_uniqueness_of :location
end
