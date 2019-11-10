'''fitnes function
    creating individual
    creating gen
    selection from population
    new gens(N-Best/M-random)
    creating child
    creating children
    mutating word
    mutating population
    '''
#password==password que tentamos saber
#individual== a palavra escolhida
import random
import operator

def fitnessfunc(password,individual):
    fitness=0.0
    if len(password)!=len(individual):
        fitness=0.0
        return fitness
    else:
        for i in range(len(password)+1):
            if i<len(password):
                if individual[i]==password[i]:
                    fitness+=1
    return (fitness/len(password)*100)#return

def creatingindividual(password):
    individual=''
    for i in range(len(password)):
        individual=individual+(vlist[int(random.random()*36)])
    return individual #return

def creatingfirstgen(populationsize,password):
    population={}
    for i in range(populationsize):
        individual=creatingindividual(password)
        population[individual]=fitnessfunc(password,individual)
    return population  #return

def gensort(population,password):
    populationsort={}
    for individual in population:
         populationsort[individual]=fitnessfunc(password,individual)
    return (sorted(populationsort.items(), key = operator.itemgetter(1), reverse=True))

def genselect(gensorted,n,m):
    newgen=[]
    for i in range(n):
        newgen.append(gensorted[i][0])
    for i in range(m):
        newgen.append(random.choice(gensorted)[0])
    random.shuffle(newgen)
    return newgen #return

def creatingchild(individual1,individual2):
    child=''
    for i in range(len(individual1)):
        if int(random.random()*100)<50:
            child+=individual1[i]
        else:
            child+=individual2[i]
    return child

def creatingchildren(sourcepopulation):
    children=[]
    for i in range(int(len(sourcepopulation)/2)):
        children.append(creatingchild(sourcepopulation[i],sourcepopulation[len(sourcepopulation) -1 -i]))
    return children

def mutatingword(word):
    index=int(random.random()*len(word))
    if (index==0):
        word=chr(97+int(random.random()*26))+word[1:]
    else:
        word=word[:index]+vlist[int(random.random()*36)]+word[index+1:]
    return word
def mutatingpopulation(population,probmutation):
    for i in range(len(population)):
        if int(random.random()*100)<probmutation:
            population[i]=mutatingword(population[i])
    return population

secret=input('Your password: ')
"secret='pa9823ss'"
n=20
m=80
prob=40
gera=[]
vlist=['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9']
def program():
    i=0
    while i<1:
        firstgen=creatingfirstgen(100,secret)
        firstgensorted=gensort(firstgen,secret)
        genlist1=genselect(firstgensorted,n,m)
        childs=creatingchildren(genlist1)
        mutated=mutatingpopulation(childs,prob)
        x=[x for x in mutated if x==secret]
        i+=1
        try:
            if x[0]==secret:
                print('Your password is, "%s"'%(x[0]))
                break
        except IndexError:
            print('Fail first')
    fmutated=mutated
    while True:
        gensorti=gensort(fmutated,secret)
        genselecti=genselect(gensorti,n,m)
        createchildreni=creatingchildren(genselecti)
        fmutated=mutatingpopulation(createchildreni,prob)
        x=[x for x in fmutated if x==secret]
        i+=1
        try:
            if x[0]==secret:
                print('Your password is, "%s",in Generation %d'%(x[0],i))
                print(fmutated)
                break
        except IndexError:
            pass
program()



#x=['pljsk', 'rhweu', 'bkwnm', 'qqxij', 'fmful', 'nlnpv', 'gnrdd', 'ewrek', 'fmful', 'nlnpv', 'nmjrx', 'gixdy', 'tovdu', 'tplic', 'dnlah', 'kksoo', 'todgj', 'jbyhl', 'twvhu', 'xtsar', 'hqxrp', 'lqpec', 'ettke', 'ewrek', 'mogku', 'sofum', 'jbyhl', 'fmful', 'dipha', 'vxcpt', 'qoksm', 'jbyhl', 'gixdy', 'idooc', 'iigdr', 'gixdy', 'iigdr', 'mkeia', 'bkwnm', 'ngrab', 'mlpkb', 'aoluk', 'ihkbv', 'mgesu', 'sxdyw', 'csqcf', 'xilah', 'qqbxl', 'tpddi', 'bkxsk', 'fflnd', 'xbith', 'muaes', 'ngrab', 'nrqyy', 'ghwed', 'erdgl', 'gnrdd', 'iigdr', 'bhbap', 'sxdyw', 'ebiwo', 'wmwkv', 'ettke', 'vxrst', 'obxbw', 'qqbxl', 'xbith', 'ebiwo', 'tovdu', 'qqxij', 'aeven', 'tlwel', 'pljsk', 'qaqab', 'twvhu', 'tpari', 'feptd', 'kuhud', 'bhbap', 'kksoo', 'qoksm', 'xbith', 'xjicv', 'ghwed', 'mkeia', 'cdkro', 'xtsar', 'mogku', 'gnrdd', 'nlnpv', 'gixdy', 'rtmmi', 'hyxuq', 'bkwnm', 'xmtbi', 'fencl', 'xjicv', 'aeven', 'qqxij']
#fitnessfunc('trial','tria')
#creatingindividual('trial')
#creatingfirstgen(100,'sara')
#gensort(creatingfirstgen(1000,'trial'),'trial')
#genselect(gensort(creatingfirstgen(100,'trial'),'trial'),20,80)
#creatingchildren(x)
#mutatingpopulation(creatingchildren(x),40)
