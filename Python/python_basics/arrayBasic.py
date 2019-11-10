#import copy
##list1 = [1,[2],3]
##list = copy.deepcopy(list1)
##[[i for i in elem] for elem in [[1,2,3],[4,5,6]]]
##[i for elem in [[1,2,3],[4,5,6]] for i in elem]
##enumerate

def length(array):
    return len(array)

def itSelf(array):
    return array

def reverse(array):
    array.reverse()
    return array

def middle(array):
    array.pop(len(array)-1)
    array.pop(0)
    return array

def minMax(array):
    array.sort()
    return [array[0],array[len(array)-1]]

def sumAll(array):
    d = 0
    for i in array:
        d+= i
    return d

if __name__ == "__main__":
    nlist = [1,2,4,5,3]
    number = sumAll(nlist)
    print(number)
