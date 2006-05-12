

require 'yaml'

class EmptyShellFailure < Exception
  attr_reader :result

  def initialize(result)
    @result = result
  end

  def to_s
    s = "SCRIPT FAILURE:\n"
    s += @result.to_s
    return s
  end
end

class ShellResult
  attr_reader :output, :errors, :script, :exitstatus

  def initialize(output, errors, exitstatus, script)
    @output = output
    @errors = errors
    @exitstatus = exitstatus
    @script = script
  end

  def to_s
    s = "script: #{@script}\n"
    s += "exit: #{@exitstatus}\n"
    s += "stdout: \n#{@output}\n"
    s += "stderr: \n#{@errors}\n"
  end

end


class EmptyShell

  #### The interface

  def read(script, env = '')
    result = run_raising(script, env)
    return result.output
  end

  def read2(script, env = '')
    result = run_raising(script, env)
    return result.output, result.errors
  end

  def read3(script, env = '')
    result = run_raising(script, env)
    return result.output, result.errors, result.script
  end
  
  def execute(script, env = '')
    run_raising(script, env)
    return nil
  end

  #### More or less private... 

  def run_raising(script, env)
    result = run(script, env)
    if result.exitstatus != 0 then
      raise EmptyShellFailure.new(result)
    end
    return result
  end

  def run(script, env)
    return run_in_empty_shell do |stream|
      stream << "#{env}\n"
      stream << "#{script}\n"
    end
  end

  def add_header(stream)
    stream << "set -e\n"
  end

  def add_var(stream, var)
    stream << "#{var}=\n"
    stream << "export #{var}\n"
  end

  def add_footer(stream)
    stream << "exit $?\n"
  end

  def run_in_empty_shell
    stream = ""
    add_header(stream)
    yield stream
    add_footer(stream)
    run_script(stream)
  end    

  def temp_file_name(stem)
    return ".sisyphus_#{stem}.#{Process.pid}"
  end
  
  def save_script_to_temp_file(filename, script)
    File.open(filename, 'w') do |f|
      f.write(script)
    end
  end
  
  def run_script(script)
    todo_name = temp_file_name('todo')
    errors_name = temp_file_name('errors')
    output_name = temp_file_name('output')
    save_script_to_temp_file(todo_name, script)
    `/bin/sh -s < #{todo_name} 2> #{errors_name} > #{output_name}`
    output = read_file(output_name)
    errors = read_file(errors_name)
    File.unlink(todo_name, errors_name, output_name)
    return ShellResult.new(output, errors, $?.exitstatus, script)
  end
  
  def read_file(filename)
    result = nil
    File.open(filename) do |file|
      result = file.read
    end
    return result
  end

end
  
class CommandSpecificShell < EmptyShell
  # The shell this class models, 'knows' the explicit dependencies passed to configure
  # It assumes a yaml file in the same location as the file this class is in.
  # The yaml file contains e.g.:
  # cvs:              # command name
  #   CVS_RSH: ssh    # normal env var
  #   PATH: __CVS__   # env var bound by ./configure and substituted in make

  def initialize(command_name)
    @command_name = command_name
    @environment = read_environment
  end

  ##### Interface 
  # inherited


  ############# Private
  
  def run(script, env)
    return run_in_empty_shell do |stream|
      install_environment(stream)
      stream << "#{script}\n"
    end
  end
  
  def install_environment(stream)
    @environment.each_pair do |var, value|
      stream << "#{var.strip}=#{value.strip}\n"
      stream << "export #{var}\n"
    end
  end

  def read_environment
    data_dir = File.expand_path(File.dirname(__FILE__))
    config_filename = File.join(data_dir, 'environment.conf')   
    File.open(config_filename) do |file|
      return YAML.load(file)[@command_name]
    end
  end

end


if $0 == __FILE__ then
  script = $stdin.read
  result = EmptyShell.new.run_script(script)
  $stdout << result.output
  $stderr << result.errors
  exit(result.exitstatus)
end
