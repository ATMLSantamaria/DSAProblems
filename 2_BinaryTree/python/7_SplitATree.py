# This is an input class. Do not edit.
class BinaryTree:
    def __init__(self, value, left=None, right=None):
        self.value = value
        self.left = left
        self.right = right


def splitBinaryTree(tree):
    pass
    # Traverse the entire tree and find the sum

# In order traversal summing each branch
def sumBinaryTree(node):
    if node is None:
        return 0
    # First we go to the left
    sumLeft = sumBinaryTree(node.left)
 
    # Then to the right
    sumRight = sumBinaryTree(node.right)

    # Then add this node value
    thisNode = node.value

    return sumLeft + sumRight + thisNode
















# Constructing the tree
tree = BinaryTree(
    1,
    left=BinaryTree(
        3,
        left=BinaryTree(6, left=BinaryTree(2)),
        right=BinaryTree(-5)
    ),
    right=BinaryTree(
        -2,
        left=BinaryTree(5),
        right=BinaryTree(2)
    )
)

def postOrderTraversalPrint(node):
    if node is None:
        return 
    postOrderTraversalPrint(node.left)
    postOrderTraversalPrint(node.right)
    print(node.value,end=" ")

postOrderTraversalPrint(tree)
print(" ")

print(sumBinaryTree(tree))