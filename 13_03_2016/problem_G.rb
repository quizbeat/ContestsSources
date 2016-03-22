n = gets.to_i
data = gets.split(' ').map(&:to_i)

h = Hash.new
data.each do |item|
    el = h[item]
    if el == nil
        h[item] = 1
    else
        h[item] = el + 1
    end
end

top = 0
h.each_value do |val|
    if val > top
        top = val
    end
end
puts top
