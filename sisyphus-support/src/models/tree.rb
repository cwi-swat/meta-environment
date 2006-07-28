require 'active_record'

class Tree < ActiveRecord::Base
  belongs_to :designator
end
