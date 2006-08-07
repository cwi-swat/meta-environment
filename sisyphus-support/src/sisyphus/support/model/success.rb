
require 'active_record'

class Success < ActiveRecord::Base
  # Readonly!

  belongs_to :host
  belongs_to :profile
  belongs_to :build

  # Fields:
  # - name
  # - revision
  # - version
  
 

end

