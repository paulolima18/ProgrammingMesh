import turtle,time
turtle.screensize(400,400)
def quad(l):
    for i in range(4):
        turtle.fd(l)
        turtle.right(90)
def circle(l=400,n=100,counter=0.01):
    for i in range(n*2):
        time.sleep(0.1)
        turtle.hideturtle()
        turtle.clear()
        turtle.dot(n*counter,'black')
        counter+=0.01
    turtle.begin_fill()
    turtle.colormode(255)
    turtle.pen(fillcolor=(254,165,0))    
    turtle.pu()
    turtle.goto(-400,800)
    quad(800)
    turtle.end_fill()
    turtle.goto(0,0)
    turtle.dot(n*counter+0.01,'yellow')    
    turtle.begin_fill()
    turtle.pen(fillcolor=(135,206,250))
    turtle.goto(-400,0)
    quad(800)
    turtle.end_fill()
circle()
turtle.exitonclick()