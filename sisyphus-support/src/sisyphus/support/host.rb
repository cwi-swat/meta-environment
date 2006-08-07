require 'active_record'

class Host < ActiveRecord::Base
  has_many :sessions
  belongs_to :platform
  validates_presence_of :name

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

