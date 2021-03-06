module Model

  require 'active_record'
  require 'utils/diff'
  require 'utils/udir'



  class SiPlatform < ActiveRecord::Base
    # Fields:
    # kernel_name
    # kernel_release
    # hardware_platform
    # hardware_class
    # processor_type
  end

  class SiComponent < ActiveRecord::Base
    # fields: name
    has_many :si_revisions

    def prefix(root)
      return File.join(root, name)
    end

    def ==(o)
      return name == o.name
    end
  end

  class SiRevision < ActiveRecord::Base
    belongs_to :si_component
    has_many :si_items
    # fields: version, changelog_diff

    def name
      si_component.name
    end

    def predecessor
      p = SiRevision.find(:first, :conditions => ['si_component_id = ? and version < ?', 
                                                  self.si_component_id, self.version],
                          :order => 'version desc')
      return p
    end

    def ==(o)
      return version == o.version &&
        si_component == o.si_component
    end

    def prefix(root)
      subdir = version.to_s
      return File.join(si_component.prefix(root), subdir)
    end

    def to_s
      return "#{name}-#{informative_version.strip}:#{version}"
    end
  end


  class SiProfile < ActiveRecord::Base
    # fields: name, version
  end

  class SiHost < ActiveRecord::Base
    # fields: uname
    belongs_to :si_platform
    validates_presence_of :uname

    def name
      if uname =~ /([a-z0-9]+\.[a-z0-9]+\.[a-z0-9]+\.[a-z0-9]+) / then
        return $1
      end
      raise RuntimeError.new("no hostname found in uname: #{uname}")
    end
  end

  class SiConfig < ActiveRecord::Base
    # fields: sources_version, script_version
    belongs_to :si_profile
  end

  class SiSession < ActiveRecord::Base
    # fields: time
    has_many :si_items  
    has_many :si_messages
  end

  class SiItem < ActiveRecord::Base
    include Comparable
    # fields: success
    belongs_to :si_revision

    ###
    belongs_to :si_host
    belongs_to :si_config # can host/config vary per session? don't think so.
    # move this to session
    # looking for an existing attempt we have one extra indirection:
    # find an item with a session that has the same host and config.

    belongs_to :si_session
    has_many :si_results
    has_and_belongs_to_many :si_deps, 
    :class_name => 'SiItem',
    :join_table => 'si_item_deps',
    :foreign_key => 'si_item_id',
    :association_foreign_key => 'si_dep_id'   


    def add_action_result(action, command, result)
      r = SiResult.new(:command => command, 
                       :action => action,
                       :output => result.output,
                       :error_output => result.errors,
                       :environment => result.environment,
                       :success => result.success)
      SiItem.transaction do 
        si_results << r
        save
      end
    end

    def informative_version
      si_revision.informative_version.strip
    end

    def set_result(result)
      self.success = result.success
    end

    def set_progress(bool)
      self.progress = bool
    end

    def set_success(bool)
      # For some obscure reason, this:
      self.success = bool
      # is not the same as:
      # success = bool (????)
    end

    def in_progress?
      self.progress == true
    end

    def dep_items
      return si_deps
    end

    def name
      return si_revision.name
    end

    def version
      return si_revision.version
    end

    def prefix(root)
      subdir = id.to_s
      # Why o why was it the session time...?
      # si_session.time.to_i.to_s
      return File.join(si_revision.prefix(root), subdir)
    end

    def trans_closure
      return closure - [self]
    end

    def closure
      todo = [self]
      closure = [self]
      while !todo.empty? do
        item = todo.shift
        deps = item.dep_items
        todo |= deps
        closure |= deps
      end
      return closure
    end

    def revision_closure(closure = closure)
      closure.collect do |item|
        item.si_revision
      end.uniq
    end

    def component_closure(revision_closure = revision_closure)
      revision_closure.collect do |revision|
        revision.si_component
      end.uniq
    end

    def <=>(o)
      self.id <=> o.id
    end

    def tr_deps
      return extent
    end

    def extent
      set = []
      as_nodes do |n|
        set |= [n]
      end
      return set
    end


    def each_dep
      si_deps.each do |d|
        yield d
      end
    end

    def as_nodes
      yield self
      each_dep do |dep|
        dep.as_nodes do |n|
          yield n
        end
      end
    end
    
    def as_edges
      each_dep do |dep|
        yield self, dep
        dep.as_edges do |n1, n2|
          yield n1, n2
        end
      end
    end

    def edges
      result = []
      as_edges do |n1, n2|
        result << [n1, n2]
      end
      return result.uniq
    end
  
    def targz_version
      return "#{informative_version}pre.#{version}.#{id}"
    end
    
    def targz
      return "#{name}-#{targz_version}.tar.gz"
    end
    
    def bundle_targz
      return "#{name}-bundle-#{targz_version}.tar.gz"
    end


    def to_s
      return "<#{id}:#{si_revision}:#{success}>"
    end

  end

  class SiRelease < ActiveRecord::Base
    # fields: version
    belongs_to :si_component
    belongs_to :si_item 
  end

  class SiResult < ActiveRecord::Base
    # fields: command, output, success
    belongs_to :si_item
  end

  # Based on a view: no updates!
  
  class SiBuild < ActiveRecord::Base
    belongs_to :si_item
    #fields name, version, informative_version
  end

  class DBStore
    include Utils::SimpleDiff
    include Utils::UnameDir

    def initialize(dbconf)
      @dbconf = dbconf
    end


    def set_log(log)
      @log = log
    end

    def connect
      ActiveRecord::Base.establish_connection(@dbconf)
    end

    def disconnect
      ActiveRecord::Base.remove_connection
    end
    

    def has_release_for_package_version(component, version)
      c = db_component(component)

      # Alternative implementations of si_releases: bool column in items
      # select * from si_items i, si_revisions r
      # where
      #   i.released == true and
      #   i.si_revision_id = r.id
      #   r.si_component_id = ? (c.id)
      #   r.informative_version = ? (version)


      rs = SiItem.find_by_sql("select si_items.* from si_items, si_revisions where si_items.released = 't' and si_items.si_revision_id = si_revisions.id and si_revisions.si_component_id = #{c.id} and si_revisions.informative_version = '#{version}'")
      
      #SiRelease.find(:all, :conditions => 
      #                    ['si_component_id = ? and version = ?', c.id, version])
      if rs.empty? then
        return false
      end
      return true    
    end


    def has_item_for_target?(target)
      return contains_revision?(target.host, target.config, target.revision)
    end

    def last_item_for_target(target)
      begin
        # In this context we can call this function.
        return latest_item(target.host, target.config, target.revision)
      rescue RuntimeError
        return nil
      end
    end

    def item_for_target(target, dep_items)
      h, c, r = host_config_revision(target.host, target.config, target.revision)
      s = target.db_session

      item = nil
      SiItem.transaction do
        item = SiItem.new(:si_config => c, :si_host => h, :si_revision => r, 
                          :si_session => s, :si_results => [],
                          :success => false, :progress => true)

        # This save is essential!!!
        item.save
        dep_items.each do |dep|
          # @log.warn("********* SAVING: #{dep}")
          # dep.save
          item.si_deps << dep
          # @log.warn("********* Add  #{dep} to si_deps of #{item}")
          # @log.warn("********* Saved #{item}")
          # @log.warn("********* Dep_items:: #{item.dep_items}")
          # @log.warn("********* Si_deps:: #{item.si_deps}")        
        end
        item.save
      end
      @log.info("saved item for #{target.revision}: #{item}")
      return item
    end

    def has_item_for_target_modulo_config_and_host?(target)
      h, c, r = host_config_revision(target.host, target.config, target.revision)
      item = SiItem.find(:first, :conditions => ['si_revision_id = ?', r.id])
      return !item.nil?
    end

    ## Refactor the three below!!!
    def latest_item(host, config, revision)
      h, c, r = host_config_revision(host, config, revision)
      item = SiItem.find(:first, 
                         :conditions => ['si_host_id = ? and si_config_id = ? and si_revision_id = ?',
                                         h.id, c.id, r.id],
                         :order => 'id desc')
      if item.nil? then
        raise RuntimeError.new("latest_item called but revision is not available: #{revision}")
      end
      return item
    end


    def contains_revision?(host, config, revision)
      begin
        item = latest_item(host, config, revision)
        return true
      rescue RuntimeError => e
        return false
      end
    end


    def save(item)
      SiItem.transaction do
        item.save
      end
    end

    def host_config_revision(host, config, revision)
      h = db_host(host)
      c = db_config(config)
      r = db_revision(revision)
      return h, c, r
    end

    def db_platform
      s = platform()
      p = SiPlatform.find(:first, :conditions => ['kernel_name = ? and kernel_release = ? and hardware_platform = ? and hardware_class = ? and processor_type = ?', s.kernel_name,
                                                  s.kernel_release,
                                                  s.hardware_platform,
                                                  s.hardware_class,
                                                  s.processor_type])

      if not p then
        p = SiPlatform.new(
                           :kernel_name => s.kernel_name,
                           :kernel_release => s.kernel_release,
                           :hardware_platform => s.hardware_platform,
                           :hardware_class => s.hardware_class,
                           :processor_type => s.processor_type)

        p.save
      end
      return p
    end

    def db_host(host)
      h = SiHost.find(:first, :conditions => ['uname = ?', host])
      if h.nil? then
        p = db_platform
        h = SiHost.new(:uname => host, :si_platform => p)
        h.save
      end
      return h
    end

    def db_session(time)
      s = SiSession.find(:first, :conditions => ['time = ?', time])
      if s.nil? then
        s = SiSession.new(:time => time)
      end
      return s
    end

    def db_component(component)
      name = component.name
      c = SiComponent.find(:first, :conditions => ['name = ?', name])
      if c.nil? then
        c = SiComponent.new(:name => name)
        c.save
      end
      return c
    end

    def db_revision(revision)
      c = db_component(revision.component)
      r = SiRevision.find(:first, :conditions => ['si_component_id = ? and version = ?', 
                                                  c.id, revision.version])
      if r.nil? then
        r = SiRevision.new(:si_component => c, :version => revision.version, 
                           :informative_version => revision.checkout.extract_version)
        pred = r.predecessor
        changelog = revision.changelog
        if pred.nil? then
          # r is the first revision of this component
          r.changelog_diff = changelog
        else
          lines = []
          changelog.each_line do |line|
            pattern = Regexp.quote(line)
            if pred.changelog_diff.match(/^#{pattern}/) then
              break
            end
            lines << line
          end
          r.changelog_diff = lines.to_s
        end
        r.save
      end
      
      return r
    end

    def db_profile(profile)
      p = SiProfile.find(:first, :conditions => ['name = ? and version = ?',
                                                 profile.name, profile.version])
      if p.nil? then
        p = SiProfile.new(:name => profile.name, :version => profile.version)
        p.save
      end
      return p
    end

    def db_config(config)
      p = db_profile(config.profile)
      sov = config.sources.version
      scv = config.script.version
      c = SiConfig.find(:first, :conditions => 
                        ['si_profile_id = ? and sources_version = ? and script_version = ?',
                         p.id, sov, scv])
      if c.nil? then
        c = SiConfig.new(:si_profile => p, :sources_version => sov,:script_version => scv)
        c.save
      end
      return c
    end    

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
  c.save
end
