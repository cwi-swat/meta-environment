
module Utils

  require 'ostruct'

  module UnameDir
    def uname(opt)
      elt = `uname -#{opt}`.chomp
      return elt.tr(', #', '_')
    end

    def platform
      opts = ['s', 'r', 'i', 'm', 'p']
      s = OpenStruct.new
      s.kernel_name = uname('s')
      s.kernel_release = uname('r')
      s.hardware_platform = uname('i')
      s.hardware_class = uname('m')
      s.processor_type = uname('p')
      return s
    end

    def uname_dir
      s = platform
      path = s.kernel_name
      path = File.join(path, s.kernel_release)
      path = File.join(path, s.hardware_platform)
      path = File.join(path, s.hardware_class)
      path = File.join(path, s.processor_type)
      return path
    end
  end

end
