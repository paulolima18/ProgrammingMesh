import turtle
import math
import random

def grafico(tartaruga,f,inicio,fim,n):
    #def
    x=inicio
    t_seg=(fim-inicio)/n
    #pos
    tartaruga.pu()
    tartaruga.goto(x,f(x))
    tartaruga.pd()
    #des
    for i in range(n):
        x = x+ t_seg
        turtle.colormode(255)
        tartaruga.pensize(3.5)
        tartaruga.pencolor(random.randint(10,254),random.randint(10,254),random.randint(10,254))        
        tartaruga.goto(x,f(x))

    
if __name__=='__main__':
    turtle.title('Janela')
    toto= turtle.Turtle()
    lol= turtle.Turtle()
    turtle.setworldcoordinates(-math.pi,-2,math.pi,2)
    turtle.hideturtle()
    turtle.speed(0)
    grafico(toto,math.sin,-math.pi,math.pi,50)
    grafico(lol,math.atan,-math.pi,math.pi,50)
    turtle.exitonclick()
    