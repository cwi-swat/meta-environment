

require 'active_record'

class Latest < ActiveRecord::Base
  # Read only!

  belongs_to :component
  belongs_to :build
  
end
