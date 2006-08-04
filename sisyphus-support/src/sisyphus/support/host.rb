require 'active_record'

class Host < ActiveRecord::Base
  has_many :sessions
  belongs_to :platform
  validates_presence_of :name

  def self.find_by_name_and_platform(name, platform)
    h = Host.find(:first, :conditions => ['name = ? and platform_id = ?', name, platform])
    if not h then
      h = Host.new(:name => name, :platform => platform)
      h.save
    end
    return h
  end

end

