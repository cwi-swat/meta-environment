
require 'active_record'

class Target < ActiveRecord::Base
  belongs_to :project
  belongs_to :source
  belongs_to :tree

  def name
    return source.name
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
