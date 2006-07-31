require 'active_record'

class Result < ActiveRecord::Base
  belongs_to :build
  belongs_to :action
  validates_presence_of :success
end

