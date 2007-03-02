
class SiComponentsController < ApplicationController
  layout 'application'
  
  


  def success_failure_ratio
    @component = SiComponent.find(params[:id])
  end

  def success_failure_ratio_graph
    component = SiComponent.find(params[:id])
    failed = SiItem.find_by_sql("select si_items.* from si_items, si_revisions where si_revision_id = si_revisions.id and si_component_id = #{component.id} and success = false").length
    success = SiItem.find_by_sql("select si_items.* from si_items, si_revisions where si_revision_id = si_revisions.id and si_component_id = #{component.id} and success = true").length

    g = Gruff::Pie.new('400x400')
    g.data("Failed", [failed], 'red')
    g.data("Success", [success], 'green')
    g.title = "Success-failure ratio for #{component.name}"
    
    g.theme = {
      # :colors => %w(#efd250 #666699 #e5573f #9595e2),
      :colors => %w(red green),
      :marker_color => 'black',
      :background_colors => %w(white white)
    }

    send_data(g.to_blob, 
              :disposition => 'inline', 
              :type => 'image/png', 
              :filename => "success_failure_ratio_#{component.name}.png")

  end


end
