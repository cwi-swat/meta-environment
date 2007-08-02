
class SiRevision < ActiveRecord::Base
  belongs_to :si_component
  has_many :si_items
  # fields: version

  def name
    si_component.name
  end

  def prefix(root)
    subdir = version.to_s
    return File.join(si_component.prefix(root), subdir)
  end

  def predecessor
    p = SiRevision.find(:first, :conditions => ['si_component_id = ? and version < ?', 
                                                si_component_id, version],
                        :order => 'version desc')
    return p
  end

  def ==(o)
    return o.si_component == si_component &&
      o.version == version
  end

end

