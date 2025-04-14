import heapq
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def closestValue(self, root: Optional[TreeNode], target: float) -> int:
        # Store minimum value
        heap = []
        
        # traverseTree(root,target,heap)

        cleverTraverseTree(root,target,heap)

        return heapq.heappop(heap)[1]


# First approach. Simply to solve the problem checking all nodes if the tree
    
    # Create tuples of (diff,value) and put them in a min heap

    # Go across all the tree

    # when finished pop the minimum diff from the heap.
            # Check if there are more diff with same value

    # This approach is going to take O(n) since we will check all the nodes in the tree

def traverseTree(node,target,heap):
    # Base case
    if node is None:
        return

    # Recursive call adn logic
    dif = abs(target - node.val)
    heapq.heappush(heap,(dif,node.val))

    traverseTree(node.left,target,heap)
    traverseTree(node.right,target,heap)

# Second approach. Use the properties of the BST to reduce the size of the data to half in each iteration kwoing that each value in the right of a node is bigger than itself
# Each node in the left is smaller or equal
def cleverTraverseTree(node,target,heap):

    if node is None:
        return

    dif = abs(target - node.val)
    heapq.heappush(heap,(dif,node.val))

    if target <= node.val:
        traverseTree(node.left,target,heap)
    else:
        traverseTree(node.right,target,heap)




      