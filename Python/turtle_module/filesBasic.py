def create_file(fich='first.txt'):
    f = open(fich,'w')
    f.write('Example of .txt file')
    f.close()

def mfirst(i,q,fich='first.txt'):
    f = open(fich,'r')
    f.seek(i)
    cont = f.read(q)
    f.close()
    return cont

def datah(fich='first.txt',date = '01/08/2018'):
    f = open(fich,'a')
    f.write('\n%s'%(date))
    f.close()

def fichn(fich='first.txt'):
    array,res=[],[]
    f = open(fich,'r')
    for i in f.read():
        array = array+[i]
    for i in array:
        if i.isdigit():
            res = res+[i]
    print(res)

def imitation(ori='first.txt',fake='wtv.txt'):
    f = open(ori,'r')
    f1 = open(fake,'w')
    f1.write('%s'%(f.read()))
    f.close()
    f1.close()

def fpoint(n):
    import turtle
    import random
    f = open('new.txt','w')
    array = []
    for i in range(n):
        array = array+[[10*random.randint(1,6),10*random.randint(1,6)]]
    print(array)
    for i in array:
        f.write('\n%d\n%d'%(i[0],i[1]))
    f.close()
    l = []
    f = open('new.txt','r')
    x = f.read().split()
    z = [(i,j) for i,j in zip(x[::2],x[1::2])]
    print(z)
    turtle.dot(10,'green')
    for i in z:
        turtle.pd()
        turtle.goto(int(i[0]),int(i[1]))
        turtle.pu()
    turtle.dot(10,'red')
    f.close()
    turtle.exitonclick()
