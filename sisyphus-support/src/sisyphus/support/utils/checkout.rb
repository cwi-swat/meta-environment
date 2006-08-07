


class Checkout
  def initialize(repository, tree, destdir, dirname)
    @repository = repository
    @tree = tree
    @destdir = destdir
    @dirname = dirname
    @repository.checkout(@tree.path, @dirname, @destdir, @tree.revision)
  end

  def clean_up
    puts "rm -r #{local_path}"
  end

  def in_checkout
    Dir.chwd(local_path) do 
      yield
    end
  end

  private

  def local_path
    return File.join(@destdir, @dirname)
  end


end
