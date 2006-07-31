require 'active_record'

# = The +Action+ class
# This class models build actions; they can be configured as part of a profile.
# The name is used to identify a build action; the template should be a shell script
# containing embedded ruby (erb). It is instantiated using +Contexts+

class Action < ActiveRecord::Base
  belongs_to :profile
  acts_as_list :scope => :profile
  validates_presence_of :name, :template
end

