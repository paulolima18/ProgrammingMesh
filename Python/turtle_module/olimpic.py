import turtle
import math
def ball(pencil,color,radius):
    y = 0
    x = 0
    #des
    pencil.right(90)
    for i in range(5):
        pencil.pensize(5)
        if i%2==0:
            if i==0:
                color = "blue"
            elif i==2:
                color = "black"
            elif i==4:
                color = "red"
            ##y=y+radius*(5/3)
            y = 0
            x += radius
            turtle.colormode(255)
            pencil.pencolor(color)
            pencil.pu()
            pencil.goto(x,y)
            pencil.pd()
            pencil.circle(radius)
        else:
            if i==1:
                color="yellow"
            else:
                color="green"
            ##x=x+(radius*(4/3))
            x += radius
            y = -radius
            turtle.colormode(255)
            pencil.pencolor(color)
            pencil.pu()
            pencil.goto(x,y)
            pencil.pd()
            pencil.circle(radius)

if __name__=='__main__':
    radius = eval(input("Radius: "))
    turtle.title("Olimpic Symbol")
    pencil = turtle.Turtle()
    turtle.setworldcoordinates(-radius*7,-radius*7,radius*10,radius*10)
    turtle.hideturtle()
    ball(pencil,"blue",radius)
    turtle.exitonclick()
