numList = list(map(int, input("Enter the number >> ").strip().split()))

minNum, maxNum = 0, 0 

for i in range(0, len(numList)):
    if (i == 0):
        minNum = numList[0]
        maxNum = numList[-1]

    if (numList[i] < minNum):
        minNum = numList[i]

    if (numList[i] > maxNum):
        maxNum = numList[i]

print("******************************")
print("The minimum number is:", minNum)
print("The maximum number is:", maxNum)
print("******************************")