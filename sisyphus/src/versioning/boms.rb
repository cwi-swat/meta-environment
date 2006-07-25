module Versioning

  class BOMReader
    def initialize(path)
      File.open(path) do |f|
        @bom = f.read
      end
    end    
  end

  class PackageBOMReader < BOMReader
    def version
      if @bom =~ /version\s*=\s*([0-9\.a-bA-Z_\-]+)/m then
        return $1
      end
      raise RuntimeError.new("error parsing version in: #{text}")
    end

    def dependencies
      requires = @bom
      requires.sub!(/.*requires/m, '')
      requires.sub!(/configuration.*/m, '')
      requires.squeeze!("\n")
      requires.strip!
      return remove_versions(requires.split("\n"))
    end

    private

    def remove_versions(deps)
      return deps.collect do |dep|
        dep.split[0]
      end.uniq
    end  

  end

  class PKGConfigBOMReader < BOMReader
    def version
      if @bom =~ /Version\s*:\s*([0-9\.a-bA-Z_\-]+)/m then
        return $1
      end
      raise RuntimeError.new("error parsing version in: #{@bom}")
    end

    def dependencies
      if @bom =~ /^Requires\s*:\s*([^\n]*)/m then
        return $1.split(/[, ]/)
      end
      return []
      #raise RuntimeError.new("error parsing dependencies in: #{@bom}")
    end

  end

end
