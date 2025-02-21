res = [[-8,2,6],[-8,3,5],[-6,1,5]]

# Find all triplets in the array that sum up to the target sum
# Triplets has to be ordered in ascending orders

#  Brute Force approach
#  Usar 3 for loops, and simply  find all the possible triplets

#  Clever approach.
## First sort
## Despues usar dos indexes a elementos a izquierda y derecha

#  Time complexity is O(n2). We iterate once in the main array, plus the other iteration with L and R
#  Space complecity is O(N)
def threeNumberSum(array, targetSum):
  result = []
  array.sort()
  for i in range(len(array)-1):
    cN=array[i]
    # cS = cN + array[L] + array[R]
    L=i+1
    R=len(array)-1
    while L < R:
        cS = cN +array[L]+array[R]
        
        #cS < targetSum -> we need to do the cS bigger, so we increase L
        if cS < targetSum:
            L+=1
        #cS > targetSum -> we need to do the cS smaller, so we decrease R
        elif cS > targetSum:
            R-=1
        # we found a triplet, we add it to the res vector, and we continue. For that we need to decrease R and increase L at the same time
        else:
           result.append([cN,array[L],array[R]])
           R-=1
           L=+1
  return result
  

array = [12,3,1,2,-6,5,-8,6]
targetSum = 0

print(threeNumberSum(array,targetSum))
           





                