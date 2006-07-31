
require 'active_record'

class Platform < ActiveRecord::Base
  validates_presence_of 
  :kernel_name, 
  :kernel_release, 
  :hardware_platform, 
  :hardware_class, 
  :processor_type
  
end
