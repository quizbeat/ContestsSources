#!/usr/bin/env ruby
a = gets.chomp
h = {}
count = 0
for i in 0...a.size
  if h.has_key?(a[i])
    h[a[i]] += 1
  else
    h[a[i]] = 1
    count += 1
  end
end
if count <= 2
  puts 0
else
  m = h.values.sort
  sum = 0
  n = m.size - 2
  for i in 0...n
    sum += m[i]
  end
  puts sum
end
