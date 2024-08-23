inputString = input("Enter the string >> ").strip()

reversedString = ""

# reversedString = inputString[::-1]

for s in range(len(inputString), 0, -1):
    reversedString += inputString[s-1]

print(reversedString)