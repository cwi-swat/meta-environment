

class BuildsController < ApplicationController

  def index
    @movable_host_columns = true
    @components = SiComponent.find(:all)
    @table = {}
    @components.each do |c|
      @table[c] = {}
      @hosts.each do |h|
        @table[c][h] = nil
      end
    end
    builds = do_the_query(@hosts)
    latest = {}
    builds.each do |build|
      h = build.si_host
      c = build.si_revision.si_component
      latest[h] ||= nil
      @table[c][h] = LinkLabel.new(build)
      if latest[h] then
        if build.id > latest[h].id 
          latest[h] = build
        end
      else
        latest[h] = build
      end
    end
    session[:latest] = latest
  end
    
  def changes
    latest = session[:latest]
    
    changes_per_host = {}
    if not latest then
      latest = {}
    end
    
    latest.each_key do |host|
      previous_build = latest[host]
      items = SiItem.find(:all, :conditions => 
                          ['id >= ? and si_host_id = ?', previous_build.id, host.id],
                          :order => 'id asc')

      
      if completed?(previous_build) and completed?(items.first) then
#      if !previous_build.in_progress? and !items.first.in_progress? then
#        $stderr << "Previous build: \n"
#        $stderr << previous_build.success
#        $stderr << "\n"
#        $stderr << previous_build.id
#        $stderr << "\n"
#        $stderr << previous_build.in_progress?
#        $stderr << "\n"
#        $stderr << previous_build.si_results.length
#        $stderr << "\n"
        items.shift
        if not items.empty? then
          latest[host] = items.first
        end
      else
        if completed?(items.first) then
          latest[host] = items.last
#          if items.length == 1 then
#            items = []
#          end
        else
          latest[host] = items.first
        end
      end
      
      changes_per_host[host] = items
    end
    

    session[:latest] = latest

    global_changes = []
    changes_per_host.each_value do |items|
      global_changes += items
    end

    render_partial 'items', global_changes.collect { |x| LinkLabel.new(x) }
  end



  def rss
    @links = {}
    @result_links = {}

    @items = @recent

    if params[:pkg] then
      @items = SiItem.find(:all, :conditions => ['progress = \'f\' and si_items.id in (select si_item_id from si_results) and si_revision_id in (select si_revisions.id from si_revisions, si_components where si_component_id = si_components.id and name = ?)', params[:pkg]], :limit => 10, :order => "id desc")         
    end

    if params[:host] then
      @items = SiItem.find(:all, :conditions => ['progress = \'f\' and si_items.id in (select si_item_id from si_results) and si_host_id in (select id from si_hosts where uname like ?)', "%#{params[:host]}%"], :limit => 10, :order => "id desc")         
    end
    
    @items.each do |item|
      @links[item] = url_for(:controller => 'si_items', :action => 'show', :id => item.id)
      item.si_results.each do |result|
        @result_links[result] = url_for(:controller => 'si_results', :action => 'show', :id => result.id)
      end
    end
    render_without_layout
  end
  

  private


  def hosts_clause(hosts = @hosts)
    s = @hosts.collect do |h|
      h.id
    end.join(' or si_host_id = ')
    return 'si_host_id = ' + s
  end


  def do_the_query(hosts)
    query=<<-EOQ
select *, 
  (si_items.id not in (select * from tried)) as not_tried 
from
    si_items
where 
 si_items.id in (
select max(id) as id 
from si_items 
where
  #{hosts_clause(hosts)}
group by 
  si_revision_id, si_host_id 
having 
  si_revision_id in 
     (select max(id) 
      from si_revisions 
      group by si_component_id)
) ;
EOQ
    return SiItem.find_by_sql(query)
  end

  def my_hosts
    time = Time.now - 24 * 60 * 60 * 7
    sessions = SiSession.find(:all, :conditions => ['time > ?', time], :order => 'time desc')
    items = sessions.collect do |session|
      SiItem.find(:all, :conditions => ['si_session_id = ?', session.id], :order => 'id desc')
    end
    items.flatten!
    hosts = {}
    items.each do |item|
      host = item.si_host
      if not hosts.has_key?(host) then
        hosts[host] = []
      end
      hosts[host] = hosts[host] | [item.si_session]
    end
    return hosts
  end


  def host_items(host)
    return SiItem.find(:all, :conditions => ['si_host_id = ?', host.id], 
                       :order => 'id desc', :limit => 100)
  end

  def completed?(item)
    # Ugly!!!!
    label = LinkLabel.new(item)
    return label.failed? || label.success? || label.not_tried?
  end

end



class LinkLabel
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
    failed? && @item.not_tried?
  end

  def id
    return @item.id
  end


  def label
    if @item.progress? then
      results = @item.si_results
      if results.empty? then
        return "starting..."
      else
        return results.last.action
      end
    else
      if @item.success then
        return 'success'
      elsif !@item.not_tried?
        return 'failed'
      else
        return 'not tried'
      end
    end
  end

  def to_s
    return label
  end

end
