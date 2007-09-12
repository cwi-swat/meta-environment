require 'bundle'
require 'graphviz'

class SiItemsController < ApplicationController
  layout 'application'

  def index
    list
    render :action => 'list'
  end

  def list
    @si_item_pages, @si_items = paginate :si_item, :per_page => 10
  end

  def show
    @si_item = SiItem.find(params[:id])
    @co_deps = co_dependencies(@si_item)
    @may_be_bundled = false
    if File.exists?(package_path(@si_item)) then
      @may_be_bundled = true
      @dist_file = @si_item.targz
      @bundle_file_name = bundle_file_name(@si_item)
      @binary_file_name = binary_file_name(@si_item)
      @binary_path = File.join(binary_download_path, @binary_file_name)
      if File.exist?(@binary_path) then
        @has_binary = true
      else
        @has_binary = false
      end
      @binary_url = File.join('/downloads/binaries' , @binary_file_name)
    end
    @changes = item_changes(@si_item)
    query =<<END
select si_items.* from si_items, si_revisions, si_components 
where
    si_items.si_revision_id = si_revisions.id and
    si_revisions.si_component_id = si_components.id and
    si_components.name = '#{@si_item.name}' and
    si_items.id < #{@si_item.id} and
    si_items.si_host_id = #{@si_item.si_host_id}
    order by si_session_id desc limit 10
END
    @earlier_items = SiItem.find_by_sql(query)
  end


  def latest
    item = latest_dist_item_by_name(params[:pkg])
    upload_item(item)
  end

  def latest_binary
    item = latest_dist_item_by_name(params[:pkg])
    render_binary(binary_file_path(item))
  end

  def latest_bundle
    item = latest_dist_item_by_name(params[:pkg])
    bundle_file_path = make_bundle(item)
    render_bundle(bundle_file_path)    
  end

  def latest_dep_graph
    item = latest_dist_item_by_name(params[:pkg])
    render_plain_dep_graph(item)
  end

  def latest_dep_graph_map 
    item = latest_dist_item_by_name(params[:pkg])
    render_plain_dep_graph_map(item)   
  end

  def download
    item = SiItem.find(params[:id])
    upload_item(item)
  end


  def bundle
    item = SiItem.find(params[:id])
    #bundle_file_path = bundle_file_path(item)
    #if not File.exists?(bundle_file_path) then
    #  make_bundle(item, bundle_file_path)
    #end
    bundle_file_path = make_bundle(item)
    render_bundle(bundle_file_path)
  end

  def dep_graph
    @si_item = SiItem.find(params[:id])
    @map = graph_map_cmapx(@si_item)
  end

  def reduced_dep_graph
    @si_item = SiItem.find(params[:id])
    @map = graph_map_cmapx(@si_item, true)
  end

  def reduced_graph_img
    @si_item = SiItem.find(params[:id])
    compute_graph_img(@si_item, true)
  end

  def graph_img
    @si_item = SiItem.find(params[:id])
    compute_graph_img(@si_item)
  end

  

  private


  
  def latest_dist_item_by_name(name)
    query = <<EOQ
select si_items.* 
from si_items, si_revisions, si_components, si_hosts
where
si_items.progress = false and
si_items.success = 't' and
si_host_id = si_hosts.id and
si_hosts.dists = 't' and
si_revision_id = si_revisions.id and
si_component_id = si_components.id and
si_components.name = '#{name}'
order by si_items.id desc
limit 1
EOQ
    item = SiItem.find_by_sql(query)[0]
    return item
  end

  def upload_item(item)
    path = File.join(download_path, item.targz)
    if not File.exists?(path) then
      render :text => "<h2>No such archive #{path}</h2>", :layout => true
      return 
    end

    tarball = nil
    File.open(path) do |f|
      tarball = f.read
    end
    response.headers['Pragma'] = ' '
    response.headers['Cache-Control'] = ' '
    response.headers['Content-type'] = 'application/octet-stream'
    response.headers['Content-Disposition'] = "attachment; filename=#{File.basename(path)}" 
    response.headers['Accept-Ranges'] = 'bytes'
    response.headers['Content-Length'] = tarball.length
    response.headers['Content-Transfer-Encoding'] = 'binary'
    response.headers['Content-Description'] = 'File Transfer'
    render :text => tarball
  end

  # 5432
  def item_changes(item)
    # find first older item for the same revision
    i = SiItem.find(:first, :conditions => ['si_revision_id = ? and id < ?', 
                                            item.si_revision.id, item.id])
    if not i.nil? then
      # there is such item
      # so no changes
      return ''
    end

    return item.si_revision.changelog_diff
  end

  def binary_download_path
    File.join(download_path, 'binaries')
  end

  def download_path
    File.join(File.dirname(__FILE__), '../../public/downloads')
  end

  def package_dir
    return download_path
  end

  def package_path(item)
    return File.join(package_dir, package_name(item))
  end

  def sisyphus_download_path
    File.join(download_path, 'sisyphus')
  end


  def co_dependencies(item)
    codeps = SiItem.find_by_sql(
                                ["select i.* from si_items i, si_item_deps d where i.id = si_item_id and si_dep_id = ? order by i.id desc", item.id]
                                )
    return codeps
  end



  def parsed_package_name(item)
    return package_name(item) + '.af'
  end

  def pkg_version(item)
    return "#{item.informative_version}pre.#{item.version}.#{item.id}"
  end

  def bundle_file_name(item)
    return "#{item.name}-bundle-#{pkg_version(item)}.tar.gz"
  end

  def binary_file_name(item)
    return "#{item.name}-#{pkg_version(item)}.bin.sh"
  end


  def binary_file_path(item)
    file_name = binary_file_name(item)
    return File.join(binary_download_path, file_name)
  end

  def has_binary?(item)
    if File.exist?(binary_file_path(item))
      return true
    end
    return false
  end

  def package_name(item)
    return "#{item.name}-#{pkg_version(item)}.pkg"
  end

  def bundle_file_path(item)
    return File.join(package_dir, bundle_file_name(item))
  end

  def bundle_command(item, output_dir = Dir.tmpdir)
    # NOTE Hard paths here!!! Refactor
    autobundle = '/ufs/sen1/software/installed/autobundle-0.12/linux/i386/bin/autobundle'
    return "#{autobundle} -I #{package_dir} -p #{parsed_package_name(item)} -v #{pkg_version(item)} -o #{output_dir}"
  end

  def ariadne_bundle(item, output_dir = Dir.tmpdir)   
    deps = {}
    item.edges.each do |i1, i2|
      pkg1 = BundlePackage.new(i1.name, i1.targz_version)
      pkg2 = BundlePackage.new(i2.name, i2.targz_version)
      deps[pkg1] ||= []
      deps[pkg2] ||= []
      deps[pkg1] << pkg2
    end

    # TODO: Find this out from RoR (asset_url_for?)
    location = 'http://sisyphus.sen.cwi.nl:8080/downloads'
    # The list of packages must be in topological sort!
    bundle = Bundle.new(item.name, item.targz_version, deps.tsort, deps, location)
    gen = BundleGenerator.new(bundle, output_dir)
    return gen.generate # returns path of bundle targz
  end

  def make_bundle_old(item)
    output_dir = Dir.tmpdir
    command = bundle_command(item, output_dir)
    `#{command}`
    return File.join(output_dir, bundle_file_name(item))
  end
  
  def make_bundle(item)
    return ariadne_bundle(item)
  end


  def render_bundle(path, errors = nil)
    my_render_file(path, errors)
  end

  def render_binary(path, errors = nil)
    my_render_file(path, errors)
  end

  def my_render_file(path, errors = nil)
    content = nil
    File.open(path) do |f|
      content = f.read
    end
    response.headers['Pragma'] = ' '
    response.headers['Cache-Control'] = ' '
    response.headers['Content-type'] = 'application/octet-stream'
    response.headers['Content-Disposition'] = "attachment; filename=#{File.basename(path)}" 
    response.headers['Accept-Ranges'] = 'bytes'
    response.headers['Content-Length'] = content.length
    response.headers['Content-Transfer-Encoding'] = 'binary'
    response.headers['Content-Description'] = 'File Transfer'
    render :text => content
  end

  def render_plain_dep_graph_map(item) 
    map = ''
    write_plain_dep_graph(item) do |path|
      map = create_graph(path, 'imap', true)
    end
    render :text => map   
  end

  def render_plain_dep_graph(item)
    png = ''
    write_plain_dep_graph(item) do |path|
      png = create_graph(path, 'png', true)
    end
    response.headers['Content-type'] = "image/png"
    render :text => png
  end

  



  def graph_map_imap
    @si_item = SiItem.find(params[:id])   
    map = ''
    write_graph(@si_item) do |path|
      map = create_graph(path, 'imap')
    end
    render :text => map
  end    


  def compute_graph_img(item, reduce = false)
    png = ''
    write_graph(@si_item) do |path|
      png = create_graph(path, 'png', reduce)
    end
    response.headers['Content-type'] = "image/png"
    render :text => png
  end


  def graph_map_cmapx(item, reduce = false)
    map = ''
    write_graph(item) do |path|
      map = create_graph(path, 'cmapx', reduce)
    end
    return map
  end    

  
  def create_graph(fname, lang, reduce = false)
    text = ''
    if reduce then
      text = `#{GraphViz::PATH}/tred #{fname} | #{GraphViz::PATH}/dot -T#{lang}`
    else
      text = `#{GraphViz::PATH}/dot -T#{lang} #{fname}`
    end
    return text
  end


  def write_graph(item)
    sessions = []
    nodes = item.nodes
    edges = item.edges
    nodes.each do |node|
      sessions |= [node.si_session]
    end
    
    f = Tempfile.new("dot_generation")
    f.puts("digraph dependency_graph {")
    f.puts("compound=true;")
    f.puts("node [shape=box];")
    f.puts("nodesep=1.0;")
    sessions.each do |sess|
      f.puts("subgraph cluster_#{sess.id} {")
      sess.si_items.each do |item|
        if nodes.include?(item)
          url = url_for(:controller => 'si_items', :action => 'show', :id => item.id)
          color = 'green'
          shape = 'box'
          if not item.success then
            color = 'red'
          end
          if item.in_progress? then
            shape = 'ellipse'
          end
          version = item.si_revision.version
          name = item.name
          f.puts("node_#{item.id} [shape=#{shape},label=\"#{name}\\nV:#{version}\",URL=\"#{url}\",color=#{color}]")
        end
      end
      url = url_for(:controller => 'sessions', :action => 'show', :id => sess.id)
      f.puts("graph [label=\"#{sess.time}\", URL=\"#{url}\"]")
      f.puts("}")
    end
    edges.each do |n1, n2|
      f.puts("node_#{n1.id} -> node_#{n2.id}")
    end
    f.puts("}")
    f.flush
    begin
      yield f.path
    ensure
      f.close
    end
  end

  def write_plain_dep_graph(item)
    sessions = []
    nodes = item.nodes
    edges = item.edges
    nodes.each do |node|
      sessions |= [node.si_session]
    end
    
    f = Tempfile.new("dot_generation")
    f.puts("digraph dependency_graph {")
    f.puts("node [shape=box];")
    f.puts("nodesep=1.0;")
    sessions.each do |sess|
      sess.si_items.each do |item|
        if nodes.include?(item)
          url = url_for(:controller => 'si_items', :action => 'show', :id => item.id)
          version = item.si_revision.version
          name = item.name
          f.puts("node_#{item.id} [label=\"#{name}\\nV:#{version}\",URL=\"#{url}\"]")
        end
      end
    end
    edges.each do |n1, n2|
      f.puts("node_#{n1.id} -> node_#{n2.id}")
    end
    f.puts("}")
    f.flush
    begin
      yield f.path
    ensure
      f.close
    end
  end


  def old_write_graph(item)
    f = Tempfile.new("dot_generation")
    f.puts("digraph dependency_graph {")
    f.puts("compound=true")
    item.nodes.each do |node|
      url = url_for(:controller => 'si_items', :action => 'show', :id => node.id)
      color = 'green'
      fillcolor = 'white'
      if not item.success then
        color = 'red'
      end
      if item.progress? then
        fillcolor = 'lightgrey'
      end
      
      version = node.si_revision.version
      name = node.name
      f.puts("node_#{node.id} [label=\"#{name}@#{version}\",URL=\"#{url}\",color=#{color}]")
    end
    item.edges.each do |n1, n2|
      f.puts("node_#{n1.id} -> node_#{n2.id}")
    end
    f.puts("}")
    f.flush
    begin
      yield f.path
    ensure
      f.close
    end
  end



end
