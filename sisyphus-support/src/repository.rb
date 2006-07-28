require 'active_record'

class Repository < ActiveRecord::Base
  has_many :designators
end
