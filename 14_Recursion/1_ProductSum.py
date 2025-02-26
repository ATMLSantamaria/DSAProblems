# Tip: You can use the type(element) function to check whether an item
# is a list or an integer.

# Product Sum.[x,y] = x + y pero [x,[y,z]] -> x + 2 * (y + z)

def productSum(array):
    # Write your code here.
    return auxProduct(array)

def auxProduct(array,depth = 1):
    sum = 0
    depth = depth + 1
    prod = 1
    for i in array:
        if type(i) is int:
            sum += i

        elif type(i) is list:
            sum += depth * auxProduct(i,depth)
    return sum
        