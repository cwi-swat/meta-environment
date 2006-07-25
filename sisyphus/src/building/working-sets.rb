
module Building

  class WorkingSetGenerator
    def initialize(items, names)
      @items = items
      @names = names
    end

    def each
      start = 0
      loop do
        yield working_set_at(start)
        start += 1
      end
    end



    private         

    def working_set_at(start)
      required = @names.clone
      working_set = []
      i = 0
      while not required.empty? do
        item = @items[start + i]
        name = item.name
        if required.include?(name) then
          required.delete(name)
          working_set << item
        end
        i += 1
      end
      return working_set
    end


  end


end
