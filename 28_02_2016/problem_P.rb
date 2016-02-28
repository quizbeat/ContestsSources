t = gets.to_i

t.times do
    medals = gets.split(' ').map(&:to_i)
    temp = medals.each_slice(3).to_a
    berland = temp.first
    byteland = temp.last
    # test Win
    berland_count = berland.inject(:+)
    byteland_count = byteland.inject(:+)
    count_win = false
    if (berland_count > byteland_count)
        count_win = true
    end
    # test Quality
    quality_win = false
    if berland[0] > byteland[0]
        quality_win = true
    elsif berland[0] == byteland[0] and
          berland[1] > byteland[1]
          quality_win = true
    elsif berland[0] == byteland[0] and
          berland[1] == byteland[1] and
          berland[2] > byteland[2]
          quality_win = true
    end
    if count_win and quality_win
        puts "Win"
    elsif count_win
        puts "Count"
    elsif quality_win
        puts "Quality"
    else
        puts "None"
    end
end
