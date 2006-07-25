


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

    def current_revision(time = Time.now)
      return repository.last_changed_revision_at(self, time)
    end

    def read(path, revision)
      return repository.cat(self, path, revision)
    end

    def exists?(path, revision)
      return repository.exits?(self, path, revision)
    end

    def ==(o)
      return o.repository == repository &&
        o.name == name &&
        o.location == location
    end

  end  

 
  class SourceTree
    include FileUtils
    
    attr_reader :designator, :revision

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
      puts "rm_rf(path)"
    end
      
    def read(path)
      return @designator.read(path, @revision)
    end

    def exists?(path)
      return @designator.exists?(path, @revision)
    end

    def state
      deps = {}

      # yield a name
      # get a state back
      required.each do |dep|
        deps[dep] = yield dep
        if deps[dep].name != dep then
          raise "Inconsistency: #{deps[dep]} is no state for #{dep}!"
        end
      end

      return SourceTreeState.new(self, deps)
    end

    def name
      return @designator.name
    end

    def ==(o)
      o.revision == revision &&
        o.designator = designator
    end

    private

    def required
      # extract from .pc.in
    end

  end

  class SourceTreeState
    def initialize(source_tree, dependencies)
      @source_tree = source_tree
      @dependencies = dependencies
      check_state_consistency
    end

    def extent
      result = [@source_tree]
      @dependencies.each_value do |state|
        result |= state.extent
      end
      return result
    end

    def name
      return @source_tree.name
    end

    private

    def check_state_consistency
      if not homogeneous?(extent) then
        raise "State #{self} is inconsistent!"
      end
    end

    def homogeneous?(set)
      names = sets.collect { |x| x.name }.uniq
      return names.length == set.length
    end


  end
    

end
