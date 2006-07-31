require 'active_record'

class Repository < ActiveRecord::Base
  has_many :designators
  validates_presence_of :location
  validates_uniqueness_of :location

  def self.find_by_location(location)
    r = Repository.find(:first, :condition => ['location = ?', location])
    if not r then
      r = Repository.new(:location => location)
      r.save
    end
    return r
  end

end
