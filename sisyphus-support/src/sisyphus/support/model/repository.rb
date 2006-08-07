
require 'active_record'

require 'sisyphus/support/utils/subversion'


class Repository < ActiveRecord::Base
  include Subversion
  
  has_many :designators
  validates_presence_of :location
  validates_uniqueness_of :location


  def tree(designator, revision)
    if revision.is_a?(Time) then
      revision = last_changed_revision_at(designator.path, revision)
    end
    return Tree.find_by_designator_and_revision(designator, revision)
  end


  def changes_since_session(session)
    result = []
    designators.each do |designator|
      result += changes_since(designator.path, session.time)
    end
  end


  def <=>(r)
    return location <=> r.location
  end

  def ==(r)
    return location == r.location
  end

  def to_s
    return location
  end


end
