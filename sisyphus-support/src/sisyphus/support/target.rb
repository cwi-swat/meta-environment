
require 'active_record'

class Target < ActiveRecord::Base
  belongs_to :project
  belongs_to :source
  belongs_to :profile
  belongs_to :tree

  def name
    return source.name
  end

  def revision
    return tree.revision
  end


  def actions
    return profile.actions
  end

  def environment
    return profile.environment
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

  def function(name)
    return profile.find_function(name)
  end


  def ==(o)
    return project == o.project &&
      source == o.source &&
      profile == o.profile &&
      tree == o.tree
  end


  protected

  def validate
    source_must_be_in_project
    project_must_be_in_profile
    tree_must_have_same_designator_as_source
  end

  def source_must_be_in_project
    if source.project != project then
      errors.add('source', "the project #{target} belongs to is not the same as the project its source #{source} belongs to.")
    end
  end

  def project_must_be_in_profile
    if not profile.projects.include?(project) then
      errors.add('project', "project #{project} is not part of profile #{profile}")
    end
  end

  def tree_must_have_same_designator_as_source
    if tree.designator != source.designator then
      errors.add('tree', "tree has a different designator #{tree.designator} than source (#{source.designator}")
    end
  end

end
