require 'active_record'

class Host < ActiveRecord::Base
  has_many :sessions
  belongs_to :platform
  validates_presence_of :name

  def self.current
    name = `uname -n`.chomp
    platform = Platform.current
    return find_or_create_by_name_and_platform(:name => name, :platform => platform)
  end


  def ==(o)
    return name == o.name &&
      platform == o.platform
  end

  def <=>(o)
    return name <=> o.name
  end

  def to_s
    return name
  end


end

