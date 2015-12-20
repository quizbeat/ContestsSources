#!/usr/bin/env ruby
def calc_sum(m, i)
  s = 0
  for a in m do
    s += Math.sqrt((a-i)*(a-i) + 1)
    i += 1
  end
  return s
end
n = gets.to_i
r = gets.split.map{|x| x.to_i}
c = gets.split.map{|x| x.to_i}
m = (r + c).sort
x = 0
step = 1000000
sum_curr = calc_sum(m, x)
sum_prev = sum_curr + 1
sign = 1
x += step
while ((sum_prev-sum_curr).abs > 0.0000000001)
  sum_prev = sum_curr
  sum_curr = calc_sum(m, x)
  if sum_curr > sum_prev && sign == 1
    sign = -1
    step /= 2.0
    sign_counter = 0
  elsif sum_curr > sum_prev && sign == -1
     sign = 1
     step /= 2.0
     sign_counter = 0
  end
  x += step*sign
end
puts sum_curr
