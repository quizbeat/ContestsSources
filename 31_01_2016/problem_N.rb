input = gets.split(' ').map(&:to_i)
games = input.first
score = input.last

wins = score / 3
ties = 0
losses = 0

while wins > games
    wins = wins - 1
end

while wins > -1
    ties = score - wins * 3
    losses = games - wins - ties
    break if ties < 0 or losses < 0
    puts "#{wins} #{ties} #{losses}"
    wins = wins - 1
end
