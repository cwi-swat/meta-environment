module Versioning

  class Revision
    attr_reader :deps, :component, :version, :checkout

    def Revision.from_checkout(component, checkout)
      revision = Revision.new(component, checkout.version, checkout)
      checkout.extract_deps.each do |d|
        revision.add_dep(Component.new(d))
      end
      return revision
    end

    def initialize(component, version, checkout = nil)
      @component = component
      @version = version
      @checkout = checkout
      @deps = []
    end


    def add_dep(component)
      @deps |= [component]
    end

    def name
      return component.name
    end

    def virtual?
      return false
    end

    def implicit?
      return false
    end

    def changelog
      return @checkout.changelog
    end


    def eql?(revision)
      return @component.eql?(revision.component) &&
        @version.eql?(revision.version)
    end

    def ==(revision)
      return  (revision.component == @component) &&
        (revision.version == @version)
    end

    def hash
      s = "#{@component.hash}#{@version.hash}"
      return s.hash
    end

    def prefix(root)
      #subdir = "rev_#{version}"
      #return File.join(component.prefix(root), subdir)
      return component.prefix(root)
    end

    def checkout_path
      return checkout.path
    end

    def to_s
      return "<#{component}, #{version}>"
    end
  end

  class ImplicitDependencyRevision < Revision
    def implicit? 
      return true
    end
  end                    


  class VirtualRevision < Revision
    def initialize(component)
      @component = component
    end

    def virtual?
      return true
    end

    def to_s
      return @component.to_s
    end

  end




  class CheckoutFactory 
    def initialize(repositories, externals, repo_factory, vcs_user, checkout_dir, time)
      @repositories = repositories
      @externals = externals
      @repo_factory = repo_factory
      @vcs_user = vcs_user
      @checkout_dir = checkout_dir
      @time = time
    end

    def checkout(component)
      repo = @repo_factory.repository(component.name, @repositories)
      return repo.checkout(@vcs_user, @time, component.name, @checkout_dir)
    end

    def trunk_checkout(component)
      repo = @repo_factory.repository(component.name, @repositories)
      return repo.trunk_checkout(@vcs_user, component.name, @checkout_dir)
    end

  end

  class RevisionFactory < CheckoutFactory

    def trunk_revision(component)
      if @externals.include?(component.name)
        return VirtualRevision.new(component)
      end
      revision = Revision.from_checkout(component, trunk_checkout(component))
      return revision
    end

    def updated_revision(component)
      return revision(component)
    end

    def clean_revision(component)
      return revision(component)
    end

    def revision(component)
      if @externals.include?(component.name)
        return VirtualRevision.new(component)
      end
      return repository_revision(component)
    end

    def repository_revision(component)
      revision = Revision.from_checkout(component, checkout(component))
      return revision
    end

  end


end
