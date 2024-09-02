def MultiplicationTable(row, column):
    for i in range(int(row)):
        for j in range(int(column)):
            print(f"{((i + 1) * (j + 1)):3d}  ", end="")
        print("\n", end="")

row, column = input(">>").strip().split()

MultiplicationTable(row, column)