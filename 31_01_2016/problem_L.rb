#!/usr/bin/env ruby
a = gets.chomp
b = gets.chomp
i = 0
j = 0
f = false
fc = b[0]
while j < b.length do
  if fc != b[j]
    f = true
  end
  if i < a.length && a[i] == b[j]
    i += 1
    j += 1
  elsif i == 0
    puts 'No'
    exit
  else
    if b[j-1] == b[j] && !f
      puts 'No'
      exit
    end
    j += 1
  end
end
if i == a.length
  puts 'Yes'
else
  puts 'No'
end
