
require 'active_record'

class Project < ActiveRecord::Base
  has_many :sources
  has_many :profiles
  has_and_belongs_to_many :components
  validates_presence_of :name
  validates_uniqueness_of :name

end
