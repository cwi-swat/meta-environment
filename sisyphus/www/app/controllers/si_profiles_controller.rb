
require 'settings'

class SiProfilesController < ApplicationController
  layout 'application'

  def index
    list
    render :action => 'list'
  end

  def show
    @si_profile = SiProfile.find(params[:id])
    @name = @si_profile.name
    @version = @si_profile.version
    @profile = checkout_profile(@name, @version)
  end


  def list
    @profile_names = SiProfile.find_by_sql("select distinct name from si_profiles;")
    @profiles = []
    @profile_names.each do |name|
      @profiles << SiProfile.find(:first, :conditions => ['name = ?', name.name], :order => 'version desc')
    end
  end

  private

  def checkout_profile(name, version)
    command = $svn_executable
    command += " --username #{$sisyphus_config_username}"
    command += " --password #{$sisyphus_config_password}"
    command += " --revision #{version}"
    command += " cat #{repository_profile_path(name)}"
    IO.popen(command) do |f|     
      return f.read()
    end
  end

  def profile_name(name)
    return "#{name}.yml"
  end

  def repository_path
    return File.join($sisyphus_config_root, 'profiles')
  end

  def repository_profile_path(name)
    return File.join(repository_path, profile_name(name))
  end


end
