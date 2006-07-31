require 'active_record'

class Environment < ActiveRecord::Base
  belongs_to :profile
  validates_presence_of :script
end
