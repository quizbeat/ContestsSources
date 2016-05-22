t = gets.to_i
t.times do
    n = gets.to_i
    data = Array.new(n)
    for i in 0...n
        data[i] = gets.split(' ').map(&:to_f)
    end

    d = Array.new(10)

    for i in 0...n
        d[i] = 1;
        for j in 0...i
            if data[j].first < data[i].first and data[j].last > data[i].last
                d[i] = [d[i], 1 + d[j]].max
            end
        end
    end

    ans = d[0]
    for i in 0...n
        ans = [ans, d[i]].max
    end
    puts ans

end
