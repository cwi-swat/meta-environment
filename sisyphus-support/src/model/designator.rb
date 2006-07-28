require 'active_record'

class Designator < ActiveRecord::Base
  belongs_to :repository
  belongs_to :component
end
