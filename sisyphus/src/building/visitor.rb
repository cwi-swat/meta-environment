module Building

  require 'versioning/component'
  require 'versioning/revision'
  require 'model/db'
  require 'building/product'
  require 'building/items'
  require 'building/working-sets'
  
  require 'pp'


  class BuildResult
  end

  class VirtualBuildResult < BuildResult
  end

  class NormalBuildResult < BuildResult
    attr_reader :item
    def initialize(item)
      @item = item
    end
  end

  class ImplicitDependencyBuildResult < NormalBuildResult
  end

  class Visitor
    include Product
    
    def initialize(target_factory, revision_factory, roots, builder, log, config, store)
      @target_factory = target_factory
      @revision_factory = revision_factory
      @roots = roots
      @builder = builder
      @log = log    
      @visited = {}
      @config = config
      @store = store
    end

    def build_roots
      @roots.each do |root|
        build(root)
      end
    end

    def build(name)
      component = Versioning::Component.new(name)
      build_component(component)
    end

    def build_component(component)
      if not @visited.has_key?(component) then
        @log.info("component #{component} may require a build.")
        @visited[component] = build_revision_for_component(component)
      end
      return @visited[component]
    end
    
    def revision(component)
      return @revision_factory.clean_revision(component)
    end

    def build_revision_for_component(component)
      revision = revision(component)
      if revision.virtual? then
        @log.info("revision #{revision} is virtual; no build performed.")
        return nil
      end
      return build_revision(revision)
    end

    def build_revision(revision)
      #if `uname -n`.chomp == 'verfrol.sen.cwi.nl' then
      #  return build_revision_backtracking_original(revision)
      #end
      dep_items = build_deps(revision)

      #host = `uname -n`.chomp
      #names = revision.dep_names
      #if not names.empty? then
      #  ws = dep_items
      #  begin
      #    ws = first_valid_working_set(names, host, @config, @store)
      #  rescue
      #  end
      #  puts "Workingset: "
      #  ws.each do |item|
      #    puts item
      #  end
      #end
      return build_revision_with_deps(revision, dep_items)
    end

    #############################################################

    def build_revision_backtracking_original(revision, limit = 10)
      names = revision.deps.collect { |dep| dep.name }
      debug_all_working_sets(names)
      working_set = first_valid_working_set(names)
      exit!
    end

    def first_valid_working_set(names, host, config, store)
      items = LazyItemGenerator.new(names, host, config, store)
      workingsets = WorkingSetGenerator.new(items, names)
      workingsets.each do |working_set|
        if valid_working_set?(working_set) then
          return working_set
        end
      end   
    end

    def valid_working_set?(working_set)
      return homogeneous?(extent(working_set))
    end

    def debug_all_working_sets(names)
      items = LazyItemGenerator.new(names)
      workingsets = WorkingSetGenerator.new(items, names)
      workingsets.each do |working_set|
        if homogeneous?(extent(working_set)) then
          puts "Valid: "
        else
          puts "Invalid: "
        end
        extent(working_set).each do |item|
          puts "\t#{item}"
        end
      end
    end

    def extent(working_set)
      set = []
      working_set.each do |item|
        set |= item.extent
      end
      return set
    end


    def homogeneous?(set_of_items)
      names = set_of_items.collect { |i| i.name }.uniq
      return names.length == set_of_items.length
    end

    ##################################################

    def build_revision_with_deps(revision, dep_items)
      target = @target_factory.target(revision, dep_items)
      @log.info("#{revision}: dep_items in build_revision_with_deps: [#{dep_items.join(', ')}]")
      item = @builder.build(target)
      return item
    end

    def implicit_deps
      return @config.build_env_packages
    end

    def build_deps(revision)
      implicit_deps.each do |implicit_dep|
        if implicit_dep == revision.name then
          # if revision is an implicit_dep itself
          # add only implicit deps "until" revision.name
          break
        end
        revision.add_dep(Versioning::Component.new(implicit_dep))
      end
      result = []                   
      @log.indented do
        result = revision.deps.collect do |dep|
          @log.info("Building #{dep}")
          build_component(dep)
        end
      end
      return result.compact
    end

  end

  class UncleanVisitor < Visitor
    def revision(component)
      return @revision_factory.updated_revision(component)
    end
  end

end
