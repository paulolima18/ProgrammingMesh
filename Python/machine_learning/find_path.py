import turtle
import random
import operator

#Setting up the map
turtle.setworldcoordinates(-200,-200,200,200)
begin=turtle.Turtle()
end=turtle.Turtle()
number=turtle.Turtle()
move=turtle.Turtle()
end.ht()
begin.ht()
begin.pu()
begin.goto(-100,0)
begin.pd()
begin.dot(25,'green')
end.pu()
end.goto(0,0)
end.pd()
end.dot(25,'red')

#Function that decides good or bad performance
def fitnessfunc(turtlepos):#turtle.pos()
    xDistance = (abs(0-int(turtlepos[0]))**2)
    yDistance = (abs(0-int(turtlepos[1])**2))
    distance = float((xDistance + yDistance )**(1/2))
    return float(distance)
'''0-Back
  1-Forward
  2-Right
  3-Left'''

def creatingindividual(moves):
    individual = []
    for i in range(moves):
        if int(random.random()*100) < 50:
            individual.append(str(int(2+random.random()*2)))#2 or 3
        else:
            individual.append(str(int(random.random()*2)))#0 or 1
    individual = ''.join(individual)
    return individual #return

def draw(individual):
    #move.hideturtle()
    move.pu()
    move.goto(-100,0)
    move.pd()
    move.speed(0)
    for i in range(len(individual)):
        if individual[i] == '0':
            move.bk(10)
        elif individual[i] == '1':
            move.fd(10)
        elif individual[i] == '2':
            move.right(90)
        elif individual[i] == '3':
            move.left(90)
    x = move.pos()
    return x

def creatingfirstgen(populationsize):
    population = {}
    numberindicator('1')
    for i in range(populationsize):
        individual = creatingindividual(moves)
        turtlepos = draw(individual)
        population[individual] = fitnessfunc(turtlepos)
    move.clear()
    return population

def setorder(population,n):
    populationsort = {}
    numberindicator(n)
    for individual in population:
        if int(n) == 1:
            turtlepos = move.pos()
            populationsort[individual] = fitnessfunc(turtlepos)
            if int(fitnessfunc(turtlepos)) == 0:
                print('Well Done')
                print(individual)
        else:
            turtlepos = draw(individual)
            turtlepos = move.pos()
            populationsort[individual] = fitnessfunc(turtlepos)
            if int(fitnessfunc(turtlepos)) == 0:
                print('Well Done')
                print(individual)

    number.clear() #Turtle number onScreen
    move.clear() #Turtle move set onScreen
    return(sorted(populationsort.items(),key = operator.itemgetter(1), reverse = False))

def genselect(population,n,m):
    newgen = []
    for i in range(n):
        newgen.append(population[i][0])
    for i in range(m):
        newgen.append(random.choice(population)[0])
    #random.shuffle(newgen)
    #print(newgen)
    return newgen

def creatingchild(individual1,individual2):
    child = ''
    for i in range(len(individual1)):
        if int(random.random()*100) < 50:
            child+= individual1[i]
        else:
            child+= individual2[i]
    return child

def creatingchildren(source):
    children = []
    for i in range(len(source)):
        children.append(creatingchild(source[i],source[len(source) -1 -i]))
    return children

def mutatingstr(st):
    index = (int(random.random()*len(st)))
    if (index==0):
        st = str(int(random.random()*4))+st[1:]
    else:
        st = st[:index]+str(int(random.random()*4))+st[index+1:]
    return st

def mutatingpopulation(population,probmutation):
    for i in range(len(population)):
        if int(random.random()*100)<probmutation:
            population[i] = mutatingstr(population[i])
    return population

def numberindicator(n):
    number.ht()
    number.pu()
    number.goto(-150,150)
    number.pd()
    fontsize=30
    FONT=('Arial',fontsize,'normal')
    number.write(n,font=FONT)

def program():
    i = 1
    while i < 2:
        mutated = mutatingpopulation(creatingchildren(genselect(setorder(creatingfirstgen(psize),str(i)),n,m)),mprob)
        i+= 1
    fmutated = mutated
    while int(i) < psize:
        order = setorder(fmutated,str(i))
        sle = genselect(order,n,m)
        children = creatingchildren(sle)
        fmutated = mutatingpopulation(children,mprob)
        i+= 1

if __name__ == '__main__':
    n = 10
    m = 5
    mprob = 40
    moves = 15
    psize = 50
    turtle.speed(0)
    program()
    turtle.exitonclick()

#creatingindividual(10)
#draw(creatingindividual(moves))
#setorder(creatingfirstgen(1),'1')
#genselect(setorder(creatingfirstgen(10),'1'),n,m)
#creatingchildren(genselect(setorder(creatingfirstgen(10),'1'),n,m))
