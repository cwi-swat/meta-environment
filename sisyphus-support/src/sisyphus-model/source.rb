
require 'active_record'

class Source < ActiveRecord::Base
  belongs_to :profile
  belongs_to :repository
end
