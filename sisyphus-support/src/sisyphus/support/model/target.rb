
require 'active_record'

class Target < ActiveRecord::Base
  belongs_to :project
  belongs_to :source
  belongs_to :tree
  has_many :builds

  def name
    return source.name
  end

  def revision
    return tree.revision
  end

  def requires
    return tree.requires
  end

  def each_dependency
    requires.each do |dependency|
      yield dependency
    end
  end
  
  def designator
    return source.designator
  end

  def component
    return source.component
  end

  def checkout(path)
    return tree.checkout_as(path, name)
  end

  def ==(o)
    return project == o.project && equal_modulo_project(o)
  end

  def equal_modulo_project(o)
    return source == o.source &&
      tree == o.tree
  end    

  def eql?(o)
    return self == o
  end

  def <=>(o)
    order = project <=> o.project
    if order == 0 then
      order = tree <=> o.tree
    end
    return order
  end

  protected

  def validate
    source_must_be_in_project
    tree_must_have_same_designator_as_source
  end

  def source_must_be_in_project
    if source.project != project then
      errors.add('source', "the project #{target} belongs to is not the same as the project its source #{source} belongs to.")
    end
  end

  def tree_must_have_same_designator_as_source
    if tree.designator != source.designator then
      errors.add('tree', "tree has a different designator #{tree.designator} than source (#{source.designator}")
    end
  end

end
