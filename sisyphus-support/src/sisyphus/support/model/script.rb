
require 'active_record'

class Script < ActiveRecord::Base
  has_an_belongs_to_many :profiles
  has_many :actions
end
