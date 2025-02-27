def stairCaseTraversal(height,maxNumSteps):
    #  Base case
    waysOfTraversal=[1]
    currentNumberOfWays = 0

    # Height+1 because you need to arrive to the end of the aray
    for currentHeight in range(1,height+1):
        # Update the start and end in the window
        startPrev = currentHeight - maxNumSteps - 1

        endCurrent = currentHeight - 1

        # Add new value and subtrack previous value
        if startPrev >= 0:
            currentNumberOfWays -= waysOfTraversal[startPrev]
          
        currentNumberOfWays += waysOfTraversal[endCurrent]

        waysOfTraversal.append(currentNumberOfWays)
    
    print(waysOfTraversal)
    return currentNumberOfWays
    


print(stairCaseTraversal(5,2))
