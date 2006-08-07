require 'active_record'

class Result < ActiveRecord::Base
  belongs_to :build
  belongs_to :action
  validates_presence_of :success

  def to_s
    return "#{action}@#{build}: #{success}"
  end

end

