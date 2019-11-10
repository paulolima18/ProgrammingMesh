import turtle

def star(dim):
    rot = 144
    x = 0
    for i in range(15):
      turtle.forward(dim)
      turtle.right(144)
      dim+= 5
      
    turtle.exitonclick()

if __name__ == '__main__':
    star(100)
