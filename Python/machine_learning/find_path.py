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
#Setting up global vars
minimum=100.0 #minimum distance
best_individuals = 6 #number of good individuals
random_individuals = 14 #random individuals generated
mprob = 20 #probabily of mutation
moves = 15 #number of moves for each child
psize = 20 #population size
generations = 100 #number of generations

#Function that decides good or bad performance
def fitnessfunc(turtlepos):#turtle.pos()
    global minimum
    xDistance = (abs(0-int(turtlepos[0]))**2)
    yDistance = (abs(0-int(turtlepos[1])**2))
    distance = float((xDistance + yDistance )**(1/2))
    if(minimum > distance):
        minimum = distance
        print(distance)
    return distance
'''0-Back
  1-Forward
  2-Right
  3-Left'''

def creating_individual(moves):
    individual = []
    for i in range(moves):
        if int(random.random()*100) < 50:
            individual.append(str(int(2+random.random()*2)))#2 or 3
        else:
            individual.append(str(int(random.random()*2)))#0 or 1
    individual = ''.join(individual)
    return individual #return

def draw(individual):
    global move
    #move.hideturtle()
    move.clear()
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
    return move.pos()

def creatingfirstgen(populationsize):
    global move

    population = {}
    number_indicator('1')
    for i in range(populationsize):
        individual = creating_individual(moves)
        turtlepos = draw(individual)
        #print(individual)
        population[individual] = fitnessfunc(turtlepos)
    move.clear()
    #print(population)
    return population

def setorder_next(population, n):
    global move

    populationsort = {}
    number_indicator(str(n))
    print("SETORDER")
    print(population)
    for i in range(len(population)):
        print("OKKKKKKK")
        print(population[i])
        turtlepos = draw(population[i])
        fitness_value = fitnessfunc(turtlepos)
        populationsort[population[i]] = fitness_value
        print("BYEEEEEE")
        print(populationsort[population[i]])
        if int(fitness_value) == 0:
            print('Well Done')
            print(population[i])

    number.clear() #Turtle number onScreen
    move.clear() #Turtle move set onScreen
    print("SETORDER_AFTER")
    print(populationsort)
    return(sorted(populationsort.items(),key = operator.itemgetter(1), reverse = False))

def setorder(population, n):
    populationsort = {}
    number_indicator(str(n))
    move.clear()
    print("SETORDER")
    print(population)
    for individual in population:
        print("HIIIII")
        print(individual)
        fitness_value = population[individual]
        populationsort[individual] = fitness_value
        if int(fitness_value) == 0:
            print('Well Done')
            print(individual)

    number.clear() #Turtle number onScreen
    move.clear() #Turtle move set onScreen
    print("SETORDER_AFTER")
    print(populationsort)
    return(sorted(populationsort.items(),key = operator.itemgetter(1), reverse = False))

def genselect(population, best_individuals, random_individuals):
    newgen = []
    print("ALL")
    print(population)
    for i in range(best_individuals):
        newgen.append(population[i][0])
    for i in range(random_individuals):
        newgen.append(random.choice(population)[0])
    # random.shuffle(newgen)
    print("Newgen")
    print(newgen)
    return newgen

def creatingchild(individual1, individual2):
    child = ''
    for i in range(len(individual1)):
        if int(random.random()*100) < 50:
            child+= individual1[i]
        else:
            child+= individual2[i]
    return child

def creating_children(source):
    children = []
    for i in range(len(source)):
        if(i < best_individuals):
            children.append(source[i])
        else:
            children.append(creatingchild(source[i],source[len(source) -1 -i]))
    print("Children")
    print(children)
    return children

def mutatingstr(st):
    index = (int(random.random()*len(st)))
    if (index==0):
        st = str(int(random.random()*4))+st[1:]
    else:
        st = st[:index]+str(int(random.random()*4))+st[index+1:]
    return st

def mutating_population(population, probmutation):
    for i in range(len(population)-random_individuals,len(population)):
        if int(random.random()*100) < probmutation:
            population[i] = mutatingstr(population[i])
    print("mutation")
    print(population)
    return population

def number_indicator(n):
    number.ht()
    number.pu()
    number.goto(-150,150)
    number.pd()
    fontsize=30
    FONT=('Arial',fontsize,'normal')
    number.write(n,font=FONT)

def program():
    global best_individuals
    global random_individuals
    global generations
    i = 0
    while i < 1:
        mutated = mutating_population(
                    creating_children(
                        genselect(
                            setorder(creatingfirstgen(psize),i+1)
                        , best_individuals, random_individuals)
                    )
                ,mprob)
        i+= 1
    fmutated = mutated
    while i < generations:
        order = setorder_next(fmutated,i+1)
        sle = genselect(order, best_individuals, random_individuals)
        children = creating_children(sle)
        fmutated = mutating_population(children, mprob)
        i+= 1

if __name__ == '__main__':
    # turtle.speed(1)
    program()
    #position = draw('111013300300121')
    #print(fitnessfunc(position))
    turtle.exitonclick()

#creating_individual(10)
#draw(creating_individual(moves))
#setorder(creatingfirstgen(1),'1')
#genselect(setorder(creatingfirstgen(10),'1'),n,m)
#creating_children(genselect(setorder(creatingfirstgen(10),'1'),n,m))
