import heapq

# You are given an array of integers stones where stones[i] is the weight of the ith stone.

# We are playing a game with the stones. On each turn, we choose the heaviest two stones and smash them together. Suppose the heaviest two stones have weights x and y with x <= y. The result of this smash is:

#     If x == y, both stones are destroyed, and
#     If x != y, the stone of weight x is destroyed, and the stone of weight y has new weight y - x.

# At the end of the game, there is at most one stone left.

# Return the weight of the last remaining stone. If there are no stones left, return 0



def lastStoneWeight(stones):
    
    maxHeap = []
    for i in stones:
        heapq.heappush(maxHeap, -1 * i)

    # Now I have my max heap

    while len(maxHeap) > 1:

        stoneY = -1 * heapq.heappop(maxHeap)
        stoneX = -1 * heapq.heappop(maxHeap)

        if stoneX == stoneY:
            continue
        else:
            stoneY = stoneY - stoneX
            heapq.heappush(maxHeap,-1 * stoneY)
    
    return 0 if len(maxHeap) == 0 else -1 *heapq.heappop(maxHeap)
            
            
    
stones = [2,7,4,1,8,1]

print(lastStoneWeight(stones))