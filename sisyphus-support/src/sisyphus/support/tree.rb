require 'active_record'

class Tree < ActiveRecord::Base
  belongs_to :designator
  has_many :targets
  validates_presence_of :revision

  def repository
    return designator.repository
  end

  def path
    return designator.path
  end

  def to_s
    return "<#{designator}, #{revision}>"
  end

  def ==(o)
    return designator == o.designator &&
      revision == o.revision
  end

  def <=>(o)
    order = designator <=> o.designator
    if order == 0 then
      order = revision <=> o.revision
    end
    return order
  end


end
