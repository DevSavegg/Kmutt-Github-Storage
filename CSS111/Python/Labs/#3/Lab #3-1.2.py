special_characters = "\'!@#$%^&*()-+?_=,<>/\"`"

def PasswordCheck(password: str):
    if len(password) < 6:
        return "Weak"
    
    haveLetter = False
    haveNumber = False
    haveSpecial = False

    for s in password:
        if (s.isnumeric()):
            haveNumber = True
            continue
        elif (s in special_characters):
            haveSpecial = True
            continue
        elif(s.lower().isalpha()):
            haveLetter = True
            continue

    if ((len(password) >= 8) and (haveLetter and haveNumber and haveSpecial)):
        return "Strong"
    
    return "Medium"
        

inputPassword = input("Enter your password: ").strip()

result = PasswordCheck(inputPassword)

print(f"Your password - {inputPassword} - is {result}")