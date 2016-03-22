n, d = gets.split(' ').map(&:to_i)

if n == 1
    puts "#{n} #{d}"
    exit
end

nn = n
dd = d

arr = []

while true
    nn, dd = dd, nn
    val = nn / dd
    arr.push(val)
    nn = nn - dd * val
    if nn == 1
        arr.push(dd)
        break
    end
end

nn = 1
dd = arr.first

for i in (1...arr.size)
    nn = arr[i] * dd + nn
    nn, dd = dd, nn
end

puts "#{nn} #{dd}"
