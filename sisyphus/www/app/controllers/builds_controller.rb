

class BuildsController < ApplicationController

  def index
    @movable_host_columns = true
    @components = SiComponent.find(:all)
    @table = {}
    latest = {}
    @components.each do |c|
      @table[c] = {}
      @hosts.each do |h|
        ## NB: the || is essential!
        latest[h] ||= nil
        item = latest_item2(c, h)
        if item.nil? then
          label = nil
        else
          if latest[h] then
            if item.id > latest[h].id 
              latest[h] = item
            end
          else
            latest[h] = item
          end
          label = LinkLabel.new(item)
        end
        @table[c][h] = label
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

  def index_old
    @components = SiComponent.find(:all)
    @table = {}
    @components.each do |c|
      @table[c] = {}
      @hosts.each do |h|
        item = latest_item2(c, h)
        if item.nil? then
          label = nil
        else
          label = LinkLabel.new(item)
        end
        @table[c][h] = label
      end
    end
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

  def latest_item2(component, host)
    if host.id.nil? then #????
      return nil
    end
    return  SiItem.find_by_sql("select si_items.* from si_items, si_revisions where si_items.si_revision_id = si_revisions.id and si_revisions.si_component_id = #{component.id} and si_items.si_host_id = #{host.id} order by si_items.id desc limit 1").first
  end

  def latest_item3(c, h)
    return SiItem.find_by_sql("select si_items.* from si_items, si_revisions where si_items.si_host_id = #{h} and si_items.si_revision_id = si_revisions.id and si_revisions.si_component_id = #{c} order by si_items.id desc limit 1").first
  end


  def latest_itemssss() 
    query=<<EOQ
select * from  
si_components inner join (select si_component_id, max(si_revisions.id) from si_revisions group by si_component_id) as bla on (si_components.id = si_component_id) order by name;
EOQ
  end


  def latest_item(items, component)
    items.each do |item|
      if item.si_revision.component == component then
        # return the first
        return item
      end
    end
    return nil
  end


  def completed?(item)
    # Ugly!!!!
    label = LinkLabel.new(item)
    return label.failed? || label.success? || label.not_tried?
  end

##    return (!item.in_progress? && !item.success) || (item.success) || (!item.success && item.si_results == [] || (!item.success) && item.si_results != [])
#  end
  

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
    failed? && @item.si_results == []
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
      elsif @item.si_results != [] then
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
