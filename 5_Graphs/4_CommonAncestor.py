from collections import deque
# This is an input class. Do not edit.
class AncestralTree:
    def __init__(self, name):
        self.name = name
        self.ancestor = None

# Brute force
def getYoungestCommonAncestor(topAncestor, descendantOne, descendantTwo):
    # Write your code here.
    possibleAncestors = set()
    toVisitOne = deque()
    toVisitTwo = deque()
    

    toVisitOne.append(descendantOne)
    toVisitTwo.append(descendantTwo)
    

    while len(toVisitOne) > 0:
        # Work in One
        currentNode = toVisitOne.popleft() #we need queue behaviour
        if currentNode is None:
            break
        if currentNode.name in possibleAncestors:
            return currentNode
        
        possibleAncestors.add(currentNode.name)
        toVisitOne.append(currentNode.ancestor)


        
    while len(toVisitTwo) > 0:
        # Work in Two

        currentNode = toVisitTwo.popleft()
        if currentNode is None:
            break
        
        if currentNode.name in possibleAncestors:
            return currentNode

        possibleAncestors.add(currentNode.name)
        toVisitTwo.append(currentNode.ancestor)

    return currentNode
        

# Smart algorithm
# This is an input class. Do not edit.
class AncestralTree:
    def __init__(self, name):
        self.name = name
        self.ancestor = None


def getYoungestCommonAncestor(topAncestor, descendantOne, descendantTwo):
    # I need to get the depth of both descendant One and Two
    depthOne = getDepthIterative(descendantOne)
    depthTwo = getDepthIterative(descendantTwo)

    # First to put both nodes at the same level
    while depthOne > depthTwo:
        # When we place both at the same depth if one is the other that one is the common ancestor
        if descendantTwo == descendantOne:
            return descendantOne
        descendantOne = descendantOne.ancestor
        depthOne -= 1
    while depthTwo > depthOne:
        if descendantTwo == descendantOne:
            return descendantTwo
        descendantTwo = descendantTwo.ancestor
        depthTwo -= 1
    # Then iterate upward until find the commond ancestor

    while descendantOne != descendantTwo:
        descendantOne = descendantOne.ancestor
        descendantTwo = descendantTwo.ancestor
        # We found the common node
    return descendantOne #.ancestor if descendantOne.ancestor is not None else descendantOne


            
            
    



# Auxiliar function to get depth from root of the node
def getDepth(node):
    # root node has deep 0
    if node.ancestor is None:
        return 0
    return getDepth(node.ancestor) + 1

def getDepthIterative(node):
    depth = 0
    while node is not None:
        depth += 1
        node = node.ancestor
    return depth - 1