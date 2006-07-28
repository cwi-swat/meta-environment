require 'active_record'

class Tree < ActiveRecord::Base
  belongs_to :designator
  validates_presence_of :revision
end
