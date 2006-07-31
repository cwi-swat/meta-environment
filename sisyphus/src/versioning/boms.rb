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
      each do |line|
        if line =~ /^Version\s*:\s*([0-9\.a-bA-Z_\-]+)$/ then
          return $1
        end
      end
      raise RuntimeError.new("error parsing version in: #{@bom}")
    end

    def emails
      each do |line|
        if line =~ /^Maintainers\s*=\s*([^\n]*)$/ then
          return $1.split(',')
        end
      end
      return []
    end

    def dependencies
      each do |line|
        if line =~ /^Requires\s*:\s*([^\n]*)$/ then
          return $1.split(/[, ]/)
        end
      end
      return []
    end

    def each
      @bom.each do |line|
        yield line
      end
    end

  end

end
