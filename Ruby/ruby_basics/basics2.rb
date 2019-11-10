#Example on how to run -> ruby basics2.rb 1 2 3 text.txt

#Gets Information and then prints it
first,second,third,filename= ARGV
puts "Arguments\n\t*One:#{first}\n\t*Two:#{second}\n\t*Three:#{third}"

#Uses the name of the file given and creates a file object
file = open(filename)

#Safer and more specific way of opening a file
#file = open(filename, 'w')
#file = open(filename, 'a')
#file = open(filename, 'r+')

#Print what is in the filename
#puts file.gets.chomp -> To get just a line from the file
#seek && readline
print file.read


#Closing file
file.close

#Simple function
def prints(*args)#arg1,arg2,arg3
  arg1,arg2,arg3 = args
  puts("First is #{arg1}\nSecond is #{arg2}\nThird is #{arg3}")
end

#Calling function
prints(first,second,third)
