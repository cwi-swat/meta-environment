
require 'distconf'
require 'fileutils'
require 'erb'

class ContextItem
  include FileUtils

  attr_reader :item

  def initialize(config, item)
    @config = config
    @item = item
  end

  def name
    return @item.name
  end

  def binary_dist_dir
    path = @item.prefix(@config.binary_dist_dir)
    make_dir_if_needed(path)
    return path
  end

  def source_dist_dir
    path = @item.prefix(@config.source_dist_dir)
    make_dir_if_needed(path)
    return path
  end

  def enlarge_path(path)
    return ('/' * NUM_OF_SLASHES) + path
  end

  def prefix
    path = nil
    #if `uname -n`.chomp == 'batatrom.sen.cwi.nl' then
    #  path = File.join(@config.install_dir, @item.name)
    #  if not File.exists?(path) then
    #    `svn mkdir #{path}`
    #  end
    #else
    path = @item.prefix(@config.install_dir)
    make_dir_if_needed(path)
    #end
    path = enlarge_path(path)
    return path
  end

  def make_dir_if_needed(path)
    if not test(?d, path) then
      mkdir_p path
    end
  end

  def to_s
    return "context(#{@item})"
  end

end

class Context < ContextItem
  attr_reader :deps, :tr_deps
  
  def initialize(config, item)
    super(config, item)
    @deps = item.dep_items.collect do |dep|
      ContextItem.new(config, dep)
    end
    @tr_deps = @deps
    # @tr_deps = trans_close(config, item)
  end


  # BUggy?
  def trans_close(config, item)
    todo = [item]
    ds = []
    while todo != [] do
      i = todo.pop
      items = i.dep_items
      if items.is_a?(Array) then
        ds |= [i] + items
        todo |= items
      end
    end
    return ds.collect do |dep|
      ContextItem.new(config, item)
    end
  end


  def actions
    @config.actions.each do |name|
      yield name, instantiate(@config.action_template(name))
    end      
  end

 
  def instantiate(template)
    t = ERB.new(template)
    return t.result(binding())
  end
end
