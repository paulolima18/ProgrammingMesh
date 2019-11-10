import turtle
import random
##l=lado;c=comprimento;a=angulo;k=largura;t=turn

turtle.setworldcoordinates(-500,-500,500,500)
corpo=turtle.Turtle()
corpo.pensize(3)
turtle.colormode(255)
corpo.color("brown")
def des(l,c,k,a,t):
    corpo.begin_fill()
    for i in range (l):
        turtle.colormode(255)
        corpo.pencolor(random.randint(10,254),random.randint(10,254),random.randint(10,254))  
        if i%2==0:
            corpo.fd(c)
            corpo.right(a)
        else:
            corpo.fd(k)
            corpo.right(a)
    corpo.end_fill()
    corpo.pu()
    corpo.right(t)
    corpo.pd()    

des(4,400,200,90,135)
des(4,150,150,90,90)
corpo.fd(150)
corpo.right(90)
des(3,150,150,120,90)
corpo.fd(430)
corpo.left(100)
corpo.fd(355)
corpo.right(145)
corpo.fd(350)
corpo.right(180)
des(3,100,100,120,0)

turtle.exitonclick()