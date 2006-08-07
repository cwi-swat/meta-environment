
require 'rexml/document'

module Subversion
  include REXML

  # this module assumes a method location
  # which returns a valid subversion URL

  def changes_since(path, from, to = "HEAD")
    if from.is_a?(Time) then
      return changes_since_time(path, from, to)
    else
      return changes_since_revision(path, from, to)
    end
  end

  def last_changed_revision_at(path, time = nil)
    info = info(path, time)
    if info =~ /Last Changed Rev: ([0-9]+)/m then
      return Integer($1)
    end
    raise RuntimeError.new("subversion didn't behave as expected: #{info.split.inspect}")    
  end

  def read(path, revision = nil)
    return cat(path, revision)
  end

  def exist?(path, revision = nil)
    if info(path, revision).rstrip =~ /\(Not a valid URL\)/  then
      return false
    end
    return true
  end

  def checkout(path, dirname = File.split(path).last, revision = nil)
    svn_command('checkout', path, revision, dirname)
  end


  def ensure_path(path)
    # TODO
  end

  private 

  def url_for(path)
    return File.join(location, path)
  end

  def svn(options, revision = nil)
    revision_str = revision_option(revision)
    cmd = "svn #{revision_str} #{options}"
    return `#{cmd}`
  end

  def svn_command(command, path, revision, options = nil)
    return svn("#{command} #{url_for(path)} #{options}", revision)
  end

  def revision_option(revision)
    if revision then
      if revision.is_a?(Time) then
        time_str = svn_time(revision)
        return "--revision {#{time_str}}"
      else
        return "--revision #{revision}"
      end      
    end
    return ''
  end

  def svn_time(time)
    time.strftime("%Y%m%dT%H%M")
  end

  def info(path, revision = nil)
    return svn_command('info', path, revision)
  end

  def cat(path, revision = nil)
    return svn_command('cat', path, revision)
  end

  def changes_since_revision(path, from_revision, to_revision)
    return changes_in_range(path, "#{from_revision}:#{to_revision}")
  end

  def changes_since_time(path, from_time, to_revision)
    time = svn_time(from_time)
    return changes_in_range(path, "{#{time}}:#{to_revision}")
  end

  def changes_in_range(path, range)
    log = `svn log --xml --verbose --revision #{range} #{location}/#{path}`
    xml = Document.new(log)
    changes = {}
    xml.elements.each('log/logentry') do |entry|
      changes[entry_revision(entry)] = entry_paths(entry)
    end
    return changes
  end

  def entry_revision(entry)
    return Integer(entry.attributes['revision'])
  end
    
  def entry_paths(entry)
    result = []
    entry.elements.each('paths/path') do |path|
      result << path.text
    end
    return result
  end


end
