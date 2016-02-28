t = gets.to_i

t.times do
    inp = gets.split(' ').map(&:to_i)

    n = inp.first
    x = inp.last

    first_class = true
    if n % 4 == 0 or (n + 1) % 4 == 0
        first_class = false
    end

    nums = []

    if first_class
        #nums = (1..n).step(2).to_a
        if !x.even? and x <= n
            puts 'YES'
        else
            puts 'NO'
        end
    else
        #nums = (0..n).step(2).to_a
        if x.even? and x <= n
            puts 'YES'
        else
            puts 'NO'
        end
    end
end
