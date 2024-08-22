from math import pi as PI
from sys import stderr as error

while True:
    try:
        radius = float(input("Enter your radius: "))
        
        result = PI * (radius ** 2)

        print(f'The area of circle where radius is equal to {radius} is: {result:.3f}')

        break
    except:
        error.write("Invalid input, please try again...\n")