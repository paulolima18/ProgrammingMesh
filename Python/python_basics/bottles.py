liters = eval(input("Number of Liters: "))

bottles5 = liters//5 ##number of 5L bottles
notUsed5 = liters%5 ##Liters left
bottles15 = notUsed5//1.5 ##number of 1.5L bottles
notUsed15 = notUsed5%1.5 ##Liters left
bottles05 = notUsed15//0.5 ##number of 0.5L bottles
notUsed05 = notUsed15%0.5 ##Liters left
bottles25 = notUsed05//0.25 ##number of 0.25L bottles
bottles25 = notUsed05%0.25 ##rest
k=(bottles25*100)+bottles25

if __name__ == "__main__":
    print(bottles5,"=5L,",bottles15,"=1.5L,",bottles05,"=0.5L,","%.2f"%k,"=0.25L")
