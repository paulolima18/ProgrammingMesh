def reverse(array): #reverse array
    print(array[::-1])
def middle(array): #select elements in the middle of the array
    print(array[1:-1])
def edges(array): #select only first and last
    print(max(array),min(array))
def totalsum(array): # sum of all elements (countable)
    print(sum(array))
def nlist(n,array): # same list but with n elements
    print([x for x in array if x<=n])

def sum_even_odd(array): # sum of even numbers and odd numbers in array
    par,impar=0,0
    for i in array:
        if i%2==0:
            par+=i
        else:
            impar+=i
    return par,impar

def mix_lists(l1=[1,2,3,4,5,6,7],l2=['a','b','c','d','e']):
    #Ex:[1,a,2,b.....]
    l=[]
    if len(l1)==len(l2):
        for i in range(len(l2)):
            l=l+[l1[i]]+[l2[i]]
    elif len(l1)>len(l2):
        for i in range(len(l2)):
            l=l+[l1[i]]+[l2[i]]
        l=l+l1[len(l2):]
    elif len(l2)>len(l1):
        for i in range(len(l1)):
            l=l+[l2[i]]+[l1[i]]
        l=l+l2[len(l1):]
    return l

def x_smaller(n,array):
    #only numbers smaller than "n"
    return (len([x for x in array if x<n]))

def even_chance(n):
    #probability of sum of two dices being even
    import random
    res = []
    result = 0
    for i in range(n):
        d1 = random.randint(1,6)
        d2 = random.randint(1,6)
        res = res + [d1+d2]
        if (d1+d2)%2 == 0:
            result+= 1
    print(res,'\n',(result/n))

def sequence_sum(array=[1,2,3]):
    #sum one number to the last (Sequential)
    val = 0
    new = []
    for i in array:
        val = val+i
        new = new+[val]
    print(new)

def negative(image):
    import copy
    replace=copy.deepcopy(image)
    for line in range(len(image)):
        for col in range(len(image[0])):
            replace[line][col]^=1
    return replace
#simple way
def vegatives(image):
    import copy
    replace = copy.deepcopy(image)
    for line in range(len(image)):
        for col in range(len(image[0])):
            if replace[line][col]==0:
                replace[line][col]=1
            else:
                replace[line][col]=0
    return replace
##68
def rotation(matrix):
    import copy
    replace=copy.deepcopy(matrix)
    new=[]
    for column in range(len(matrix[0])):
        for line in matrix:
            new+=[line[column]]
    for line in range(len(new)):
        new[line] = new[line]
    return new
##69
def main_turtle(n):
    import turtle
    little = turtle.Turtle()
    guide = controlls(n)
    navigator(guide,little)
    turtle.exitonclick()

def controlls(n):
    import random
    array=[]
    for i in range(n):
        array.append(random.randint(0,3))
    return array

def navigator(com,tart):
    tart.dot('green')
    for i in com:
        if i==0:
            tart.fd(50)
        if i==1:
            tart.left(50)
        if i==2:
            tart.right(50)
        if i==3:
            tart.bk(50)
    tart.dot('red')

##610
def positions(text):
    dicio={}
    for i in range(len(text)):
        if text[i] in 'AEIOUaeiou':
            dicio.setdefault(text[i],[]).append(i)
    print(dicio)

autor={"php":"Rasmus Lerdorf","perl":"Larry Wall","tcl":"John Ousterhout","awk":"Brian Kernighan","java":"James Gosling","parrot":"Simon Cozens","python":"GuidovanRossum","xpto":"zxcv"}
def dict_call(dicio):
    return 'c++' in dicio
    dicio.setdefault(lf[i],[]).append(lq[i])

recipe ={'dreams':'flour', 'French Toast':'bread','cake':'water'}
def upsidown(dicio):
    book={}
    for key,value in dicio.items():
        book.setdefault(value,[]).append(key)
    print(book)

def brother(a,i1,i2):
    for key in a.keys():
        if i1 in a[key]:
            i1=key
        if i2 in a[key]:
            i2=key
        return i2==i1

def grand_children(a,p):
    arrayn = []
    for key,value in a.items():
        if p == key:
            for i in value:
                arrayn = arrayn+a[i]
    print(arrayn)

def grandpa(a,p):
    father,grandpa='',''
    for key in a:
        if p in a[key]:
            father = key
    for key in a:
        if father in a[key]:
            grandpa = key
    print(grandpa)
