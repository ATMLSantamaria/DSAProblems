import heapq

# Very IMPORTANT. 

# GREATERS is a MINHEAP -> EVERYTHING NORMAL, SIMPLY OPERATE WITH IT
# LOWERS is a MAXHEAP -> Does not exist in Python. We need to multiply by a negative number all operations related with LOWERS

class ContinuousMedianHandler:
    def __init__(self):
        # Write your code here.
        self.lowers = []
        self.greaters = []
        self.median = None

    def insert(self, number):
        # Case both arrays empty
        # Insert in the lowers values heap. Is a Max Heap
        if len(self.lowers) == 0:
            heapq.heappush(self.lowers,-1*number)
            self.median = number
            return
        
        # If number > peek value in lowers -> insert it into greater
        if number > -self.lowers[0]:
            heapq.heappush(self.greaters,number)
        else:
            heapq.heappush(self.lowers,-1*number)

        # Check if rebalance is needed
        diff = len(self.greaters) - len(self.lowers)

        # If greaters has 2 more units than lowers, pop in greaters, insert in lowers. Remebber greaters is a MinHeap and lowers is a MaxHeap
        if diff == 2:
            elementToMove = heapq.heappop(self.greaters)
            heapq.heappush(self.lowers,-1*elementToMove)
        # If lowers has 2 more unites greaters
        if diff == -2:
            elementToMove = - heapq.heappop(self.lowers)
            heapq.heappush(self.greaters,elementToMove)

        # Now the heap is rebalanced
        # Recalculate Median
        if len(self.lowers) == len(self.greaters):
            self.median =  (-self.lowers[0] + self.greaters[0])/2
        elif len(self.lowers) > len(self.greaters):
            self.median = -self.lowers[0]
        else:
            self.median = self.greaters[0]
            
        
        
    def getMedian(self):
        return self.median
    
    def getLowers(self):
        print(self.lowers)
    def getGreaters(self):
        print(self.greaters)
    



myMedianHandler = ContinuousMedianHandler()

myMedianHandler.insert(5)
print("should be 5, is: ",myMedianHandler.getMedian())


myMedianHandler.insert(10)

print("should be 7.5, is: ",myMedianHandler.getMedian())


myMedianHandler.insert(100)
print("should be 10, is: ",myMedianHandler.getMedian())

myMedianHandler.insert(200)
print("should be 55, is: ",myMedianHandler.getMedian())

myMedianHandler.insert(6)
print("should be 10, is: ",myMedianHandler.getMedian())

print(myMedianHandler.lowers)
print(myMedianHandler.greaters)


myMedianHandler.insert(13)
print("should be 11.5, is: ",myMedianHandler.getMedian())

