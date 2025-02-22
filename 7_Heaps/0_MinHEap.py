class MinHeap:
    def __init__(self, array):
        # self.heap is the underlying array in the heap
        self.heap = self.buildHeap(array)

    def buildHeap(self, array):
        # lwe start by the last parent, although we call it "first".
        # La razon del -2, es que el idx del ultimo padre, se calcula a partir del idx del ultimo hijo, es decir, len(array) - 1 es el idx del hijo.
        #  y el del padre es idxHijo - 1 // 2 -> en conuunto len(array) - 2 //2
        
        firstParentIdx = len(array) - 2 // 2
        for currentIdx in reversed(range(firstParentIdx + 1)):
            self.siftDown(currentIdx,len(array) - 1,array)
        return array
        



    def siftDown(self,currentIdx,endIdx,heap):
        childOneIdx = currentIdx * 2 + 1
        while childOneIdx <= endIdx:
            childTwoIdx = currentIdx * 2 + 2 if currentIdx * 2 + 2 <= endIdx else - 1

            if childTwoIdx != -1 and heap[childTwoIdx] < heap[childOneIdx]:
                idxToSwap = childTwoIdx
            else:
                idxToSwap = childOneIdx
            
            if heap[idxToSwap] < heap[currentIdx]:
                self.swap(idxToSwap,currentIdx,heap)
                currentIdx = idxToSwap
                childOneIdx = 2 * currentIdx + 1
            else:
                break


    def siftUp(self,currentIdx, heap):
        # Compute parent. j=2*i+1 -> i = (j-1) //2
        parentIdx = (currentIdx - 1) // 2
        while currentIdx > 0 and heap[currentIdx] < heap[parentIdx]:
            # intercambias
            self.swap(currentIdx,parentIdx,heap)
            # actualizas posicion
            currentIdx = parentIdx
            # calculas index del nuevo padre
            parentIdx = (currentIdx - 1) // 2
        

    def peek(self):
        return self.heap[0]

    # We can only remove the root of the heap
    # We swap with the last value, then remove it from the last position, then siftDown the new root to its final position
    def remove(self):
        self.swap(0,len(self.heap) - 1)
        valueToRemove = self.heap.pop()
        self.siftDown(0,len(self.heap) - 1,self.heap())
        return valueToRemove
    
    # Append to the last position in array and then siftUp to its correct position
    def insert(self, value):
        self.heap.append(value)
        self.siftUp(len(self.heap) - 1,self.heap)
    
    def swap(self,i,j,heap):
        heap[i],heap[j] = heap[j], heap[i]

test = [48, 12, 24, 7, 8, -5, 24, 391, 24, 56, 2, 6, 8, 41]

heap = MinHeap(test)