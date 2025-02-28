def binarySearch(array, target):
    # Write your code here.
    return helper(array,target,0,len(array) - 1)
    
def helper(array,target,low,high):
    middle = (low+high) // 2
    
    # Base class
    if low > high:
        return -1
    
    if array[middle] == target:
        return middle

    # Recursive call
    if target < array[middle]:
        return helper(array,target,low,middle - 1)
    if target > array[middle]:
        return helper(array,target,middle + 1,high)
    
