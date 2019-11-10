import turtle
def naut():
    dim=200
    turtle.left(30)
    turtle.forward(100)
    turtle.right(90) 
    for i in range(20):
        for k in range(4):
            turtle.right(90)
            turtle.forward(dim)
        turtle.pu()
        dim=dim-10
        turtle.right(10)
        turtle.pd()