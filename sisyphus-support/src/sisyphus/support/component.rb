require 'active_record'

class Component < ActiveRecord::Base
  has_many :sources

  validates_presence_of :name
  validates_uniqueness_of :name


end
