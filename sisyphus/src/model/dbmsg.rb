
module Model

  require 'active_record'

  class SiMessage < ActiveRecord::Base
    # fields: line, created_on 
    belongs_to :si_host
    belongs_to :si_session
  end

end
