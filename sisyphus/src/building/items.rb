
module Building

  require 'model/db'

  class LazyItemGenerator 
    LIMIT = 100;

    def initialize(names)
      @names = names
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

    def conditions
      pat = (['name = ?'] * @names.length).join(' or ')
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
