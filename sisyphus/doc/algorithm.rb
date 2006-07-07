module SetEquality
  def set_equal(set1, set2)
    return subset_or_equal(set1, set2) &&
      subset_or_equal(set2, set1)
  end

  def subset_or_equal(set1, set2)
    set1.each do |x|
      if not set2.include?(x) then
        return false
      end
    end
    return true
  end

end


class StateOracle
  def initialize(time)
    @time = time
  end

  def dependencies(name)
  end

  def version(name)
  end
end


class State
  def initialize(name, oracle)
    @name = name
    @oracle = oracle
    @deps = oracle.dependencies(name)
    @version = oracle.version(name)
    @map = {}
    @deps.each do |dep|
      @map[dep] = State.new(dep, oracle)
    end
  end
  
  def flatten
    table = {}
    table[@name] = [self]
    @deps.each do |dep|
      dep_table = @map[dep].flatten
      dep_table.each do |name, state|
        table[name] ||= []
        table[name] << state
      end
    end
    return table
  end
    

  def validate
    # for any component reachable from here
    # there should be one single state
    # i.e. the flattened table should be a bijection.
  end

  def ==(state)
    if not set_equal(names, state.names) then
      return false
    end
    names.each do |name|
      if revision(name) != state.revision(name) then
        return false
      end
    end
    return true
  end

end    
  


end

class Revision
  include SetEquality

  attr_reader :name, :version, :deps

  def initialize(name, version, time, deps)
    @name = name
    @version = version
    @time = time
    @deps = deps
  end

  def state(state = State.new(self))
    deps.each do |dep|
      state.add(dep.revision(@time))
    end
  end

  def ==(revision)
    return name == revision.name &&
      version == revision.version &&
      set_equal(deps, revision.deps)
  end

end




class Package
  attr_reader :name

  def initialize(name)
    @name = name
  end

  def revision(time)
    version = version(time)
    deps = dependencies(time)
    return Revision.new(@name, version, time, deps)
  end


  def state(time)
    state = State.new
    revision = revision(time)
    revision.deps do |dep|
      
    deps = dependencies(time)
    deps.each do |dep|
      state.add(dep.revision(time))
    end
  end
  
  def dependencies(time)
    return # list of Package instances
  end



end



# state = Deps^*[p]

def build(package)
  fix_point_build(package.state(Time.now))
end

def fix_point_build(state)
  build_dependencies(state.deps)
  state2 = state.new(Time.now)
  if state2 != state then
    fix_point_build(state2)
  else
    build_state(state)
    state3 = state.new(Time.now)
    if state3 != state then
      fix_point_build(state3)
    else
      return
    end
  end
end

def build_state(state)
  if session.include?(state) then
    return
  else
    dep_states = session.select do |s|
      state.deps.include?(s.package)
    end
    if any of dep_states has failed then
      construct an optimal state from the db
      ...
    end
    do_build(state, dep_states)
  end
end


def build_dependencies(deps)
  deps.each do |dep|
    build(dep)
  end
end
