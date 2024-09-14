def strlen(string: str):
    count = 0
    for _ in string:
        count += 1
    return count

def count_substrings_occurrences(main_string: str, sub_string: str):
    sub_string_len = strlen(sub_string)

    tmp_substring_count = 0
    occur_count = 0

    if sub_string_len != 0:
        for char in main_string:
            ## DEBUG
            print(char, tmp_substring_count, sub_string[tmp_substring_count], sub_string_len)
            
            if char == sub_string[tmp_substring_count]: # if char is starting to match the sub_string
                tmp_substring_count += 1
            else:
                tmp_substring_count = 0

                if char == sub_string[tmp_substring_count]: # start checking from substring[0] again
                    tmp_substring_count += 1

            if tmp_substring_count == sub_string_len: # if length of founding char is equal to length of sub_string
                occur_count += 1
                tmp_substring_count = 0
    
    return occur_count

main_string = input("Enter main string >> ")
sub_string = input("Enter sub string >> ")

result = count_substrings_occurrences(main_string, sub_string)

print("Total substring count:", result)
print("Expected:", main_string.count(sub_string))