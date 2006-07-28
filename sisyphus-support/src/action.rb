require 'active_record'

class Action < ActiveRecord::Base
  belongs_to :profile
end

