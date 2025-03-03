# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isSameTree(self, p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:
        return inOrderTraversal(p,q)

def inOrderTraversal(node1,node2):
    if node1 is None and node2 is None:
        return True
    if node1 is None and node2:
        return False
    if node2 is None and node1:
        return False
    
    # left =  inOrderTraversal(node1.left,node2.left)

    compare = node1.val == node2.val


    return compare and inOrderTraversal(node1.left,node2.left) and inOrderTraversal(node1.right,node2.right)
    

        
        