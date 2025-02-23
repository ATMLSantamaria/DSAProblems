import heapq

def mergeSortedArrays(arrays):

    # I need a heap where I will keep track of the minimum element out of the k first elements remaining in each array
    heapMinValues = []
    solution = []


    #  The heap will be an array of arrays [value, arraysKIndex, elementIdx]
    for kidx in range(len(arrays)):
        heapq.heappush(heapMinValues,[arrays[kidx][0],kidx,0])
    # Now we have a Min Heap in function of the first element of such array, that is the value. The other elements are necessary to keep track of where we are

    kTracking = len(arrays)
    while kTracking > 0:
        
        tmpItem = heapq.heappop(heapMinValues)
        tmpValue = tmpItem[0]
        tmpKidx = tmpItem[1]
        tmpElementIdx = tmpItem[2]
        
        solution.append(tmpValue)

        if tmpElementIdx == len(arrays[tmpKidx]) - 1:
            kTracking -= 1
            continue
            
        heapq.heappush(heapMinValues,[arrays[tmpKidx][tmpElementIdx+1],tmpKidx,tmpElementIdx+1])
    return solution




        


















test = [
  [1, 5, 9, 21],
  [-1, 0],
  [-124, 81, 121],
  [3, 6, 12, 20, 150]
]

test_solution = [-124, -1, 0, 1, 3, 5, 6, 9, 12, 20, 21, 81, 121, 150]

print(mergeSortedArrays(test))