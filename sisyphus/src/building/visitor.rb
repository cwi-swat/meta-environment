module Building

  require 'versioning/component'
  require 'versioning/revision'
  require 'model/db'
  require 'building/product'
  
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
      if `uname -n`.chomp == 'verfrol.sen.cwi.nl' then
        return build_revision_backtracking_original(revision)
      end
      dep_items = build_deps(revision)
      return build_revision_with_deps(revision, dep_items)
    end

    def build_revision_backtracking_simple(revision, limit = 10)
      #dep_items = build_deps(revision)
      # discard these, because they may have failures
      
      query =<<EOQ
select si_items.* from 
si_items, 
si_revisions, 
si_components
where 
si_items.si_revision_id = si_revisions.id and
si_revisions.si_component_id = si_components.id and
si_components.name = '#{revision.name}' and
si_items.success = true 
order by id desc
limit #{limit}
EOQ
      previous_builds = Model::SiItem.find_by_sql(query)
      item = find_newest_previous_build_using_same_deps(revision.deps, previous_builds)
      puts item
      item.si_deps.each do |dep|
        puts "\t#{dep}"
      end
      exit!
    end

      
    def find_newest_previous_build_using_same_deps(required_deps, previous_builds)
      s1 = required_deps.collect { |dep| dep.name }.sort
      #puts "S1 = #{s1.join(', ')}"
      previous_builds.each do |item|
        #puts item
        s2 = item.si_deps.collect { |dep| dep.name }.sort
        #puts "S2 = #{s2.join(', ')}"
        if s1 == s2 then
          return item
        end
      end
      return nil
    end


    def build_revision_backtracking_original(revision, limit = 10)
      # This, the original idea, does not scale.
      num_of_possibilities = 1
      num_of_solutions = 0
      items = nil
      begin
        puts "Iteration limit: #{limit}"
        power_set = []
        dep_i = 0
        revision.deps.each do |dep|
          my_limit = limit
          if limit > 1 then
            if dep_i % 2 == 0 then
              my_limit = limit  / 2
            end
          end
          dep_i += 1
          query =<<EOQ
select si_items.* from 
si_items, 
si_revisions, 
si_components
where 
si_items.si_revision_id = si_revisions.id and
si_revisions.si_component_id = si_components.id and
si_components.name = '#{dep.name}' and
si_items.success = true
order by si_items.id desc
limit #{my_limit}
EOQ
          items = Model::SiItem.find_by_sql(query)
          num_of_possibilities *= items.length
          power_set << items
        end       
        puts "Number of possible solutions: #{num_of_possibilities}"
        num_of_solutions = num_of_possibilities
      
        prod = product_space(power_set)  

        i = 1
        prod.each do |solution|
          set = []
          solution.each do |item|
            set |= extent_set(item)
          end
          if homogeneous(set) then
            puts "Solution: #{i}"
            solution.each do |item|
              puts "\t#{item}"
            end
          else
            puts "Error:"
            puts set
          end
          i += 1
        end
       

        limit += 1
      end while num_of_solutions == 0 && !items.nil?

      exit!
    end

    def extent_set(item)
      set = []
      item.as_nodes do |n|
        set |= [n]
      end
      return set
    end

    def homogeneous(set_of_items)
      names = set_of_items.collect { |i| i.name }.uniq
      return names.length == set_of_items.length
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
