require 'active_record'

class Component < ActiveRecord::Base
  has_many :sources

  validates_presence_of :name
  validates_uniqueness_of :name

  def self.find_by_name(name)
    c = Component.find(:first, :condition => ['name = ?', name])
    if not c then
      c = Component.new(:name => name)
      c.save
    end
    return c
  end

end
