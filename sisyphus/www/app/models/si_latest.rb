
class SiLatest < ActiveRecord::Base
  # fields: name (component-name)
  # NB: id corresponds to host_ids (this is a view)
  belongs_to :si_item
  belongs_to :si_component

end
