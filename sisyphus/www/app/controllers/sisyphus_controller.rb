
class SisyphusController < ApplicationController
  def index
    @dists = {}
    Dir[File.join(sisyphus_download_path, '*.tar.gz')].each do |path|
      dist = File.basename(path)
      @dists[dist] = url_for(File.join(sisyphus_download_stem, dist))
    end
  end

  private

  def download_stem
    return '/downloads'
  end

  def download_path(stem)
    File.join(File.dirname(__FILE__), File.join('../../public', stem))
  end

  def sisyphus_download_stem
    return File.join(download_stem, 'sisyphus')
  end

  def sisyphus_download_path
    download_path(File.join(download_stem, 'sisyphus'))
  end
end
