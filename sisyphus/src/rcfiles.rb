
module Roll

  def Roll.rcfile(name)
    home = ENV['HOME']
    return File.join(home, name)
  end

  def Roll.boot_roll_rcfile
    return rcfile('.bootrollrc')
  end

  def Roll.roll_rcfile
    return rcfile('.rollrc')
  end

end
