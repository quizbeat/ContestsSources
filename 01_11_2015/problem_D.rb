n = gets.to_i
m = (1e+9 + 7).to_i

amount = Array.new(1e+5 + 1)
sum_for_pos = Array.new(1e+5 + 1)

k = 5

amount[1] = 1
amount[2] = 2
amount[3] = 2
amount[4] = 4

sum_for_pos[1] = 1
sum_for_pos[2] = 3
sum_for_pos[3] = 5
sum_for_pos[4] = 9

while k <= n do
    max_next_k = k / 2
    amount[k] = (1 + sum_for_pos[max_next_k])
    sum_for_pos[k] = sum_for_pos[k - 1] + amount[k]
    k += 1
end

answer = (amount[n] % m)

puts answer
