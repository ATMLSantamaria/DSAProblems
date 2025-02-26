# This is an input class. Do not edit.
class BinaryTree:
    def __init__(self, value, left=None, right=None):
        self.value = value
        self.left = left
        self.right = right


def mergeBinaryTrees(tree1, tree2):
    # Create the root node of mergedTree
    merged = BinaryTree(0)
    # Invoke aux function to merge nodes in newly created tree
    mergeIntoThirdNode(tree1,tree2,merged)

    return merged


def mergeIntoThirdNode(n1,n2,n3):
    # Calculate Value for this node
    val1 = n1.value if n1 else 0 #if n1 None we dont have value to add
    val2 = n2.value if n2 else 0

    # set value to this n3
    n3.value = val1 + val2

    # Recursive part
    ## First take care of left side
    left1 = n1.left if n1 else None # Only value if n1 exist. If n1.left is None will be take care in next call
    left2 = n2.left if n2 else None

    # We do something if left1 or left2 exist, otherwise we set the n3.left to None and then that branch computation are finished
    if left1 or left2:
        # Create a new node for the next call
        n3.left = BinaryTree(0)
        mergeIntoThirdNode(left1,left2,n3.left)
    # Nothind to merge
    else:
        n3.left = None


    # Second take care of the right part
    right1 = n1.right if n1 else None
    right2 = n2.right if n2 else None

    if right1 or right2:
        n3.right = BinaryTree(0)
        mergeIntoThirdNode(right1,right2,n3.right)
    else:
        n3.right = None

    
