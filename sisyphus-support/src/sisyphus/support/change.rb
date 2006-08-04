

require 'active_record'

class Change < ActiveRecord::Base
  belongs_to :designator
  belongs_to :session
  validates_presence_of :path
end
