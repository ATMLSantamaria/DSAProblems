def minSubArrayLen(target, nums):

    # I like more this names
    targetSum = target
    array = nums
    # solutions
    solutionLen = float("Inf")
    solutionL = 0
    
    currentWindowSum = 0
    # pointers
    L = 0
    R = 0

    # Grow window in the right
    while R < len(array):
        currentNumber = array[R]
        currentWindowSum += currentNumber

        # If currentWindowSum > targetSum we have a solution. We try to optimise
        while currentWindowSum >= targetSum:
            currentLen = R - L + 1
            # If this solution is better than previous save it
            if currentLen < solutionLen:
                solutionL = L
                solutionLen = currentLen
            # We have save the current best solution, try to optimise it making smaller the window in the left
            currentNumber = array[L]
            currentWindowSum -= currentNumber
            L += 1

            # We have make the solution decrease by the left, also moved the pointer. If it is a solution will be checked by the shile currentWindowSum > targetSum
        
        # If the other loop has finished it mean that the solution can not be more optimised by the left. We move in the right
        R += 1

    # Important to remember to return 0 if we did not find a solution
    return 0 if solutionLen==float("Inf") else solutionLen


test = [2,3,1,2,4,3]
target = 7

print(minSubArrayLen(7,test))