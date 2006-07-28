require 'active_record'

class Action < ActiveRecord::Base
  belongs_to :profile
  acts_as_list :scope => :profile
  validates_presence_of :name, :template
end

