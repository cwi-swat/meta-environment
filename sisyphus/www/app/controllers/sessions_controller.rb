require 'stringio'

class SessionLinkLabel
  attr_reader :item
  def initialize(item)
    @item = item
  end

  def time
    return @item.si_session.time.strftime("%H:%M %d/%m")
  end

  def linkable
    return @item.si_results != []
  end

  def style_class
    if @item.success then
      return 'success'
    else
      return 'failure'
    end
  end
  
  def progress?
    @item.progress?
  end
  
  def failed?
    !progress? and !@item.success
  end

  def success?
    @item.success
  end
  
  def not_tried?
    failed? && @item.si_results == []
  end


  def id
    return @item.id
  end


  def label
    if @item.progress? then
      return 'in progress'
    end
  end

end


class SessionsController  < ApplicationController
  def show
    @sess = SiSession.find(params[:id])
  end

  def messages
    asession = SiSession.find(params[:id])
    messages = SiMessage.find(:all, :conditions => ['si_session_id = ?', asession.id], :order => "id asc")
    
    stream = StringIO.new
    messages.each do |msg|
      stream << msg.line
    end
        
    response.headers['Pragma'] = ' '
    response.headers['Cache-Control'] = ' '
    response.headers['Content-type'] = 'text/plain'
    response.headers['Content-Disposition'] = "attachment; filename=session#{asession.id}.log" 
    response.headers['Accept-Ranges'] = 'bytes'
    response.headers['Content-Length'] = stream.length
    response.headers['Content-Transfer-Encoding'] = 'binary'
    response.headers['Content-Description'] = 'File Transfer'
    render :text => stream.string
  end
  
  def index
    @hosts = SiHost.find(:all)
    if not session[:visible].nil? then
      @hosts = @hosts.select do |host|
        session[:visible].include?(host)
      end
    end
    @sessions = SiSession.find(:all, :limit => 30, :order => 'time desc')
    @table = {}
    @max = 0
    @hosts.each do |host|
      @table[host] = []
      @sessions.each do |sess|        
        sess.si_items.each do |item|
          if item.si_host.id == host.id and item.si_results != [] then
            @table[host] << [sess, SessionLinkLabel.new(item)]
          end
        end
        if @table[host].length > @max then
          @max = @table[host].length
        end
      end  
    end
  end
end
