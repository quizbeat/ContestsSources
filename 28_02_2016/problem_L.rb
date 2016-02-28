n = gets.to_i
counter = 0
state = 'a'
a = n
while a > 1
  if state == 'a'
    if a&1 == 1
      state = 'c'
    else
      state = 'b'
    end
    counter += (a.to_f / 2.0).ceil
  elsif state == 'b'
    d = a / 2
    counter += d
    a -= d
    state = 'a'
  else
    state = 'a'
    d = (a.to_f / 2.0).ceil
    counter += d
    a += d
  end
end
puts counter
