import turtle
import math
def main(squares):
    length = 100
    for k in range(squares):
        for i in range(4):
            turtle.forward(length)
            turtle.right(90)
        turtle.pu()
        turtle.left(90)
        turtle.forward(length/10)
        turtle.right(90)
        turtle.back(length/10)
        turtle.pd()
        length = length + ((length/10) *2)
    input()
main(eval(input("Number of Squares: ")))
