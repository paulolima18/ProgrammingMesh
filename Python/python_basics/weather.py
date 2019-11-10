#Gives the max and the min weather in a file
def weather():
    file = open('weather.txt','r')
    t = file.read()
    file = open('weather.txt','r')
    l = []
    for i in range(t.count('\n')+1):
        line = file.readline()
        num = line.split()
        for j in range(len(num)):
            num[j] = eval(num[j])
        if len(num) != 0:
            print('max:',max(num),'min:',min(num))
        else:
            print()
    file.close()


if __name__ == '__main__':
    weather()
