def files(domain='dei.uc.pt'):
    file = open('domainNames.txt','r')
    x = file.readlines()
    x.sort()
    array = []
    for i in range(len(x)):
        x[i] = x[i].split()
        l.append(x[i][0][0]+x[i][1])
        email = open('email.txt','a')
        email.write(l[i]+'@'+domain+'\n')
    print(l)
    email.close()
    file.close()

if __name__ == '__main__':
    files()
