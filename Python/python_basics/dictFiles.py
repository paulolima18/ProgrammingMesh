def dict_check(mydict={'Jack':('Jacob','Pendrive'),'Jacob':('Mary','Shoes'),'Mary':('Jack','Cards'),'Carl':('Peter','Book')}):
    x = 0
    u = [x[0] for x in mydict.values()]
    for key,value in mydict.items():
        if value[0] in mydict.keys():
            x+=1
        else:
            print(value[0],'does not give a gift')
            #indicates value which doesn't appear as a key
        if key not in u:
            print(key,'does not receive gift')
            #indicates key which doesn't appear as a value
    if x == len(mydict):
        print('Alright!')

def dict_save(mydict={'Peter':('Jacob','Pendrive'),'Jacob':('Mary','Shoes'),'Mary':('Carl','Cards'),'Carl':('Peter','Book')}):
    f = open('gifts.txt','w')
    for key,value in mydict.items():
        f.write('%s gives %s to %s\n'%(key,value[1],value[0]))
    f.close()

if __name__ == "__main__":
    dict_check()
    dict_save() #creates a txt file with dictionary connections
