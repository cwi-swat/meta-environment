module Versioning
  require 'versioning/boms'
  require 'ostruct'

  class Revision
    attr_reader :deps, :component, :version, :checkout

    def Revision.from_checkout(component, checkout)
      revision = Revision.new(component, checkout.version, checkout, checkout.repository)
      checkout.extract_deps.each do |d|
        revision.add_dep(Component.new(d))
      end
      return revision
    end

    def initialize(component, version, checkout = nil, repository = nil, user = nil, time = nil, checkout_dir = nil)
      @component = component
      @version = version
      @checkout = checkout
      @repository = repository
      @user = user
      @time = time
      @checkout_dir = checkout_dir
      @deps = []
    end

    def version 
      if @version == nil then
        @version = @repository.version(@user, @time, @component.name)
      end
      return @version
    end

    def deps
      pkgconfig = @repository.svn_cat_pkgconfig_file(@user, component.name, @time)
      PKGConfigBOMReader.from_text(pkgconfig).dependencies.each do |dep|
        add_dep(Component.new(dep))
      end
      return @deps
    end

    def checkout
      #create checkout for component and version
      if not @checkout then
        @checkout = @repository.checkout(@user, @time, component.name, @checkout_dir)
        @version = checkout.version
      end
      return @checkout
    end

    def dep_names
      return @deps.collect do |dep|
        dep.name
      end
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
      return @checkout.path
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

      # nieuw:
      repo = @repo_factory.repository(component.name, @repositories)
      version  = nil
      # the horror, the horror....
      #checkout = OpenStruct.new
      #checkout.path = File.join(@checkout_dir, component.name)
      # </dirty-hack>
      checkout = trunk_checkout(component)
      revision = Revision.new(component, version, checkout, repo, @vcs_user, @time, @checkout_dir)

      return revision

      # oud
      #revision = Revision.from_checkout(component, trunk_checkout(component))
      #return revision
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
      # oud:
      #revision = Revision.from_checkout(component, checkout(component))

      # nieuw:
      repo = @repo_factory.repository(component.name, @repositories)
      version  = nil
      checkout = nil
      revision = Revision.new(component, version, checkout, repo, @vcs_user, @time, @checkout_dir)

      return revision
    end

  end


end
