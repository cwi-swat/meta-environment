
require 'subversion'

class SourcesController < ApplicationController
  # seems to be needed?
  layout 'application'


  def index
    redirect_to :action => 'show', :version => obtain_version
  end

  def show
    @version = params[:version]
    @sources = checkout_sources(@version)
  end


  private

  def sources_name
    return 'sources.yml'
  end


  def checkout_sources(version)
    command = Subversion::SVN
    #command += " --username #{$sisyphus_config_username}"
    #command += " --password #{$sisyphus_config_password}"
    command += " --revision #{version}"
    command += " cat #{repository_sources_path}"
    IO.popen(command) do |f|     
      return f.read()
    end
  end

  def repository_path
    return File.join(Sisyphus::CONFIGURATION_REPOSITORY, 'config')
  end

  def repository_sources_path
    return File.join(repository_path, sources_name)
  end

  def obtain_version
    svn = Subversion::SVN
    info = `#{svn} info #{repository_sources_path}`
    info.split("\n").each do |line|
      if line =~ /Last Changed Rev: ([0-9]+)/ then
        return $1.to_i
      end
    end
    raise RuntimeError.new("subversion didn't behave as expected: #{info.split.inspect}")
  end
  
end
