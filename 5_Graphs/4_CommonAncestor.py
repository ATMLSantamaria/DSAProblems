from collections import deque
# This is an input class. Do not edit.
class AncestralTree:
    def __init__(self, name):
        self.name = name
        self.ancestor = None


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
        

      