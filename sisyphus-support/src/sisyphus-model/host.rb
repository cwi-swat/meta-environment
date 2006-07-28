require 'active_record'

class Host < ActiveRecord::Base
  belongs_to :platform
  validates_presence_of :name
  validates_uniqueness_of :name
end

