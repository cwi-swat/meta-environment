
require 'subversion'

class ScriptController < ApplicationController
  layout 'application'

  def index
    redirect_to :action => 'show', :version => obtain_version
  end

  def show
    @version = params[:version]
    @script = checkout_script(@version)
  end

  private

  def script_name
    return 'script.yml'
  end

  def checkout_script(version)
    command = Subversion::SVN
    #command += " --username #{$sisyphus_config_username}"
    #command += " --password #{$sisyphus_config_password}"
    command += " --revision #{version}"
    command += " cat #{repository_script_path}"
    IO.popen(command) do |f|     
      return f.read()
    end
  end

  def repository_path
    return File.join(Sisyphus::CONFIGURATION_REPOSITORY, 'config')
  end

  def repository_script_path
    return File.join(repository_path, script_name)
  end

  def obtain_version
    svn = Subversion::SVN
    info = `#{svn} info #{repository_script_path}`
    info.split("\n").each do |line|
      if line =~ /Last Changed Rev: ([0-9]+)/ then
        return $1.to_i
      end
    end
    raise RuntimeError.new("subversion didn't behave as expected: #{info}")
  end

  

end
