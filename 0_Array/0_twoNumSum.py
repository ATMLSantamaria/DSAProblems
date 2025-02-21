
# brute force approach
def twonumSum(array,targetSum):
    
    for i in range(len(array)-1):
        firstNum = array[i]
        for j in range(i+1,len(array)-1):
            secondNum = array[j]
            if firstNum+secondNum == targetSum:
                return [firstNum,secondNum]
    return []


# Clever algorithm 1. Using a hash table and x+y=target
# This run in O(n) but on the other hand it requires extra O(n) memory space
def twoNumSumClever1(array,targetSum):
    numsDict={}
    for nums in array:
        # y = targetNum - x
        y = targetSum - nums
        if y in numsDict:
            return [nums,y]
        else:
            numsDict[nums]=True #insert nums in the dictionary
    return []

#Clever algorithm 2. Sorting before. 
# Once sort you have 2 indexes pointing to the left and right end in the array. You compare the sum of them with the value
# If the sum is bigger than the value you need to decrease the right index to decrease your sum
# If the sum is smaller you need to increase your left pointer to make your sum bigger
# All in all this algorithm run in O(nlogn), the complexity of the sort. But it does not use extra space
def twoNumSumClever2(array,targetSum):
    array.sort() #sort uses a quick sort like merge or quicksort
    left = 0
    right = len(array)-1
    while left < right:
        if array[left]+array[right] < targetSum:
            left += 1
        elif array[left]+array[right] > targetSum:
            right -=1
        else:
            return[array[left],array[right]]
        
    return []
        
    




vector = [3,5,-4,8,11,1,-1,6]
targetSum = 10

print(twonumSum(vector,targetSum))
print(twoNumSumClever1(vector,targetSum))
print(twoNumSumClever2(vector,targetSum))
            

        

