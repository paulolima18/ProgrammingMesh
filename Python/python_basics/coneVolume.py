from piCalculator import pi

def x(radius,height):
    volume = (1/3)*pi*(radius**2)*height
    return volume

if __name__ == "__main__":
    pi = pi(2**20)
    radius = eval(input("Place radius(cm): "))
    height = eval(input("Place height(cm): "))
    volume = x(radius,height)
    print(volume)
