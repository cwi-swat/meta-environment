
module Builder

  class NewBuilder
    def initialize(revision, items)
      # assert items match revision.deps
      @revision = revision
      @items = items
    end

    def build
      # assert items have entries in bin subversion
      # checkout prefixes of each item in @items
      # checkout sources of @revision
      # run every build action
      # return an item.
    end

  end

end
