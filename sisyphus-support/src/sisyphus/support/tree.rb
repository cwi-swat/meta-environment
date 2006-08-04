require 'active_record'

class Tree < ActiveRecord::Base
  belongs_to :designator
  validates_presence_of :revision

  def self.find_by_designator_and_revision(designator, revision)
    t = Tree.find(:first, :conditions => ['designator_id = ? and revision = ?',
                                         designator, revision])
    if not t then
      t = Tree.new(:designator => designator, :revision => revision)
      t.save
    end
    return t
  end
  
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
