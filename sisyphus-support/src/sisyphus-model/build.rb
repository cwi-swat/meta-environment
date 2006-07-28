require 'active_record'

class Build < ActiveRecord::Base
  belongs_to :tree
  belongs_to :host
  belongs_to :profile
  has_many :results
  has_many :integrations
  has_many :dependencies, :through => :integrations

  validates_presence_of :time

end
