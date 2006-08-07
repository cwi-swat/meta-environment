require 'active_record'

class Helper < ActiveRecord::Base
  has_and_belongs_to_many :profiles
  has_many :functions

  def function(name)
    functions.each do |function|
      if function.name == name then
        return function.template
      end
    end
  end

  def each_variable
    functions.each do |function|
      yield function.var
    end
  end

end

