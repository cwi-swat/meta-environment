require 'active_record'

class Profile < ActiveRecord::Base
  has_one :environment
  has_many :actions

  has_and_belongs_to_many :projects
  
  validates_presence_of :name
  validates_uniqueness_of :name

  def self.find_by_name(name)
    p = Profile.find(:first, :condition => ['name = ?', name], :order => 'version desc')
    if not p then
      p = Profile.new(:name => name)
    end
    return p
  end
      

end
