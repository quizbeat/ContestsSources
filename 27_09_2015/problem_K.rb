str = gets
str = str + "$"
happy = str.split(":-)")
sad = str.split(":-(")
if happy.size > sad.size
  puts "happy"
elsif happy.size < sad.size
  puts "sad"
else
  puts "neutral"
end
