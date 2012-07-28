class SiSession < ActiveRecord::Base
  # fields: time
  has_many :si_items  
end

