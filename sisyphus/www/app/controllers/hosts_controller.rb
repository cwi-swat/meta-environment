

class HostsController  < ApplicationController

  def index
    @hosts = SiHost.find(:all, :order => 'id asc')   
    if session[:visible].nil? then
      session[:visible] = SiHost.find(:all, :conditions => ['active = true'], :order => 'id asc')
    end
    @visible = session[:visible]
  end

  def update
    session[:visible] = []
    params[:visible].each_key do |id|
      session[:visible] << SiHost.find(id)
    end
    redirect_to :action => 'index', :controller => 'builds'
  end

end
