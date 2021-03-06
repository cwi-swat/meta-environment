require 'active_record'

class Function < ActiveRecord::Base
  belongs_to :helper
  belongs_to :variable
  acts_as_list :scope => :helper
  validates_presence_of :name, :template

  def name
    return variable.name
  end

  def to_s
    return name + ' ::= ' + "{#{template}}"
  end

end

