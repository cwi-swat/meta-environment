
require 'active_record'

class SiLog < ActiveRecord::Base
  # fields: line, created_on 
  belongs_to :si_host
end


