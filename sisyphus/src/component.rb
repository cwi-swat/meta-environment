
class Component
  attr_reader :name

  def initialize(name)
    @name = name
  end

  def to_s
    return name
  end

  def prefix(root)
    return File.join(root, name)
  end

  def eql?(component)
    return @name.eql?(component.name)
  end
  
  def ==(component)
    return component.name == @name
  end

  def hash
    return @name.intern.hash
  end

  def to_s
    return @name
  end

end
