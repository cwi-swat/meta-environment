


module NewVersioning
  require 'fileutils'

  class SourceTreeDesignator
    attr_reader :repository, :name, :location

    def initialize(repository, name, location)
      @repository = repository
      @name = name
      @location = location
    end

    def snapshot(revision)
      return repository.source_tree(self, revision)
    end

    def read(path, revision)
      return repository.cat(self, path, revision)
    end

    def exists?(path, revision)
      return repository.exits?(self, path, revision)
    end

  end  

 
  class SourceTree
    include FileUtils

    def initialize(designator, revision)
      @designator = designator
      @revision = revision
    end

    def repository
      return @designator.repository
    end

    def in_check_out(destination)
      path = repository.checkout(@designator, @revision, name, destination)
      Dir.chdir(path) do 
        yield
      end
      #rm_rf(path)
    end
      
    def read(path)
      return @designator.read(path, @revision)
    end

    def exists?(path)
      return @designator.exists?(path, @revision)
    end

  end
    

end
