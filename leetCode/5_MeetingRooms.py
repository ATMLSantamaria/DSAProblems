import heapq

# Problema de intervalos. [x,y] -> [start,end]

# This runs in O(nlogn) as expected. logn for the insertion in the heap. n because we need to do n insertions
class Solution:
    def minMeetingRooms(self, intervals: List[List[int]]) -> int:
        heap = []
        intervals.sort()
        
        # Metemos primer elemento al heap. El heap tiene que trabajar con y, es decir ending time. Osea el heap sera (y,[x,y])
        heapq.heappush(heap,(intervals[0][1],intervals[0]))
        
        for idx in range(1,len(intervals)):
            #Ahora. Si start > endMin -> x > yMin. We dont need extra laptop. Pop that old endMin and push new interval
            if intervals[idx][0] >= heap[0][0]:
                heapq.heappop(heap)
                heapq.heappush(heap,(intervals[idx][1],intervals[idx]))
            else:
                heapq.heappush(heap,(intervals[idx][1],intervals[idx]))
        # when we finish, the lenght of the heap is the maximum number of simultanously meeting rooms
        return len(heap)
         