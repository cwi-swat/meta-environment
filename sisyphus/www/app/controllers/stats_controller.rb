


class StatsController < ApplicationController

  def index
  end
  

  def failure_success_history_graph
    g = Gruff::Line.new('1024x800')
    @start = SiSession.minimum(:time)
    @stop = SiSession.maximum(:time)
    period = @stop - @start
    points = 10
    slot = period / points
    fails = []
    successes = []
    commits = []
    0.upto(points - 1) do |i|
      sessions = SiSession.find(:all, :conditions => ['time >= ? and time < ?',
                                                      @start + i*slot,
                                                      @start + (i+1)*slot])
      failed = 0
      success = 0
      revisions = []
      sessions.each do |session|
        session.si_items.each do |item|
          if item.success then 
            success += 1
          else
            failed += 1
          end
          revisions << item.si_revision
        end
      end
      fails << failed
      successes << success
      commits << revisions.uniq.length
      g.labels[i] = ((@start + i * slot) + slot /2).strftime("%b")
    end
    d1 = @start.strftime("%b-%y")
    d2 = @stop.strftime("%b-%y")
    g.data("Revisions", commits, 'blue')
    g.data("Failure", fails, 'red')
    g.data("Success     (history from #{d1} to #{d2})", successes, 'green')

    g.theme = {
      :colors => %w(#efd250 #666699 #e5573f #9595e2),
      :marker_color => 'black',
      :background_colors => %w(white white)
    }
    
    g.hide_title = true


    send_data(g.to_blob, 
              :disposition => 'inline', 
              :type => 'image/png', 
              :filename => "bart_scores.png")

    
  end


  def build_partitioning
    fails = SiItem.count :id, :group => :si_host_id, :conditions => ['success = \'f\'']
    g = Gruff::Pie.new
    fails.each do |tuple|
      begin
        host = SiHost.find(tuple.first)
        if host then
          g.data(host.name, [tuple.last])
        end
      rescue ActiveRecord::RecordNotFound
      end
    end
    g.theme = {
      #:colors => %w(#efd250 #666699 #e5573f #9595e2),
      :colors => %w(red blue green yellow orange black brown),
      :marker_color => 'black',
      :background_colors => %w(white white)
    }
    g.legend_font_size = 10
    send_data(g.to_blob, 
              :disposition => 'inline', 
              :type => 'image/png', 
              :filename => "bart_scores.png") 
  end

  # Send a graph to the browser
  def revision_count_chart
    revision_counts = SiRevision.count :id, :group => :si_component_id
    map = {}
    revision_counts.each do |list|
      map[list.first] = list.last
    end
    components = SiComponent.find(:all, :order => 'name asc')

    g = Gruff::SideStackedBar.new('800x1600')
    g.title = "Number of revisions for components"
    g.font = File.expand_path('artwork/fonts/Vera.ttf', RAILS_ROOT)
    g.labels = {}
    i = 0
    components.each do |component|
      g.labels[i] = component.name
      i += 1
    end
    g.data(:RevisionCount, components.collect do |component|
             map[component.id]
    end)


    g.theme = {
      :colors => %w(#efd250 #666699 #e5573f #9595e2),
      :marker_color => 'black',
      :background_colors => %w(white white)
    }
        
    g.hide_legend = true
      

    send_data(g.to_blob, 
              :disposition => 'inline', 
              :type => 'image/png', 
              :filename => "bart_scores.png")
  end
  

end
