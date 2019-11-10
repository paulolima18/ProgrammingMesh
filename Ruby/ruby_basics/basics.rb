#Basic Ruby sintax
puts("Hello World!\n---\nShop 101")

number_cars = 10
number_buyers = 5
unsold_cars = number_cars - number_buyers

puts("Number of unsold cars is: #{unsold_cars}")

string1 = "---\nEarth is "
string2 = "nice"
string1 = string1 + string2

#Printing the mix of string1 and string2
puts string1

#Formatting Strings
formatter = "---\n%{first} %{second} %{third}"

#Puts changes lines
puts formatter % {first:1,second:2,third:3}

#Print doens't change line
print formatter % {first:"one",second:"two",third:"three"}

#Ugly way to not repeat \n
puts %q{
"this is one line"
"this is other line"
}

#Tabs and "\" in strings
city_tabbed = "---\n\t*New York!"
city_backslash = "---\nNew \\ York!"

cities = """---\n
\t*New York!
\t*London!
"""
puts city_tabbed
puts city_backslash
puts cities

#Input & Output
print "What's your age? -> "
age = $stdin.gets.chomp.to_i

print "What's your name? -> "
name = $stdin.gets.chomp

print "Choose a number!"
result = $stdin.gets.chomp
result = result.to_i+10 # Can also do ".to_f" making a change to float

puts "So #{name}, you are #{age} years old!\n\t*The Result is: #{result}"
