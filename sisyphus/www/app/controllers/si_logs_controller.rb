
class SiLogsController < ApplicationController
  layout 'application'


  def index
    list
    render :action => 'list'
  end

  def list
    @si_logs = SiLog.find(:all, :order => "id desc", :limit => 100)
  end
  
end
