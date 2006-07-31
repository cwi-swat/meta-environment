
require 'active_record'

class Root < ActiveRecord::Base
  belongs_to :project
  belongs_to :component
end

