sideList = list(map(int, input("Enter 3 sides of triangle: ").strip().split()))

sideList[:3]

if sideList[0] == sideList[1] == sideList[2]:
    print("Type of triangle is: Equilateral")
elif sideList[0] != sideList[1] != sideList[2]:
    print("Type of triangle is: Scalene")
else:
    print("Type of triangle is: Isosceles")