class SiComponent < ActiveRecord::Base
  # fields: name

  def prefix(root)
    return File.join(root, name)
  end

  def <=>(o)
    return name <=> o.name
  end

  def to_s
    return name
  end

end
