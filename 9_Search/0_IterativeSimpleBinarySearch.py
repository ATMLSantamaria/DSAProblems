def binarySearch(array, target):
    # Assure array is sorted
    array.sort()

    lowPointer = 0
    highPointer = len(array) - 1

    # [3,4,5,5,10]

    # Repeteat until both pointer cross
    while lowPointer <= highPointer:

        middlePointer = (highPointer + lowPointer) // 2 # we talk of indexes. always positive, so truncate towars -Inf works fine

        # if array[middlePointer] == target:
        #     return middlePointer

        if target > array[middlePointer]:
            # Target is in the right side -> update low to middle
            lowPointer = middlePointer + 1
        elif target < array[middlePointer]:
            # target is in the left side -> update high to middle
            highPointer = middlePointer - 1
        else:
            return middlePointer
        
    return -1
