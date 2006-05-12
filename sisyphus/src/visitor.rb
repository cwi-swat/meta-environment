
require 'component'

class CheckoutVisitor
  def initialize(target_factory, checkout_factory, builder, log)
    @target_factory = target_factory
    @revision_factory = revision_factory
    @builder = builder
    @log = log    
    @visited = {}
  end

  def visit_checkout(roots)
    roots.each do |root|
      visit(root)
    end
  end

  def visit(name)
    component = Component.new(name)
    visit_component(component)
  end

  def visit_component(component)
    if not @visited.has_key?(component) then
      @log.info("component #{component} must be visited.")
      @visited[component] = visit_checkout_for_component(component)
    end
    return @visited[component]
  end
  
  def revision(component)
    return @revision_factory.clean_revision(component)
  end

  def visit_checkout_for_component(component)
    checkout = @checkout_factory.checkout(component)
    revision = Revision.from_checkout(component, checkout)
    if revision.virtual? then
      @log.info("revision #{revision} is virtual; no build performed.")
      return nil
    end
    return visit_revision(revision)
  end

  def visit_revision(revision)
    dep_items = visit_deps(revision.deps)
    return visit_revision_with_deps(revision, dep_items)
  end

  def visit_revision_with_deps(revision, dep_items)
    target = @target_factory.target(revision, dep_items)
    item = @builder.build(target)
    return item
  end

  def visit_deps(deps)
    result = []
    @log.indented do
      result = deps.collect do |dep|
        visit_component(dep)
      end
    end
    return result.compact
  end

end



class Visitor
  def initialize(target_factory, revision_factory, roots, builder, log)
    @target_factory = target_factory
    @revision_factory = revision_factory
    @roots = roots
    @builder = builder
    @log = log    
    @visited = {}
  end

  def build_roots
    @roots.each do |root|
      build(root)
    end
  end

  def build(name)
    component = Component.new(name)
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
    dep_items = build_deps(revision.deps)
    return build_revision_with_deps(revision, dep_items)
  end

  def build_revision_with_deps(revision, dep_items)
    target = @target_factory.target(revision, dep_items)
    item = @builder.build(target)
    return item
  end

  def build_deps(deps)
    result = []
    @log.indented do
      result = deps.collect do |dep|
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

