module Utils

  require 'net/smtp'

  class MockItem
    attr_reader :name, :version, :success
    def initialize(name, version, success)
      @name = name
      @version = version
      @success = success
    end

    def id
      return object_id.abs
    end

  end

  class MockSession
    attr_reader :host, :time
    def initialize(host, time)
      @host = host
      @time = time
      @items = {}
    end

    def add(component, item)
      @items[component] = item
    end

    def item(component)
      @items[component]
    end

    def components
      return @items.keys
    end
  end

  

  class SessionMailer
    attr_reader :smtp, :port, :from_address

    def initialize(from_address, smtp, port = 25, 
                   build_url_pattern = "http://sisyphus.sen.cwi.nl:8080/si_items/show/%d")
      @smtp = smtp
      @port = port
      @from_address = from_address
      @build_url_pattern = build_url_pattern
    end


    def mail(session)
      session.each_email do |addr, items|      
        if not all_success?(items) then
          s = message(items, session)
          mail_to_address(s, addr, items, session)
        end
      end
    end


    private
    def all_success?(items)
      return items.inject(true) do |failed, item|
        failed && item.success
      end
    end

    def component_col_width
      return 22
    end
    def revision_col_width
      return 16
    end

    def build_col_width
      return 6
    end
    
    def success_col_width
      return 5
    end

    def url_col_width
      return 50
    end

    def bar(c = '-')
      return row(c * component_col_width,
                 #           c * revision_col_width,
                 #           c * build_col_width,
                 c * success_col_width,
                 c * url_col_width)
    end

    def row(comp, succ, url)
      fmt = "%-#{component_col_width}s|"
      #fmt += "%-#{revision_col_width}s|"
      #fmt += "%-#{build_col_width}s|"
      fmt += "%-#{success_col_width}s|"
      fmt += "%-#{url_col_width}s\n"
      return sprintf(fmt, comp, succ, url)
    end

    def message(items, session)
      msgstr = "Sisyphus Build results\n"
      msgstr += "======================\n\n"

      msgstr += "Host: #{session.hostname}\n"
      msgstr += "Time: #{session.time}\n\n"
      msgstr += row('Component', 'Succ', 'URL')
      msgstr += bar()
      items.each do |item|
        msgstr << format_item(item)
      end
      return msgstr
    end

    def mail_to_address(message, address, items, session)
      msgstr = mail_header(address, items, session)
      msgstr += message

      Net::SMTP.start(@smtp, @port) do |smtp|
        smtp.send_message(msgstr, @from_address, address)
      end
    end

    def format_item(item)
      url = sprintf(@build_url_pattern, item.id)
      return row(item.name, item.success, url)
    end

    def mail_header(address, items, session)
      failed = 0
      total = 0
      items.each do |item|
        total += 1
        if not item.success then
          failed += 1
        end
      end
      header =<<END_OF_HEADER
From: Sisyphus <#{@from_address}>
To: #{address}
Subject: [Sisyphus] #{session.hostname}: #{failed}/#{total} failure (#{session.time})
Date: #{Time.now}
Message-Id: <#{session.time.to_i}@example.com>
END_OF_HEADER
      return header
    end
  end



  class DummySessionMailer < SessionMailer
    def initialize()
    end

    def mail(session)
    end
  end

end



if __FILE__ == $0
  i1 = Utils::MockItem.new('aterm', 3443, true)
  i2 = Utils::MockItem.new('toolbus-java-adapter', 234, false)
  session = Utils::MockSession.new(`uname -n`.chomp, Time.now)
  session.add('aterm', i1)
  session.add('toolbus-java-adapter', i2)

  mail = Utils::SessionMailer.new(['storm@cwi.nl'], 'smtp.cwi.nl', 25)
  mail.mail(session)
  
end

