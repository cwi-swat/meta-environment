
require 'active_record'

class Session < ActiveRecord::Base
  has_many :builds
  has_many :changes
  belongs_to :previous, :class_name => 'Session', :foreign_key => 'previous_id'
  belongs_to :host
  validates_presence_of :time

  def self.find_by_host_and_time(host, time)
    s = Session.find(:first, :conditions => ['host_id = ? and time = ?', host, time])
    if not s then
      s = Session.new(:host => host, :time => time)
      s.save
    end
    return s
  end

  def self.find_latest_for_host(host)
    return Session.find(:first, :conditions => ['host_id = ?', host], :order => 'time desc')
  end

  protected

  def validate
    previous_session_must_be_of_same_host
  end

  def previous_session_must_be_of_same_host
    return previous.host == host
  end

end

