
class SiMessage < ActiveRecord::Base
  # fields: line, created_on 
  belongs_to :si_host
  belongs_to :si_session
end

