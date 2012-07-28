
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
      puts("svn commit -m \"Changes applied\" #{file}")
      system("svn commit -m \"Changes applied\" #{file}")
    end
  end 

  def rollback
    files = @changes.reverse.collect do |change|
      change.undo
    end
    files.each do |file|
      puts("svn commit -m \"Changes undone\" #{file}")
      system("svn commit -m \"Changes undone\" #{file}")
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


end

class BreakingChange < Change
  FILE = 'Makefile.am'

  def apply
    file = File.join(path, FILE)
    system("sed --in-place -e 's/ /<*>/g' #{file}")
    return file
  end


  def undo
    file = File.join(path, FILE)
    system("sed --in-place -e 's/<\\*>/ /g' #{file}")
    return file
  end
end



class HarmlessChange < Change
  FILE = 'reconf'

  def append_new_line(file)
    file = File.join(path, file)
    system("echo >> #{file}")
    return file
  end

  def apply
    return append_new_line(FILE)
  end

  def undo
    # nop
    return File.join(path, FILE)
  end
  
end

