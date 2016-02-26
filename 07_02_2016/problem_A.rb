#!/usr/bin/env ruby
n = gets.chomp.to_i
h = {}
for i in 0...n
  word = gets.chomp
  c = word[0]
  unless h.has_key?(c)
    h[c] = []
  end
  h[c].push(word)
end
puts h.size
for a in h.keys.sort
  puts h[a].sort.join(' ')
end
