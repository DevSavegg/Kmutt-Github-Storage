vowelsList = ["a", "e", "i", "o", "u"]

inputString = input("Enter the strings >> ").strip()

count = 0

for s in inputString:
    if s.lower() in vowelsList:
        count += 1

print(f"The total vowels in string '{inputString}' is: {count}")