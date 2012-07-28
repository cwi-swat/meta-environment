
require 'active_record'

class Session < ActiveRecord::Base
  has_many :builds
  has_many :changes
  belongs_to :previous, :class_name => 'Session', :foreign_key => 'previous_id'
  belongs_to :host
  validates_presence_of :time


  def self.find_latest_for_host(host)
    return Session.find_by_host(host, :order => 'time desc')
  end


  def changes(profile)
    return profile.changes_between_sessions(previous, self)
  end


  def to_s
    return "session@#{host}@{time}"
  end

  def ==(o)
    return previous == o.previous &&
      host == o.host &&
      time == o.time
  end

  def <=>(o)
    order = host <=> o.host
    if order == 0 then
      order = time <=> host.time
    end
    return order
  end

  protected

  def validate
    previous_session_must_be_of_same_host
  end

  def previous_session_must_be_of_same_host
    return previous.host == host
  end

end

