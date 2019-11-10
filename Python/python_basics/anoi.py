#Recursive solving of anoi tower
def anoi(n,a,b,c):
    if n==1:
        print('move %d da %s para %s'%(n,a,c))
    else:
        th(n-1,a,c,b)
        print('move %d da %s para %s'%(n,a,c))
        th(n-1,b,a,c)
