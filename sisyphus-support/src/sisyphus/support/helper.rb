require 'active_record'

class Helper < ActiveRecord::Base
  has_and_belongs_to_many :profiles
  has_many :functions

  def each_var
    functions.each do |function|
      yield function.var
    end
  end

end

