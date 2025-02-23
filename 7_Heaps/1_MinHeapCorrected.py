# Do not edit the class below except for the buildHeap,
# siftDown, siftUp, peek, remove, and insert methods.
# Feel free to add new properties and methods to the class.
class MinHeap:
    def __init__(self, array):
        # Do not edit the line below.
        self.heap = self.buildHeap(array)

    def buildHeap(self, array):
        # Last parent of the tree ("first to analise"). Root parent is in index 0
        firstParentIdx = (len(array) - 2) // 2
        for currentIdx in reversed(range(firstParentIdx + 1)):
            self.siftDown(currentIdx,len(array) - 1,array)
        return array

    def siftDown(self,currentIdx,endIdx,heap):
        childOneIdx = currentIdx * 2 + 1
        while childOneIdx <= endIdx:
            childTwoIdx = currentIdx * 2 + 2 if currentIdx * 2 + 2 <= endIdx else -1

            if childTwoIdx != -1 and heap[childTwoIdx] < heap[childOneIdx]:
                idxToSwap = childTwoIdx
            else:
                idxToSwap = childOneIdx
            if heap[idxToSwap] < heap[currentIdx]:
                self.swap(idxToSwap,currentIdx,heap)
                currentIdx = idxToSwap
                childOneIdx = currentIdx * 2 + 1
            else:
                return
        

    def siftUp(self,currentIdx,heap):
        parentIdx = (currentIdx - 1) // 2
        while currentIdx > 0 and heap[currentIdx] < heap[parentIdx]:
            self.swap(currentIdx,parentIdx,heap)
            currentIdx = parentIdx
            parentIdx = (currentIdx - 1 ) // 2

    def peek(self):
        return self.heap[0]

    def remove(self):
        self.swap(0,len(self.heap) - 1,self.heap)
        valueToRemove = self.heap.pop()
        self.siftDown(0,len(self.heap) - 1,self.heap)
        return valueToRemove

    def insert(self, value):
        self.heap.append(value)
        self.siftUp(len(self.heap) - 1,self.heap)
        

    def swap(self,i,j,heap):
        heap[i],heap[j] = heap[j],heap[i]

    def printHeap(self):
        lo = self.heap
        print(lo)


array = [544, -578, 556, 713, -655, -359, -810, -731, 194, -531, -685, 689, -279, -738, 886, -54, -320, -500, 738, 445, -401, 993, -753, 329, -396, -924, -975, 376, 748, -356, 972, 459, 399, 669, -488, 568, -702, 551, 763, -90, -249, -45, 452, -917, 394, 195, -877, 153, 153, 788, 844, 867, 266, -739, 904, -154, -947, 464, 343, -312, 150, -656, 528, 61, 94, -581]
a = MinHeap(array)
a.printHeap()