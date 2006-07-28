
require 'active_record'

class Root < ActiveRecord::Base
  belongs_to :profile
  belongs_to :component
end

