n = gets.to_i

data = Array.new

for i in 0...n
    s = gets.chomp
    data.push(s)
end

data.each do |s|
    begin
        s_copy = s.clone
        s.gsub!(/0{2}/,'')
        s.gsub!(/1{3}/,'')
    end until s == s_copy
end

h = Hash.new()

data.each_index do |i|
    s = data[i]
    if h[s] == nil
        h[s] = Array.new
    end
    h[s].push(i + 1)
end

res = Array.new

h.each_value do |v|
    res.push(v)
end

res.sort! do |a, b|
    a.first <=> b.first
end

puts "#{res.size}"

res.each do |l|
    l.each do |x|
        print "#{x} "
    end
    puts
end
