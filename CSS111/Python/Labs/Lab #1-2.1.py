try:
    factorialNumber = int(input("Enter factorial number: ").strip())

    sum = 1

    for i in range(1, factorialNumber + 1):
        sum *= i
    
    print(f"The result for {factorialNumber}! is: {sum}")
except:
    print("Something went wrong, please try again...")