

module Product

  def product(set1, set2)
    result = []
    set1.each do |x|
      set2.each do |y|
        result << [x,y]
      end
    end
    return result
  end

  def product_space(powerset)
    return power_product(powerset)[0].collect do |set|
      set.flatten
    end
  end

  private
  def power_product(powerset)
    if powerset.empty?
      return []
    end
    if powerset.length == 1 then
      return powerset
    end
    head = powerset[0]
    tail = powerset[1..-1]
    rec = power_product(tail)
    result = []
    rec.each do |set|
      result << product(head, set)
    end
    return result
  end

end

if __FILE__ == $0 then
  require 'pp'
  include Product
  pp product_space([[1,2,3], [4,5], [6,7], [7,8]])
end
