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
        return f"*Unexpected password case encountered. ({haveLetters}|{haveNumbers}|{haveSpecials})"
    
inputPassword = input("Enter your password: ").strip()

result = checkPassword(inputPassword)

print(f"The strength for the password - '{inputPassword}' - is: {result}")