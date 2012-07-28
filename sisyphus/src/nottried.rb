

require 'model/db'
require 'yaml'

def revision_info(revision)
  info = {}
  build_count = Model::SiItem.count(:conditions => ['si_revision_id = ?', revision.id])
  #c = Model::SiItem.find_by_sql("select count(si_items.id) from si_items where si_revision_id = #{revision.id} except select si_item_id from si_results;")
  #if not c.empty? then
  #  not_tried_count = Integer(c[0].attributes['count'])
  #else
  #  not_tried_count = 0
  #end

  $stderr << "Visiting: #{revision}\n"
  not_tried_count = Model::SiItem.find_by_sql("select si_items.id from si_items where si_revision_id = #{revision.id} except select si_item_id from si_results;").length
  $stderr << "It has: #{not_tried_count} not-trieds.\n"
  return build_count, not_tried_count
end


def component_info(component)
  revisions = component.si_revisions
  total_builds = 0
  total_not_trieds = 0
  revisions.each do |revision|
    build_count, not_tried_count = revision_info(revision)
    total_builds += build_count
    total_not_trieds += not_tried_count
  end
  puts "#{component.name} #{revisions.length} #{total_builds} #{total_not_trieds}"
end


def main
  info = nil
  puts "# Name, #revisions, #builds, #nottrieds"
  components = Model::SiComponent.find(:all)
  components.each do |component|
    info = component_info(component)
  end
end


if __FILE__ == $0 then
  conf = {
    'adapter' => 'postgresql',
    'database' => 'sisyphusdev',
    'host' =>  'sjofar.sen.cwi.nl',
    'username' => 'sisyphusdev',
    'password' => 'tantalu5'
  }
  ActiveRecord::Base.establish_connection(conf)
  main
end
