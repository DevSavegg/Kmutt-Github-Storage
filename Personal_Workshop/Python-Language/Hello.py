special_characters = "!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~"

def checkPassword(password):

    haveLetter = False
    haveNumber = False
    haveSpecial = False

    for s in password:
        if s.isalpha():
            haveLetter = True
        elif s.isdigit():
            haveNumber = True
        elif s in special_characters:
            haveSpecial = True
    
    if len(password) < 6:
        return "Weak"
    elif len(password) >= 8 and haveLetter and haveSpecial and haveLetter:
        return "Strong"
    elif len(password) >= 6 and ((haveLetter and haveNumber) or (haveLetter and haveSpecial)):
        return "Medium"
    else:
        return "Fuck you"
    
passwords = input("Enter your password: ").strip().split()

for pwd in passwords:
    result = checkPassword(pwd)
    print(f"The password - {pwd} - is: {result}")