candidates = [2,3,6,7]
target = 7

# This is simply a Type annotation module. List is simply a type indication, list is the actual data structure
from typing import List


def combinationSum(candidates: List[int], target: int) -> List[List[int]]:
    result = []
  

    def backtrack(start,combination,total):
        #Base case
        if (total == target):
            result.append(list(combination))
            return
        # If total > target -> stop exploring
        if (total > target):
            return
        
        # general case
        ### check all possibilities
        for i in range(start,len(candidates)):

            # Add current candidate to the combination
            combination.append(candidates[i])
            # recursive call with updated totals
            backtrack(i,combination,total+candidates[i])
            # pop candidates to assure clean state in the next iteration
            combination.pop()
    
    # backtrack(i=0,combination=[],total=0)
    backtrack(0,[],0)
    return result


print(combinationSum(candidates,target))



