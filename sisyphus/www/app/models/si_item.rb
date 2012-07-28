
class SiItem < ActiveRecord::Base
  # fields: success, progress
  belongs_to :si_host
  belongs_to :si_revision
  belongs_to :si_config
  belongs_to :si_session
  has_many :si_results
  has_and_belongs_to_many :si_deps, 
  :class_name => 'SiItem',
  :join_table => 'si_item_deps',
  :foreign_key => 'si_item_id',
  :association_foreign_key => 'si_dep_id'   

  def not_tried?
    !self.success && si_results.length == 0
  end


  def informative_version
    return si_revision.informative_version.strip
  end

  def targz_version
    return "#{informative_version}pre.#{version}.#{id}"
  end

  def targz
    return "#{name}-#{targz_version}.tar.gz"
  end

  def bundle_targz
    return "#{name}-bundle-#{targz_version}.tar.gz"
  end

  def name
    return si_revision.name
  end

  def version
    return si_revision.version
  end

  def in_progress?
    self.progress == true
  end

  def each_dep
    si_deps.each do |d|
      yield d
    end
  end

  def as_nodes
    yield self
    each_dep do |dep|
      dep.as_nodes do |n|
        yield n
      end
    end
  end

  def nodes
    result = []
    as_nodes do |node|
      result << node
    end
    return result.uniq
  end
  
  def as_edges
    each_dep do |dep|
      yield self, dep
      dep.as_edges do |n1, n2|
        yield n1, n2
      end
    end
  end

  def edges
    result = []
    as_edges do |n1, n2|
      result << [n1, n2]
    end
    return result.uniq
  end
  
  
end

