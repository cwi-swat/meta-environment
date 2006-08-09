
require 'active_record'

class Tree < ActiveRecord::Base
  belongs_to :designator
  has_many :targets
  validates_presence_of :revision


  def checkout(destdir = '.', dirname = File.basename(path))
    return Checkout.new(repository, self, destdir, dirname)
  end

  def maintainers
    if bom =~ /Maintainers\s*=\s*([^\n]*)/m then
      return $1.split(',')
    end
    return []
  end

  def version
    if bom =~ /Version\s*:\s*([0-9\.a-bA-Z_\-]+)/m then
      return $1
    end
    raise "Error parsing version in: #{bom}"
  end

  def requires
    if bom =~ /^Requires\s*:\s*([^\n]*)/m then
      return $1.split(/[, ]/).collect do |name|
        Component.new(:name => name)
      end
    end
    return []
  end

  def repository
    return designator.repository
  end

  def path
    return designator.path
  end

  def to_s
    return "#{designator}@#{revision}"
  end

  def ==(o)
    return designator == o.designator &&
      revision == o.revision
  end

  def <=>(o)
    order = designator <=> o.designator
    if order == 0 then
      order = revision <=> o.revision
    end
    return order
  end

  private

  def bom
    if @bom then
      return @bom
    end
    @bom = read(bom_file_name)
    return @bom
  end

  def bom_file_name
    # TODO: this should be parameterized somehow using helpers.
    return "#{name}.pc.in"
  end

  def read(subpath)
    return repository.read(expand_path(subpath), revision)
  end

  def exist?(subpath)
    return repository.exist?(expand_path(subpath), revision)
  end

  def expand_path(subpath)
    return File.join(path, subpath)
  end



end
