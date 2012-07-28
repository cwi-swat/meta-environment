
class SiConfig < ActiveRecord::Base
  # fields: sources_version, script_version
  belongs_to :si_profile
  has_many :si_items
end

