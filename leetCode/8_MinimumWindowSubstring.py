# This is a sliding window problem. In particualr one where we dinamically need to adjust the windows

# Given two strings s and t of lengths m and n respectively, 
# return the minimum window of s such that every character in t (including duplicates) is included in the window. 
# If there is no such substring, return the empty string 

# Input: s = "ADOBECODEBANC", t = "ABC"
# Output: "BANC"


# Analisis. Necesito 2 punteros. Primero debo encontrar una solucion valida y despues tratar de minimizarla. Guardar dicha solucion valida y avanzar hasta encontrar la proxima, tratar de minimizar y comparar con la anterior

# Necesito 2 diccionarios que contengan los char con sus frecuencias. Uno es el target, y el otro contendra los resultados en cada window, para comparar con el target


from collections import Counter

def minWindow(string, requiredChar):
    # El problema se estructura en 3 partes

    # First the needed variables

    leftPointer = 0
    rightPointer = 0

    # This will be the length of the final subarray. We need to initialise to a big number
    solutionMinLength = float("Inf")

    # Dictionary with the needed chars and frequencies
    targetDict = Counter(requiredChar)

    # Dictionary with the window chars and frequencies
    thisWindowDict = {}

    # This is the number of required unique characters
    requiredUniqueLen = len(targetDict)

    currentUniqueRequiredChars = 0


    # Now we start the main iteration. It will work until right reach the len of main string

    while rightPointer < len(string):

        # First. We extract character in the right. IMPORTANTE EN ESTE LOOP EXTRAEMOS DE LA DERECHA
        currentChar = string[rightPointer]

        # We add it to thisWindows count. There there will be record of all chars (if they dissapear when the window move their value will become 0)
        
        # We need the .get to get a 0 in return if the element is not yet in windows char
        thisWindowDict[currentChar] = thisWindowDict.get(currentChar,0) + 1

        # Now we check if the element is in the targetDict, and if is in the correct frequency. If yes, we can add 1 to currentUniqueChars
        if currentChar in targetDict and thisWindowDict[currentChar] == targetDict[currentChar]:
            currentUniqueRequiredChars += 1
        

        ################################3333
        # Here we will have the loop to first find a solution, and later optimise it. The loop is only triggered when we have all the necesary unique chars in our window
        while currentUniqueRequiredChars == requiredUniqueLen:
            # Save the current solution if it is better than the previous one.
            #  Len of a substring always right - left + 1 to include both ends
            currentLenSubstring = rightPointer - leftPointer + 1

            if currentLenSubstring < solutionMinLength:
                # If we are here it means that we have currently a solution, since we entered the while loop, and that we have a solution better than previous since we entered the if
                solutionLeftPointer = leftPointer
                solutionMinLength = currentLenSubstring
                
            # After the if we have stored the current best solution.

            # Now we try to optimise this solution shrinking the window. For that we: 1 remove from our window the character in the left, and then advance the pointer
            # We extract char from the left. IMPORTANTE EN ESTE LOOP EXTRAEMOS DE LA IZQUIERDA
            currentChar = string[leftPointer]
            

            # We decrease the frequency of this character in the dict
            thisWindowDict[currentChar] = thisWindowDict[currentChar] - 1

            # we check if the "removed" character was necessary for the solution, and it so we decrease currentUniqueRequireChars to show that we dont have solution. the second case is because maybe we have a lot of extra of those chars so loose one does not imapct the solution
            if currentChar in requiredChar and thisWindowDict[currentChar] < targetDict[currentChar]:
                currentUniqueRequiredChars -= 1

            # Now we move the pointer to the left
            leftPointer += 1
        
        ####################################


        rightPointer += 1

    solution = "" if solutionMinLength == float("Inf") else string[solutionLeftPointer:solutionLeftPointer+solutionMinLength]
    return solution






#Input: 
s = "ADOBECODEBANC"
required = "ABC"


print(minWindow(s,required))










  # Necesi