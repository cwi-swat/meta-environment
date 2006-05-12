
module SimpleDiff

  def simple_diff(newer, older)
    if newer =~ /^(.*)#{older}$/m then
      return $1
    end
    raise "#{older} is not a suffix of #{newer}"
  end
  
  def diff_diff(newer, diff)
    if newer =~ /^(.*)#{diff}/m then
      return $1
    end
    puts "Newer #{newer}"
    puts "Diff: #{diff}"
    #exit 0
    raise "#{diff} is not a suffix of #{newer}"
  end

end

if $0 == __FILE__ then
  include SimpleDiff
  newer = "xyzabcd"
  older = "abcd"

  puts simple_diff(newer, older)
  puts simple_diff(older, newer) 
end

#########################################
#########################################
