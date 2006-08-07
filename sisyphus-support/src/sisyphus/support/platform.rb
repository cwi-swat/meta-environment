
require 'active_record'

class Platform < ActiveRecord::Base
  has_many :hosts

  validates_presence_of 
  :kernel_name, 
  :kernel_release, 
  :hardware_platform, 
  :hardware_class, 
  :processor_type

  def self.find_by_uname_elements(kernel_name, kernel_release, hardware_platform, 
                             hardware_class, processor_type)
    
    p = Platform.find_or_create_by_kernel_name_and_kernel_release_and_hardware_platform_and_hardware_class_and_processor(kernel_name, kernel_release, hardware_platform, hardware_class, processor_type)
    p.save
    return p
  end

  def ==(o)
    return kernel_name == o.kernel_name &&
      kernel_release == o.kernel_release &&
      hardware_platform == o.hardware_platform &&
      hardware_class == o.hardware_class &&
      processor_type == o.processor_type
  end
  
end
