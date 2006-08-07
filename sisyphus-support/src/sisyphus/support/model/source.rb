
require 'active_record'

class Source < ActiveRecord::Base
  belongs_to :component
  belongs_to :designator
  belongs_to :project

  def repository
    return designator.repository
  end

  def name
    return component.name
  end

  def to_s
    return "#{component}@#{project}=#{designator}"
  end

  

end
