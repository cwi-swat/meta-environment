require 'active_record'

class Host < ActiveRecord::Base
  belongs_to :platform
  validates_presence_of :name
  validates_uniqueness_of :name

  def self.find_by_name(name)
    h = Host.find(:first, :conditions => ['name = ?', name])
    if not h then
      h = Host.new(:name => name)
      h.save
    end
    return h
  end

end

