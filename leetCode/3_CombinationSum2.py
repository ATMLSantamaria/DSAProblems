## Now we need to find the possible permutations that add the target, and each number can be used just one

# Input: 
candidates = [10,1,2,7,6,1,5]
target = 8
#Output: 
r=[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]

from typing import List

def combinationSum2(candidates: List[int], target: int) -> List[List[int]]:
    res=[]
    candidates.sort() # Avoid duplicate combinations by skipping identical numbers during recursion.
    # print("candidates=",candidates)
    def backtrace(start,combination,total):

        # Base case
        if total == target:
            # Reason to use list(). En python lists se pasan por referencia. Combination se modifica constanemente, asi que nuestro res estaria afectadfo
            #  usando list() se crea una nueva instancia independiente.
            res.append(list(combination))
            return
        if total > target:
            return
        
        # combination.append(candidates[start])
        # recursive call
        for i in range(start,len(candidates)):
            # skip duplicates
            # since numbers are in order, we can skip duplicates the second time we see them because they have already been consider the first time
            if (i != start and candidates[i]==candidates[i-1]):
                continue

            combination.append(candidates[i])
            backtrace(i+1,combination,total+candidates[i]) # we can only use each number once
            combination.pop()
        # combination.pop()
    
    backtrace(0,[],0)
    return res

print(combinationSum2(candidates,target))