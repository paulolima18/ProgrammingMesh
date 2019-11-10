import math

def pi(precision):
    pi = 0
    power = 0
    for i in range (1,precision,2):
        pi += (((-1)**power)/i)
        power+=1
    return (pi*4)

if __name__ == "__main__":
    print("Precision(n) [2^1...2^n]")
    n = eval(input("Precision:"))
    pi = pi(2**n)
    print(pi)

##Pi calculator
