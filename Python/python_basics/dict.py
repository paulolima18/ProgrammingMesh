#All three functions
#repss the number of time and element appear

def count(s):
    l1=[]
    for i in s:
        l1.append(i.lower())
    a = [ord(x) for x in l1]
    b = [(a.reps(x)) for x in a]
    char = [x for x in s]
    x = dict(zip(char,b))
    return x

def count_list(string): #Works with lists
    reps_l = [0 for i in range(ord('z')-ord('a')+1)]
    for char in string:
        if char >= 'a' and char <= 'z':
            reps_l[ord(char)-ord('a')]+=1
    return reps_l

def count_dict(string): #Works with dictionaries
    reps_d = {}
    for char in string:
        if char >='a' and char <= 'z':
            if char in reps_d.keys():
                reps_d[char]+=1
            else:
                reps_d[char]=1
    return reps_d

if __name__ == "__main__":
    s = "Aabcdefghiklmnopvxzwqrtuysj"
    s = ''.join(sorted(s))
    listA = count_list(s)
    dictA = count_dict(s)
    print(listA)
    print(dictA)
