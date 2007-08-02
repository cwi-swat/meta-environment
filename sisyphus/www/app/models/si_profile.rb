
class SiProfile < ActiveRecord::Base
  # fields: name, version
  has_many :si_config
end

