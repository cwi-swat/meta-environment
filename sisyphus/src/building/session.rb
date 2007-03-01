
module Building

  class Session
    attr_reader :time, :host, :db_session
    
    def initialize(time, host, db_session)
      @time = time
      @host = host
      @built = {}
      @emails = {}
      @db_session = db_session
    end

    def hostname
      if @host =~ /^([a-zA-Z0-9\-_.]+ [a-zA-Z0-9\-_.]+)/ then
        return $1
      end
      if @host =~  /([a-z0-9]+) / then
        return $1
      end
      return @host
    end

    def empty?
      return @built == {}
    end

    def contains_failures?
      @built.each_value do |item|
        if !item.success then
          return true
        end
      end
      return false    
    end

    def components
      return @built.keys
    end

    def add(revision, item)
      @built[revision.component] = item
      revision.checkout.extract_emails.each do |addr|
        @emails[addr] ||= []
        @emails[addr] << item
      end
    end

    def each_email
      @emails.each_key do |addr|
        yield addr, @emails[addr]
      end
    end

    def item(component)
      return @built[component]
    end


    def has?(component)
      return @built.has_key?(component)
    end

    def has_any?(components)
      return components.inject(false) do |cur, component|
        cur || has?(component)
      end
    end

    def to_s
      return @built.inspect
    end

  end

end
