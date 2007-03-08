
require 'tmpdir'

class Checkout
  def initialize(repository, package, dest = Dir.tmpdir)
    @repository = repository
    @package = package
    @dest = dest
    checkout
  end

  def path
    return File.join(@dest, @package)
  end

  def checkout
    url = "file://#{@repository}/#{@package}/trunk"
    system("svn co #{url} #{path}")
  end

end

class Transaction
  def initialize(changes)
    @changes = changes      
  end
  
  def commit
    files = @changes.collect do |change|
      change.apply
    end
    files.each do |file|
      system("svn commit -m \"Changes applied\" #{file}")
    end
  end 
end


class Change
  def initialize(checkout)
    @checkout = checkout
  end

  def apply
    # return changed file
    raise "Subclass responsibility"
  end
  
  def revert
    # return changed file
    raise "Subclass responsibility"
  end

  def path
    @checkout.path
  end

  def move_file(from, to)
    file = File.join(path, from)
    file2= File.join(path, to)
    system("svn move #{file} #{file2}")
    return file2
  end  

  def append_new_line(file)
    file = File.join(path, file)
    system("echo >> #{file}")
    return file
  end

end

class BreakingChange < Change
  FILE1 = 'configure.ac'
  FILE2 = 'configure.ac-moved'

  def apply
    return move_file(FILE1, FILE2)
  end

  def undo
    return move_file(FILE2, FILE1)
  end
end

class HarmlessChange < Change
  def apply
    file = 'reconf'
    return append_new_line(file)
  end

  def undo
    # nop
    return nil
  end
  
end

