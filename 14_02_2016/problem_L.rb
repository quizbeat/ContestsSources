#!/usr/bin/env ruby
a = gets.split(' ').map(&:to_i)
b = gets.split(' ').map(&:to_i)
as = a.sort.join('')
bs = b.sort.join('')
if (a[0]**2 + a[1]**2 == a[2]**2 ||
  a[0]**2 + a[2]**2 == a[1]**2 ||
  a[2]**2 + a[1]**2 == a[0]**2 &&
  as == bs)
  puts 1
else
  puts 0
end
