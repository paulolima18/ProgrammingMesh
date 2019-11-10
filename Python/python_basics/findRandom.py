import random

def findRandom():
    RandomNum = random.randint(0,55)

    for k in range(3):
        guess = eval(input("Number: "))
        if RandomNum == guess:
            print("Correct")
            return;
        elif randomNum > guess :
            print("Bigger")
        else:
            print("Smaller")
    print("You Lost, your number was: ",guess)
findRandom()
