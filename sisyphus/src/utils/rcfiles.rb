
module Utils

  module Roll

    def Roll.rcfile(name, tag = nil)
      home = ENV['HOME']
      if tag then
        return File.join(home, name) + "." + tag
      end
      return File.join(home, name)
    end

    def Roll.boot_roll_rcfile(tag = nil)
      return rcfile('.bootrollrc', tag)
    end

    def Roll.roll_rcfile(tag = nil)
      return rcfile('.rollrc', tag)
    end

  end

end
