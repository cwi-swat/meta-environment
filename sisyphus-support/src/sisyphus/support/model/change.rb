

require 'active_record'

class Change < ActiveRecord::Base
  belongs_to :designator
  belongs_to :session
  validates_presence_of :path

  def ==(o)
    return designator == o.designator &&
      session == o.session &&
      path = o.path
  end

  def <=>(o)
    order = designator <=> o.designator
    if order == 0 then
      order = path <=> o.path
    end
    return order
  end


end
