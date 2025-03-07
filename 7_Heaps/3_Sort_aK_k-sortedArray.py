import heapq

def sortKSortedArray(array, k):
    
    # k = 0
    if k == 0:
        return array



    # General case


    # Create the heap with the first k+1 elements
    # When using slicing it is not necessary to use list(). A new object is created
    heap = array[:k+1] #in python we dont need to care if k+1 is bigger than len(array). It will not create issues. In C++ we would need to take care if k+1 is bigger than the size of array
    heapq.heapify(heap)
    
    # Now iterate everytime extracting top element in the heap
    for i in range(len(array)):
        number =  heapq.heappop(heap)
        array[i] = number
        if i < len(array) - 1 - k:
            heapq.heappush(heap,array[i+k+1])
        
        

        




















test = [3,2,1,5,4,7,6,5]
test = [12,1]
k = 3

# In this case list is necessary to do a deep copy, creating a new instance of the object
sorted = list(test)
sorted.sort()
print(sorted)

print("compare above with below, below is the solution")
sortKSortedArray(test,k)
print(test)