import random

#Retrieves the sum of Even and Odd numbers in a list
def evenOdd(array):
    even = 0
    odd = 0
    for value in array:
        if value%2 == 0:
            even+= value
        else:
            odd+= value
    print(array,even,odd)

#Ex: Insert 1º element of l1 and then 1º elem l2 and then 2º elem l1 and ...
def insertionOrder(list1,list2):
    size = len(list1)
    list3 = []
    for i in range(size):
        list3.append(list1[i])
        list3.append(list2[i])
    return list3

#Retrieves the number of elements bigger than "n"
def biggerThan(n,array,start=0):
    for i in array:
        if n > i:
            k+= 1
    return k

#Function that gives the probability of two "dices" giving an even number
def evenCount(n):
    count = 0
    for i in range(n):
        dice1 = random.randint(1,6)
        dice2 = random.randint(1,6)
        if dice1%2 == 0:
            count+= 1
        elif dice2%2 == 0:
            count+= 1
    return (count/n)

#Sums the previous element in a list
def previousSum(array):
    array2 = [sum(array[:i+1]) for i in range(len(array))]
    return array2

#Given a list of lists it gives back itself
def lists(lst):
    return [[elem for elem in array] for array in lst]
