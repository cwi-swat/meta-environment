
class SiHost < ActiveRecord::Base
  # fields: uname, active
  belongs_to :si_platform
  
  def name
    return uname

    if uname =~ /^([a-zA-Z0-9\-_.]+ [a-zA-Z0-9\-_.]+)/ then
     return $1
    end
    if uname =~  /([a-z0-9]+) / then
      return $1
    end
    return "Unknown Host"
    #raise RuntimeError.new("no hostname found in uname: #{uname}")
  end

  def <=>(o)
    return uname <=> o.uname
  end

  def to_s
    return uname
  end
  

  def robust_uname
    u = uname
    if u.nil? then
      return "FIXME: update to newer version!"
    end
    return u
  end
end

