try:
    row, column = input(">> ").strip().split()

    for i in range(int(row)):
        for j in range(int(column)):
            print(f"{((i + 1) * (j + 1)):3d}  ", end="")
        print("\n", end="")
except:
    print("Something went wrong, please try again later...")