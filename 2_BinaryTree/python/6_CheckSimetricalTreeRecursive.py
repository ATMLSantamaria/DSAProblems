# This is an input class. Do not edit.
class BinaryTree:
    def __init__(self, value, left=None, right=None):
        self.value = value
        self.left = left
        self.right = right


def symmetricalTree(tree):
    # Write your code here.
    
    return check(tree.left,tree.right)

def check(left,right):
    
    if left is None and right is None:
        return True
    if left is None or right is None or left.value != right.value:
        return False

    check1 = check(left.right,right.left)
    check2 = check(left.left,right.right)

    return check1 and check2