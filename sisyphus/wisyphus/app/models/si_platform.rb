
class SiPlatform < ActiveRecord::Base
  # Fields:
  # kernel_name
  # kernel_release
  # hardware_platform
  # hardware_class
  # processor_type
  has_many :si_hosts
end
