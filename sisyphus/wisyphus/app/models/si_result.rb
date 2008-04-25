
class SiResult < ActiveRecord::Base
  # fields: action, command, output, success
  belongs_to :si_item
  

end

