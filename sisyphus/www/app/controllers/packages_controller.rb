

class PackagesController < ApplicationController

  def index
    @pkgs = {}

    Dir[File.join(download_path, '*.pkg.af')].each do |pkg|
      name = File.basename(pkg)
      if name =~ /^([a-zA-Z\-]*)-([0-9]*)\.([0-9]*)\.pkg\.af/ then
        @pkgs[$1] ||= []
        dist = "#{$1}-#{$2}.#{$3}.tar.gz"
        bundle = "#{$1}-bundle-#{$2}.#{$3}.tar.gz"
        @pkgs[$1] << [$2, $3, dist, bundle]
      end
    end
  end

  def package
    path = File.join(download_path, params[:archive])
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

  private

  def has_bundle(item)
    if has_package(item) then
      return item.si_deps.inject(true) do |flag, dep|
        flag &&= has_bundle(dep)
      end      
    end
    return false
  end
  
  def has_package(item)
    if File.exists?(File.join(download_path, item.targz)) then
      return true
    end
    return false
  end


  def download_path
    File.join(File.dirname(__FILE__), '../../public/downloads')
  end

end
