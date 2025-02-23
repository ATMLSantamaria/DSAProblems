def laptopRentals(times):
    if len(times) == 0:
        return 0

    usedLaptops = 0
    
    # Create the sorted lists
    # The sorted() function returns a sorted list of the specified iterable object.
    start = sorted(interval[0] for interval in times)
    end = sorted(interval[1] for interval in times)

    startIterator = 0
    endIterator = 0

    while startIterator < len(times):

        if start [startIterator] < end[endIterator]:
            startIterator += 1
            usedLaptops += 1

        else: #start[startIterator] <= end[endIterator]
            startIterator += 1
            endIterator += 1
            
    return usedLaptops

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

print(laptopRentals(test))