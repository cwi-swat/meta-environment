


class CandidatesController  < ApplicationController
  def index
    # Return all items that have successfully built on all hosts
    @items = SiItem.find(:all, :conditions => 'success = true', :limit => 100, :order => 'id desc')
    @components = SiComponent.find(:all)
    @table = {}
    @components.each do |component|
      @table[component] = []
      @items.each do |item|
        if item.si_revision.si_component == component then
          @table[component] << item
        end
      end
    end
  end
end
