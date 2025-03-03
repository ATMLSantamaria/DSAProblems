# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def inorderTraversal(root):
    output = []
    DFSearch(root,output)
    return output


def DFSearch(node,output):
    if node is None:
        return
        
    if node.left is None and node.right is None:
        output.append(node.val)
        return

    if node.left is not None:
        DFSearch(node.left,output)

    output.append(node.val)

    if node.right is not None:
        DFSearch(node.right,output)

        
