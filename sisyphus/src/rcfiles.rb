
def rcfile(name)
  home = ENV['HOME']
  return File.join(home, name)
end

def boot_roll_rcfile
  return rcfile('.bootrollrc')
end

def roll_rcfile
  return rcfile('.rollrc')
end
