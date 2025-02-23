import heapq

def laptopRentals(times):
    if len(times) == 0:
        return 0
        
    #  first i need to sort the input
    times.sort(key=lambda x: x[0])

    # Create a min heap. I need order according to the second elemet, therefore I will need an auxiliary tuple
    # heap = [times[0]]
    heap = []

    # Iterate comparing new starting time, with minimum of finishing times
    for interval in times:
        # si nuevo starting time es mayor que el menor de los finishing times. necesitamos 1 extra laptop
        # if old y <= new x -> remove old
        if heap and heap[0][0] <= interval[0]:
            heapq.heappop(heap)

        heapq.heappush(heap,(interval[1],interval)) #The tupla helps me to use this with heapq
    return len(heap)

test = [
  [0, 2],
  [1, 4],
  [4, 6],
  [0, 4],
  [7, 8],
  [9, 11],
  [3, 10]
]

solution_test = 3



print(test)
laptopRentals(test)
print(test)
print(laptopRentals(test))