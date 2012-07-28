
require 'changes'

class Scenarios
  PKGS = ['aterm', 'balanced-binary-aterms', 'dummy', 'relational-aterms']
  BUILD_ENV = ['meta-autotools', 'meta-build-env']
  ALL_PKGS = PKGS + BUILD_ENV


  def initialize(repository, workdir)
    @repository = repository
    @checkouts = {}
    ALL_PKGS.each do |pkg|
      @checkouts[pkg] = Checkout.new(repository, pkg, workdir)
    end
  end

  def init
    clean_slate_scenario(true).commit
  end

  def checkout(pkg)
    return @checkouts[pkg]
  end

  def top
    return checkout('relational-aterms')
  end

  def middle
    return checkout('balanced-binary-aterms')
  end

  def dummy
    return checkout('dummy')
  end

  def bottom
    return checkout('aterm')
  end


  def clean_slate_scenario(build_build_env = false)
    pkgs = PKGS
    if build_build_env then
      pkgs += BUILD_ENV
    end
    changes = pkgs.collect do |pkg|
      HarmlessChange.new(checkout(pkg))
    end
    return Transaction.new(changes)
  end    

  def change_propagation_scenario
    ch = HarmlessChange.new(bottom)
    return Transaction.new([ch])
  end

  def build_reuse_scenario
    return Transaction.new([HarmlessChange.new(top)])
  end

  def backtracking_scenario
    # Only with available earlier builds
    # e.g. after a clean slate run
    ch1 = HarmlessChange.new(dummy)
    ch2 = BreakingChange.new(bottom)
    return Transaction.new([ch2, ch1])
  end

  def breaking_change_transaction(pkg)
    return Transaction.new([BreakingChange.new(checkout(pkg))])
  end

  def harmless_change_transaction(pkg)
    return Transaction.new([HarmlessChange.new(checkout(pkg))])
  end
  
end

