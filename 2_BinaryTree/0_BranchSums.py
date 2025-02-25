# This is the class of the input root. Do not edit it.
class BinaryTree:
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None


def branchSum(node):
    res = []
    initialSum = 0
    calculateBranchSumDFS(node,initialSum,res)
    return res


def calculateBranchSumDFS(node,runningSum,res):
    # if we have arrive to None return
    if node is None:
        return
    # Compute new running branch sum (temporal branch sum lets say)
    newRunningSum = runningSum + node.value
    # If we have arrive to a leaf node append the sum to the vector of results
    if node.left is None and node.right is None:
        res.append(newRunningSum)
    # Now recursive calls
    calculateBranchSumDFS(node.left,newRunningSum,res)
    calculateBranchSumDFS(node.right,newRunningSum,res)





def printNodeDSF(node):
    if node is None:
        return
    if node.left is None and node.right is None:
        print(node.value)
    printNodeDSF(node.left)
    printNodeDSF(node.right)

    # print(node.value)
    



























root = BinaryTree(1)
B = BinaryTree(2)
# C = BinaryTree(2)
D = BinaryTree(4)
E = BinaryTree(5)

F = BinaryTree(8)
G = BinaryTree(9)
H = BinaryTree(10)

I = BinaryTree(3)
J = BinaryTree(6)
K = BinaryTree(7)



root.left = B 
root.right = I

B.left = D
B.right = E

D.left = F
D.right = G

E.left = H

I.left = J
I.right = K

printNodeDSF(root)


print("----")
print(branchSum(root))