
require 'active_record'

class Variable < ActiveRecord::Base
  has_many :functions
  validates_presence_of :name

  def to_s
    return name
  end
end
