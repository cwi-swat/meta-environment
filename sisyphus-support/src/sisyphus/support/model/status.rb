
require 'active_record'

class Status < ActiveRecord::Base
  set_table_name 'status'
  belongs_to :host
  belongs_to :build
  belongs_to :result

  validates_presence_of :message

end
