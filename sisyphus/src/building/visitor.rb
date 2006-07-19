module Building

  require 'versioning/component'
  require 'versioning/revision'


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
    def initialize(target_factory, revision_factory, roots, builder, log, config)
      @target_factory = target_factory
      @revision_factory = revision_factory
      @roots = roots
      @builder = builder
      @log = log    
      @visited = {}
      @config = config
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
      dep_items = build_deps(revision)
      return build_revision_with_deps(revision, dep_items)
    end

    def build_revision_with_deps(revision, dep_items)
      target = @target_factory.target(revision, dep_items)
      item = @builder.build(target)
      return item
    end

    def build_deps(revision)
      deps = revision.deps
      result = []                   
      @log.indented do
        result = deps.collect do |dep|
          build_component(dep)
        end
        if @config.build_env_package and revision.name != @config.build_env_package then
          c = Versioning::Component.new(@config.build_env_package)
          result << build_component(c)
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
