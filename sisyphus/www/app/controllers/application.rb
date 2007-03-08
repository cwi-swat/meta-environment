# Filters added to this controller will be run for all controllers in the application.
# Likewise, all the methods added will be available for all controllers.
class ApplicationController < ActionController::Base
  session :session_expires => 1.month.from_now
  before_filter :side_bar


  private

  def side_bar
    @recent = SiItem.find(:all, :conditions => ['progress = \'false\' and id in (select si_item_id from si_results)'], :limit => 10, :order => "id desc")   
    if session[:visible].nil? then
      @hosts = SiHost.find(:all, :conditions => ['active = \'true\''], :order => 'uname asc')
    else
      @hosts = session[:visible].collect do |host|
        SiHost.find(host.id)
      end
    end
    @main_url = url_for(:controller => 'builds', :action => 'index', :trailing_slash => false)
    @main_url = @main_url[0..@main_url.length-2]
  end  



end
