# There are multiple options, we can use a heap but the Time complexicy it would be O(nlog(n)). Also we could use a Stack.

# Best solution is to modify the numbers in place in the array in O(n)

# maxHeap solution

import heapq

# This solution is O(nlog(n)) in time and O(n) in space. 
def findThreeLargestNumbers(array):
    # Without Sorting
    # Create the  max heap
    maxHeap = []
    for i in array:
        heapq.heappush(maxHeap,-1*i)

    sol = [0,0,0]

    sol[2] = -1 * heapq.heappop(maxHeap)
    sol[1] = -1 * heapq.heappop(maxHeap)
    sol[0] = -1 * heapq.heappop(maxHeap)

    return sol


