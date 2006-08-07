require 'active_record'

class Designator < ActiveRecord::Base
  belongs_to :repository
  has_many :trees
  validates_presence_of :path

  def ==(o)
    repository == o.repository &&
      path == o.path
  end  

  def <=>(o)
    order = repository <=> o.repository
    if order == 0 then
      order = path <=> o.path
    end
    return order
  end

end
