while True:
    try:
        inputNumber = int(input("Enter the number: "))

        if (inputNumber % 2 == 0):
            print(f"Number {inputNumber} is Even number.")
        else:
            print(f"Number {inputNumber} is Odd number.")

        break
    except:
        print("Invalid input, please try again...\n")