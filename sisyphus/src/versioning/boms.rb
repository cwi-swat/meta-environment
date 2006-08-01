module Versioning

  class BOMReader
    attr_accessor :bom
    def self.from_text(text)
      b = self.new()
      b.bom = text
      return b
    end

    def initialize(path = nil)
      if path then
        File.open(path) do |f|
          @bom = f.read
        end
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
      v = find(/^Version\s*:\s*([0-9\.a-bA-Z_\-]+)$/)
      if not v then 
        raise RuntimeError.new("error parsing version in: #{@bom}")
      end
      return v
    end

    def emails
      e = find(/^Maintainers\s*=\s*([^\n]*)$/)
      return e ? e.split(',') : []
    end

    def dependencies
      d = find(/^Requires\s*:\s*([^\n]*)$/)
      return d ? d.split(/[, ]/) : []
    end

    def find(regexp)
      @bom.each do |line|
        if regexp.match(line)
          return $1
        end
      end
      return nil
    end

  end

end
