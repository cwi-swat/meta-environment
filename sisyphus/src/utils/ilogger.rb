module Utils

  require 'logger'
  require 'model/dbmsg'

  class Indentation
    def initialize(num_of_spaces, object)
      @num_of_spaces = num_of_spaces
      @object = object
    end

    def to_s
      return (' ' * @num_of_spaces) + @object.to_s
    end
    
    def inspect
      return (' ' * @num_of_spaces) + @object.inspect
    end

  end

  class IndentedLogger < Logger
    def initialize(output, width = 2)
      super(output)
      @indent = 0
      @width = width
    end

    def indented
      indent
      yield
      dedent
    end

    def indent
      @indent += 1
    end

    def dedent
      @indent -= 1
    end

    def indent_object(obj)
      return (' ' * (@indent * @width)) + obj.to_s
    end

    def format_message(severity, time, progname, message)
      return indent_object(super(severity, time, progname, message))
    end

  end


  class IndentedDBLogger < IndentedLogger
    def initialize(host, session, output, width = 2)
      super(output)
      @host = host
      @indent = 0
      @width = width
      @session = session
    end


    def format_message(severity, time, progname, message)
      string = super(severity, time, progname, message)
      msg = Model::SiMessage.new(:line => string, :si_host => @host, :si_session => @session)
      msg.save
      return string
    end

  end

end
