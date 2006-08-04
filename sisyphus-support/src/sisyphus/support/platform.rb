
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
    p = Platform.find(:first, :conditions => ['kernel_name = ? and kernel_release = ? and hardware_platform = ? and hardware_class = ? and processor_type = ?', 
                                              kernel_name, kernel_release, hardware_platform, 
                                              hardware_class, processor_type])
    if not p then
      p = Platform.new(:kernel_name => kernel_name, :kernel_release => kernel_release, 
                       :hardware_platform => hardware_platform, :hardware_class => hardware_class,
                       :processor_type => processor_type)
      p.save
      return p
    end
  end

  def ==(o)
    return kernel_name == o.kernel_name &&
      kernel_release == o.kernel_release &&
      hardware_platform == o.hardware_platform &&
      hardware_class == o.hardware_class &&
      processor_type == o.processor_type
  end
  
end
