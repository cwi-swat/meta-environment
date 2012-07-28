
require 'active_record'

class Platform < ActiveRecord::Base
  has_many :hosts

  validates_presence_of :kernel_name, 
  :kernel_release, 
  :hardware_platform, 
  :hardware_class, 
  :processor_type
  
  def self.uname(option)
    elt = `uname -#{opt}`.chomp
    return elt.tr(', #', '_')
  end
  

  def self.current
    kernel_name = uname('s')
    kernel_release = uname('r')
    hardware_platform = uname('i')
    hardware_class = uname('m')
    processor_type = uname('p')
    return find_by_uname_elements(kernel_name, kernel_release, hardware_platform,
                                  hardware_class, processor_type)
  end

  
  def self.find_by_uname(kernel_name, kernel_release, hardware_platform, 
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


  def <=>(o)
    return kernel_name <=> o.kernel_name
  end
  

  def to_s
    return to_path
  end


  def to_path
    list = as_tuple
    result = list.first
    return list[1..-1].inject(result) do |path, element|
      File.join(path, element)
    end
  end

  private

  def as_tuple
    return [kernel_name, kernel_release, hardware_platform, hardware_class, processor_type]
  end

end
