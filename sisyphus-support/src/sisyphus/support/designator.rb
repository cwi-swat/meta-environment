require 'active_record'

class Designator < ActiveRecord::Base
  belongs_to :repository
  has_many :trees
  validates_presence_of :path

  def tree(revision_or_time)
    return repository.tree(self, revision_or_time)
  end
  
  def location 
    return repository.location
  end

  def full_path
    return File.join(location, path)
  end

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

  def to_s
    return full_path
  end


end
