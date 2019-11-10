def areaTriangle(base,height):
    area = (base*height/2)
    print(area)

if __name__=='__main__':
    base=eval(input("Place Base: "))
    height= eval(input("Place height: "))
    areaTriangle(base,height)
