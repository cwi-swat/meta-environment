
module Building

  require 'model/db'

  class LazyItemGenerator 
    LIMIT = 100;

    def initialize(names, host, config, store)
      @names = names
      @host = host
      @config = config
      @store = store
      @builds = []
    end

    
    def [](i)
      build = @builds[i]
      unless build
        grow
        return self[i]
      end
      return build.si_item
    end


    private

    def grow
      builds = Model::SiBuild.find(:all,
                                   :conditions => conditions,
                                   :limit => LIMIT,
                                   :order => 'id desc')
      if builds.empty? then
        raise "No more builds available (last one was: #{@builds.last.si_item})"
      end 
      @builds += builds
    end

    def id_condition
      if @builds.empty? then
        return nil
      end
      return "id < #{@builds.last.si_item.id}"
    end

    def config_conditions
      c = @store.db_config(@config)
      h = @store.db_host(@host)
      return "si_host_id = #{h.id} and si_config_id = #{c.id}"
    end

    def conditions
      pat = (['name = ?'] * @names.length).join(' or ')
      pat += ' and ' + config_conditions
      vals = @names
      if id_condition then
        if pat != '' then
          pat  = ' and ' + pat
        end
        pat = id_condition + pat
      end
      return [pat] + vals
    end

  end


end
