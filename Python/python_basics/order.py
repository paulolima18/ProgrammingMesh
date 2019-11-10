def order3(x,y,z): # order sequence of 3 numbers
    if x > y: #temp -> temporary number holder
        temp = x; x = y; y = temp
    if y > z:
        temp = y; y = z; z = temp
    if x > y:
        temp = x; x = y; y = temp
    print [x,y,z]
    return [x,y,z]

def order1(seq):
    temp_seq = seq #temp_seq -> temporary sequence
    val = 0
    for i in range(len(seq)):
        ordena = True
        for j in range(len(seq)-1):
            val+=1
            if temp_seq[j] > temp_seq[j+1]:
                temp_seq = temp_seq[:j] + [temp_seq[j+1],temp_seq[j]] + temp_seq[j+2:]
                ordena = False
        if ordena:
            return val
    return val

def order2(seq):
    temp_seq = seq #temp_seq -> temporary sequence
    val = 0
    for i in range(len(seq)):
        for j in range(len(seq)-1):
            val+=1
            if temp_seq[j] > temp_seq[j+1]:
                temp_seq = temp_seq[:j] + [temp_seq[j+1],temp_seq[j]] + temp_seq[j+2:]
    return val

def x(seq):
    print(sorted(seq))

if __name__=='__main__':
    array = [3,4,2,5,1]
    x = order1(array)
    print(array)
    print("Time order1 -> ",x,'\n')
    y = order2(array)
    print("Time order2 -> ",y,'\n')
