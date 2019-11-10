import random
import turtle

def writeToFile():
    c=open('first.txt','w')
    c.write('My first python file.')
    c.close()

def readFromTo(k,n=0):
    c=open('first.txt','r')
    c.seek(n)
    print(c.read(k))
    c.close()

def appendToFile():
    c=open('first.txt','a')
    c.write('\n12/04/2017')
    c.close()

def readNumbers():
    s='0123456789'
    c=open('first.txt','r')
    s_new=[i for i in c.read() if i in s]
    print(s_new)

def copyFile(name,copy='copy'):
    t = open(name,'r') ##Name need to be inputed with ''
    x = open(copy,'w')
    x.write(t.read())
    t.close()
    x.close()

def filesToTurle(n):
    file = open('coordinates.txt','w')
    for i in range(n*2):
        file.write(('%d\n%d\n'%(random.randint(1,6),random.randint(1,6))))
    file.close()
    file = open('coordinates.txt','r')
    turtle.pd()
    for j in range(n):
        turtle.goto(eval(file.readline())*10,eval(file.readline())*10)
    turtle.pu()
    turtle.exitonclick()
    file.close()

if __name__=='__main__':
    writeToFile()
    appendToFile()
    readFromTo(10,0)
    readNumbers()
    #etc
