import turtle
# f -> Forward
# r -> Right
# l -> Left
# b -> Back
def move(length,text):
    for i in range(length):
        y = text[i:i+1:]
        if ord(y) == ord("l"):
            turtle.left(90)
        elif ord(y) == ord("f"):
            turtle.fd(90)
        elif ord(y) == ord("b"):
            turtle.right(180)
            turtle.fd(100)
        elif ord(y) == ord("r"):
            turtle.right(90)
        else:
            print("Wrong letter")
    turtle.exitonclick()

if __name__=='__main__':
    print("Inputs:\nf -> Forward\nr -> Right\nl -> Left\nb -> Back")
    text=str(input("Sequence:", ))
    length = len(text)
    move(length,text)
