
require 'active_record'

class Script < ActiveRecord::Base
  include Enumerable

  has_and_belongs_to_many :profiles
  has_many :actions

  def each
    actions.each do |action|
      yield action
    end
  end
  
end
