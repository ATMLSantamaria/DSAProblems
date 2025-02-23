## This is not a Optimal solution

# We are not using the advantage of the arrays being sorted, so this run in O(n+m)*log(n+m). This should run hjust in O(n+m). I think we need a binary search

from typing import List

import heapq

class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:

        currentMedian = 0
        
        # Max Heap
        lowerValues = []
        # Min Heap
        greaterValues =  []

        if nums1:
            heapq.heappush(lowerValues,-1 * nums1[0])
    


            for i in range(1,len(nums1)):
                
                # Introduce in the corresponding Heap
                if nums1[i] > -1 * lowerValues[0]:
                    heapq.heappush(greaterValues,nums1[i])
                else:
                    heapq.heappush(lowerValues,-1 * nums1[i])

                # Rebalance
                diff = len(lowerValues) - len(greaterValues)

                if diff == 2:
                    numberToMove = -1 * heapq.heappop(lowerValues)
                    heapq.heappush(greaterValues,numberToMove)
                
                if diff == -2:
                    numberToMove = heapq.heappop(greaterValues)
                    heapq.heappush(lowerValues, -1 * numberToMove)
                
                
            for i in range(len(nums2)):
                
                # Introduce in the corresponding Heap
                if nums2[i] > -1 * lowerValues[0]:
                    heapq.heappush(greaterValues,nums2[i])
                else:
                    heapq.heappush(lowerValues,-1 * nums2[i])

                # Rebalance
                diff = len(lowerValues) - len(greaterValues)

                if diff == 2:
                    numberToMove = -1 * heapq.heappop(lowerValues)
                    heapq.heappush(greaterValues,numberToMove)
                
                if diff == -2:
                    numberToMove = heapq.heappop(greaterValues)
                    heapq.heappush(lowerValues, -1 * numberToMove)
        else:
            heapq.heappush(lowerValues,-1 * nums2[0])
            for i in range(1,len(nums2)):
                
                # Introduce in the corresponding Heap
                if nums2[i] > -1 * lowerValues[0]:
                    heapq.heappush(greaterValues,nums2[i])
                else:
                    heapq.heappush(lowerValues,-1 * nums2[i])

                # Rebalance
                diff = len(lowerValues) - len(greaterValues)

                if diff == 2:
                    numberToMove = -1 * heapq.heappop(lowerValues)
                    heapq.heappush(greaterValues,numberToMove)
                
                if diff == -2:
                    numberToMove = heapq.heappop(greaterValues)
                    heapq.heappush(lowerValues, -1 * numberToMove)



        
        diff = len(lowerValues) - len(greaterValues)

        if diff == 0:
            currentMedian = (-1 * lowerValues[0] + greaterValues[0]) / 2
        elif diff == 1:
            currentMedian = -1 * lowerValues[0]
        else:
            currentMedian = greaterValues[0]

        return currentMedian
