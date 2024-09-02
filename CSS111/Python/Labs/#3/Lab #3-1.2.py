special_characters = "!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~"

def checkPassword(password: str):
    haveLetters = False
    haveNumbers = False
    haveSpecials = False

    for s in password:
        if s.isalpha():
            haveLetters = True
        elif s.isdigit():
            haveNumbers = True
        elif s in special_characters:
            haveSpecials = True
    
    if (len(password) < 6):
        return "Weak"
    elif (len(password) >= 8 and haveLetters and haveNumbers and haveSpecials):
        return "Strong"
    elif (len(password) >= 6 and ((haveLetters and haveNumbers) or (haveLetters and haveSpecials))):
        return "Medium"
    else:
        return f"*Unexpected password case encountered. (L:{haveLetters}|N:{haveNumbers}|S:{haveSpecials})"
    
inputPasswords = {}
count = 0

while True:
    count += 1

    password = input(f"#{count}: Enter your password (Enter -1 to stop): ").strip()

    if (password == "-1"):
        break

    result = checkPassword(password)

    inputPasswords[password] = result

print("=================================")
print(f"Result: {"" if len(inputPasswords) > 0 else "*Empty password list detected*"}")

for password, result in inputPasswords.items():
    print(f"The password - '{password}' - is: {result}")

print("=================================")