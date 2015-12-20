#!/usr/bin/env ruby
def func(l, r)
  if l < r
    (l ** func(l+1, r))%10
  else
    r%10
  end
end
a, b = gets.split.map {|x| x.to_i}
puts func(a,b)
