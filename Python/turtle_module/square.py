import turtle

def draw(point,size,sides,rot):
    for i in range(sides):
        point.fd(size)
        point.right(rot)
    turtle.exitonclick()

if __name__ == "__main__":
    square = turtle.Turtle()
    turtle.goto(0,0)
    draw(square,100,4,90)
