import turtle
print("Numbers bigger than 50")
def star(length):
    rotation = 144
    for i in range (5):
        turtle.forward(length)
        turtle.right(rotation)
    turtle.exitonclick()

if __name__ == '__main__':
    star(eval(input("Star Size: ")))
