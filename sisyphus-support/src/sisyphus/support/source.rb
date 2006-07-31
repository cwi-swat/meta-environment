
require 'active_record'

class Source < ActiveRecord::Base
  belongs_to :component
  belongs_to :designator
  belongs_to :project

  def self.find_designator_for_component_and_project(component, project)
    return Source.find(:first, :condition => ['component_id = ? and project_id = ?', 
                                             component, project])
  end

  def name
    return component.name
  end

end
