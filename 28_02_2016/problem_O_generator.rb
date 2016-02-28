n = gets.to_i

if n < 10
    puts n
else
    count = 9
    num = 10
    while true
        good_num = true
        num_as_str = num.to_s
        for i in 1...(num_as_str.size)
            digit_l = num_as_str[i - 1].to_i
            digit_r = num_as_str[i].to_i
            if (digit_r - digit_l).abs != 1
                good_num = false
                break
            end
        end
        if good_num
            count = count + 1
            print "#{num},"
        end
        if count == n
            puts num
            break
        end
        num = num + 1
    end
end
