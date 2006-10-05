module Building

  require 'distribution/distconf'

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
      return ('/' * Distribution::NUM_OF_SLASHES) + path
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
      # jurgenv: turned off to prevent bugs in automake generated makefiles 
      #path = enlarge_path(path)
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
    def initialize(config, item)
      super(config, item)
      @deps = contexts_for_items(config, item.dep_items)
      @tr_deps = contexts_for_items(config, item.tr_deps)
    end


    def tr_deps
      return @tr_deps.reject do |dep| 
        @config.build_env_packages.include?(dep.name)
      end
    end

    def deps
      return @deps.reject do |dep| 
        @config.build_env_packages.include?(dep.name)
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

    private

    def without_build_env_pkgs(deps)
      return deps.reject do |dep| 
        @config.build_env_packages.include?(dep.name)
      end
    end

    def contexts_for_items(config, items)
      items.collect do |item|
        ContextItem.new(config, item)
      end
    end

  end

end
