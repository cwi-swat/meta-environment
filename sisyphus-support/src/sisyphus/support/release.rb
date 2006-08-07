
require 'active_record'

class Release < ActiveRecord::Base
  belongs_to :build
  validates_presence_of :version

  def to_s
    return "#{build}~#{version}"
  end

end
