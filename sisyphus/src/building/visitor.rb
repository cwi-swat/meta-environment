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

    def implicit_dep
      return @config.build_env_package
    end

    def build_deps(revision)
      if implicit_dep and revision.name != implicit_dep then
        revision.add_dep(Versioning::Component.new(implicit_dep))
      end
      result = []                   
      @log.indented do
        result = revision.deps.collect do |dep|
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
