
require 'optparse'
require 'ostruct'
require 'yaml'
require 'distconf'
require 'updater'

class MyLog
  alias :info :warn

  def info(txt)
    $stderr << "#{txt}\n"
  end
end

class CommandLineParser
  def self.parse(args)
    options = OpenStruct.new
    options.prefix = nil
    options.url = nil
    options.verbose = false


    opts = OptionParser.new do |opts|

      opts.banner = """Usage: syrup [options] package
"""
      opts.separator ""    
      opts.separator "Options:"


      opts.on("-p Prefix", "--prefix Prefix",
              "Installation prefix") do |prefix|
        options.prefix = prefix
      end

      opts.on("-u URL", "--url URL",
              "SVN Release repository URL") do |url|
        options.url = url
      end
      
      opts.on("-h", "--help",  "Display usage") do |x|
        puts opts
        exit
      end


      opts.on("-v", "--[no-]verbose", "Run verbosely") do |v|
	options.verbose = v
      end
    end

    opts.parse!(args)
    if not (options.prefix && options.url) then
      $stderr << "#{opts}\n"
      exit(1)
    end
    return options
  end
end


def pick_candidate(pkg, dist_conf, current)
  table = dist_conf.package_candidates(pkg)
  pick = {}
  i = 1
  puts "Pick a release for #{pkg}"
  table.keys.sort.reverse.each do |revision|
    puts " - Revision: #{revision}"
    table[revision].sort.reverse.each do |candidate|
      if i < 30 then
        if current[0] == revision and current[1] == candidate then
          $stdout << ' * '
        else
          $stdout << '   '
        end
        puts sprintf(" [%2d] %d", i, candidate)
        pick[i] = [revision, candidate]
        i += 1
      else
        break
      end
    end
  end
  $stdout << "> "
  picked = $stdin.gets.to_i
  if picked == 0 then
    return current
  end
  return pick[picked]
end

if $0 == __FILE__ then
  options = CommandLineParser.parse(ARGV)
  if ARGV == [] then
    CommandLineParser.parse(['-h'])
  end
  pkg = ARGV[0]
  log = Logger.new(STDERR)
  log.level = Logger::ERROR
  if options.verbose then
    log = MyLog.new
  end
  dist_conf = DistributionConfiguration.new(options.url)
  updater = SisyphusUpdater.new(dist_conf, log)
  prefix = options.prefix
  current = updater.current_version(prefix)
  revision, candidate = pick_candidate(pkg, dist_conf, current)
  if [revision, candidate] != current then
    updater.install(pkg, revision, candidate, prefix)  
  end
end
