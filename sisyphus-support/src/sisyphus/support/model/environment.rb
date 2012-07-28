require 'active_record'

class Environment < ActiveRecord::Base
  belongs_to :profile
  validates_presence_of :script

  def to_s
    return script
  end
end
