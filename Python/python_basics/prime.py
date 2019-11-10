import random
from math import *

def prime(n):
    for div in range(2,((n//2)+1)):
        if n%div == 0:
            return False
    return True

def prime_range(start = 1,end = 100):#all prime numbers in a certain interval
    for n in range(start,end+1):
        if prime(n):
            print(n)

def dice(n):#Chance of a specific result result (being even)
    even_count = 0
    for i in range(n+1):
        dice = random.randint(1,6)
        if dice%2 == 0:
            even_count+= 1
    print((even_count/n)*100,"%")

def fac(n):#recursive factorial in python
    if n > 0:
        return (n*fac(n-1))
    elif n == 0:
        return 1

if __name__ == "__main__":
    is_it_prime = prime(13)
    print(is_it_prime)
    prime_range()
    dice(10)
    fac(3)
