require 'active_record'

class Helper < ActiveRecord::Base
  belongs_to :profile
  belongs_to :variable
  acts_as_list :scope => :profile
  validates_presence_of :name, :template
end

