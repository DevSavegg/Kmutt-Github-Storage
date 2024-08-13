import math

try:
    a = float(input("Enter first side: "))
    b = float(input("Enter second side: "))
    c = float(input("Enter third side: "))

    semiPerimeter = (a + b + c) / 2
    area = math.sqrt(semiPerimeter * (semiPerimeter - a) * (semiPerimeter - b) * (semiPerimeter - c))

    print('The area of triangle is {:.3f}'.format(area))
except:
    print("Something error, pleae try again...")