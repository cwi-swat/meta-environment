
require 'active_record'

class Integration < ActiveRecord::Base
  belongs_to :build
  belongs_to :dependency, :class_name => 'Build'
end
