class SiResultsController < ApplicationController
  layout 'application'

  def index
    list
    render :action => 'list'
  end

  def list
    @si_result_pages, @si_results = paginate :si_result, :per_page => 10
  end

  def show
    @si_result = SiResult.find(params[:id])
    @si_result.output.squeeze!("\n")
  end

end
