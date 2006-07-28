require 'active_record'

class Profile < ActiveRecord::Base
  has_and_belongs_to_many :repository
  belongs_to :environment
  has_many :action
end
