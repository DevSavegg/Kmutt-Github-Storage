while True:
    try:
        name = input("What's your name: ")
        age = int(input("What's your age?: "))
        print(f'{name}, You will be 50 years old in the year {(50-age) + 2024}')
        break
    except:
        print("Something error. Please check your input and try again later...")