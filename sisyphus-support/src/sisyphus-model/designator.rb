require 'active_record'

class Designator < ActiveRecord::Base
  belongs_to :repository
  belongs_to :project

  validates_presence_of :path

  def self.find_by_repository_and_project_and_path(repository, project, path)
    d = Designator.find(:first, :conditions => ['repository_id = ? and project_id = ? and path = ?',
                                                repository, project, path])
    if not d then
      d = Designator.new(:repository => repository, :project => project, :path => path)
      d.save
    end
  end

end
