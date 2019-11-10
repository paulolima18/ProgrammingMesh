import turtle
import random
dir(turtle)
def walk():
    turtle.colormode(255)
    for i in range(20):
        turtle.pencolor((random.randint(0,255),random.randint(0,255),random.randint(0,255)))
        turtle.forward(random.randint(1,100))
        turtle.right(random.randint(0,360))

    
    