def isPalindrome(string):
    nCharString = len(string)

    if nCharString == 1:
        return True

    for i in range(len(string) // 2):
        a = string[i] == string[nCharString-1-i]
        if a != True:
            return False
    return True


print(isPalindrome("anna"))
print(isPalindrome("tet"))
print(isPalindrome("Alejandro"))

