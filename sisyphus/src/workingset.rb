

def workingset(components, success)
  puts "components: #{components.join(', ')}"
  cursor = success.max
  puts "cursor init: #{cursor}"
  loop do
    current = []
    i = 0
    todo = components
    puts "\ttodo: #{todo.join(', ')}"
    while !todo.empty? do
      puts "\t\ti: #{i}"
      return [] if cursor - i < 0
      build = success[cursor - i]
      puts "\t\tbuild: #{build}"
      component = build.tree.component
      puts "\t\tcomponent: #{component}"
      if todo.include?(component) then
        current |= [build]
        todo -= [component]
      end
      i += 1
    end
    return current if yield current
  end
end
