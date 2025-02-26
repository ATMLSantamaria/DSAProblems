# [1,2,3]
# []
# iteration1
# append([]+[1]) -> append([1])
# iteration2
# append([]+[2]) -> append([2])
# append([1]+2)  -> append([1,2])
# iteration3
# append([]+[3])   ->  [3]
# append([1]+[3])  ->  [1,3]
# append([2]+[3])  ->  [2,3]
# append([1,2]+[3]) -> [1,2,3]
def powerset(array):
    subsets=[[]]
    for element in array:
        for i in range(len(subsets)):
            currentSubSet = subsets[i]
            subsets.append(currentSubSet+[element])

    return subsets
    