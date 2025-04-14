# O(n) time O(h space) with hs being height
def nodeDepths(root,depth = 0):
    # BASE CASE
    if root is None:
        return 0
    # GENERAL
    return depth + nodeDepths(root.left,depth + 1) + nodeDepths(root.right,depth + 1)


# Above there is the really clean algorithm 


def nodeDepthsDirty(root):
    list = [0,1,2,3]
    rootDepth = 0
    list[0] += rootDepth
    childDepth = 1
    nodeDepthsSum(root.left,childDepth,list)
    nodeDepthsSum(root.right,childDepth,list)
    return list[0]
    

def nodeDepthsSum(node,childDepth,list):
    if node is None:
        return 0
    num = list [0]
    num = num + childDepth
    list[0] = num
    if node.left is None and node.right is None:
        return 0
    nodeDepthsSum(node.left,childDepth+1,list)
    nodeDepthsSum(node.right,childDepth+1,list)
    

# This is the class of the input binary tree.
class BinaryTree:
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None
