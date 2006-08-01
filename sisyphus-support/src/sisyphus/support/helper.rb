require 'active_record'

class Helper < ActiveRecord::Base
  has_and_belongs_to_many :profiles
end

