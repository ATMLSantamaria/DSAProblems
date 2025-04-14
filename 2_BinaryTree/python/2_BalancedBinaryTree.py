# This is an input class. Do not edit.
class BinaryTree:
    def __init__(self, value, left=None, right=None):
        self.value = value
        self.left = left
        self.right = right


def heightBalancedBinaryTree(tree):
    list = [True]
    calculate(tree,list)
    return list[0]
    

def calculate(tree,list):
    # Protection in case node is None
    # If the node is None its height is 0
    if tree is None:
        return 0
        
    # If this at some point become False, finish. no need to additional compute
    if list[0] == False:
        return 0
        
    # Recursive case toward both sides
    
    hLeft = calculate(tree.left,list)
    hRight = calculate(tree.right,list)

    # Compute condition
    diff = abs(hLeft - hRight)
    if diff >= 2:
        # In this case finish and return
        list[0] = False
        return 0 

    # Return the Max height
    return max(hLeft,hRight) + 1

    
    
