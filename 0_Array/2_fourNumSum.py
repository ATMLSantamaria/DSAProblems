array = [7,6,4,-1,1,2]
targetSum = 16


# Find all possible cuadruplet that sum targetSum

# For this we separate a cuadruplet in 2 pairs:

# [x,y,z,f] P=[x.y] Q=[z,f]

# we add P in hash table and check is Q+P is equal to targetSum
# The order is tricky, for each current number in the main iteration, we first compute and check Qs and only later add P

# Main loop
def fourNumSum(array,targetSum):
    solution=[]
    pairDictionary={}

    # we can start in 0 but it will not have a lot of sense, since in this very first iteration we will move O(n) in j without any effect since there
    # is nothin added in the dictionary
    # we also stop in the before last number, since we are looking for pairs, j will advance until that last number
    for i in range(1,len(array)-1):
        # Define current number in each iteration
        currentNum = array[i]

        # Check numbers after current number to find possible matches
        for j in range(i+1,len(array)):
            # Possible Qs
            Q = currentNum + array[j]
            possibleP = targetSum - Q
            if possibleP in pairDictionary:
                # We have aa least 1 matching P,Q but there could be several
                # In the dictionary there could be several pairs of numbers whose sum is P, and all of them has to form part of their cuadruplet
                for pairP in pairDictionary[possibleP]:
                    # We need to concatenate the pair and the [currentNum,array[j]] to form the cuadruplet
                    solution.append(pairP + [currentNum, array[j]])
        
        # This loop create P with pairs composed from the first number until the current nu,ber
        for k in range(i):
            #Ps
            P = array[k] + currentNum
            # If this P is not in the dictionary, we add P as a key with the summation elements as value
            if P not in pairDictionary:
                pairDictionary[P]=[[array[k],currentNum]]
            else:
                pairDictionary[P].append([array[k],currentNum])
    return solution


print(fourNumSum(array,targetSum))
                

