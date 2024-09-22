import math

## Constant Variables
START_NUMBER = 5
END_NUMBER = 9000

# Verify Constant
START_NUMBER = START_NUMBER if START_NUMBER >= 0 else 0
END_NUMBER = END_NUMBER if END_NUMBER > START_NUMBER else START_NUMBER + 1

# Variables
result = {}

# Operation
# Loop through every number provided
for i in range(START_NUMBER, END_NUMBER + 1):
    # Set the default input to 1 since 1 is the divisor of every number
    tmp_array = [1]
    sum = 1

    # Loop to find the divisor of i
    # Loop will stop at sqrt(i) + 1 since every divisors come in pairs

    # E.g.,
    # Divisors of 36 are [1, 2, 3, 4, 6, 9, 12, 18, 36]

    # Observe
    # 1 x 36 = 36
    # 2 x 18 = 36
    # 3 x 12 = 36
    # 4 x 9  = 36
    # 6 x 6  = 36 (we only count it once since it's a sqrt)

    for d in range(2, int(math.sqrt(i)) + 1):
        # Check if d is the divisor of i
        if i % d == 0:
            sum += d
            tmp_array.append(d)

            # Check if d is not a sqrt number (E.g., 6 x 6)
            if d != i // d:
                pair_divisor = i // d

                sum += pair_divisor
                tmp_array.append(pair_divisor)
    
    if sum == i:
        result[i] = tmp_array

# print(int(math.sqrt(6)) + 1)

for integer, divisors in result.items():
    divisors.sort()
    print(f"{integer} is a perfect number. Divisors: {divisors}")