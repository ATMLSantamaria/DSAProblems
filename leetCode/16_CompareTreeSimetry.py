# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isSymmetric(self, root: Optional[TreeNode]) -> bool:
        return DFCompare(root.left,root.right)

def DFCompare(node1,node2):
    if node1 is None and node2 is None:
        return True
    if node1 is not None and node2 is None or node1 is None and node2 is not None:
        return False
    
    compare = node1.val == node2.val
    
    return compare and DFCompare(node1.left,node2.right) and DFCompare(node1.right,node2.left)