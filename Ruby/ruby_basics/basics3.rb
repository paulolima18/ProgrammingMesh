array = [1,2,3,4,5]

#Most common for loop
for number in array
  puts "\t*It's the number #{number}\n"
end

#Ruby way
array.each do |number|
  puts "More numbers #{number}\n"
end

#array.each {|number| puts "Stuff #{number}"}

water = ["frozen","gas"]
water << "liquid"
puts water

#A while loop
i = 0
while i < 5
  i = i+1
  puts i
end

#Typical Class in ruby
class Song

  def initialize(lyrics)
    @lyrics = lyrics
  end

  def printSong()
    @lyrics.each {|line| puts "#{line}"}
  end
end

#Creating an object
myLife = Song.new(["\n *Queen: The Show Must Go On",
  "Empty spaces, what are we living for?",
 "Abandoned places, I guess we know the score, on and on",
 "Does anybody know what we are looking for?",
 "Another hero, another mindless crime",
 "Behind the curtain, in the pantomime",
 "Hold the line",
 "Does anybody want to take it anymore?"])

myLife.printSong()
