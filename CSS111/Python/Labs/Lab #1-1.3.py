
try:
    #num1, num2, num3 = int(input("Plesae enter 3 numbers: ").strip().split())
    numList = list(map(int, input("Enter 3 numbers: ").strip().split()))

    numList = numList[:3]
    numList.sort()

    print(f"The largest number from input is: {numList[-1]}")
except:
    raise Exception("Something went wrong, please try again...")