n = gets.to_i

if n == 1
    puts "? 1"
    STDOUT.flush
    puts "! #{gets}"
    STDOUT.flush
    exit
end

idx1 = 1
idx2 = 2

l = 1
r = n

a = 0
b = 0

while true

    # puts "l = #{l}"
    # puts "r = #{r}"

    idx1 = (l + r) / 2
    if idx1.even?
        idx1 = idx1 - 1
    end
    idx2 = idx1 + 1

    if idx2 > n or l == r
        puts "? #{idx1}"
        STDOUT.flush
        a = gets.to_i
        puts "! #{a}"
        STDOUT.flush
        exit
    end

    # puts "idx1 = #{idx1}"
    # puts "idx2 = #{idx2}"

    puts "? #{idx1}"
    STDOUT.flush
    a = gets.to_i
    puts "? #{idx2}"
    STDOUT.flush
    b = gets.to_i

    if a != b
        r = idx1
    else
        l = idx2 + 1
    end

end
