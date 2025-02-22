class LinkedList:
    def __init__(self, value):
        self.value = value
        self.next = None


# Add all nodes in LL1 to a set. Iterate in LL2 until find a matching point
def mergingLinkedListsBrute(linkedListOne, linkedListTwo):
    currentNode = linkedListOne
    listOneNodes = set()

    while currentNode is not None:
        listOneNodes.add(currentNode)
        currentNode = currentNode.next

    currentNode = linkedListTwo
    while currentNode is not None:
        if currentNode in listOneNodes:
            return currentNode
        currentNode = currentNode.next

    return None
    
# Cleverer solution. Knowing len of both list we can know the distance to merging point. If len2 < len 1
# len1 + len 2 = len2 + distance head1 to merge
def mergingLinkedListsClever(linkedListOne, linkedListTwo):
    # count len LL1
    currentNode = linkedListOne
    countOne = 0
    while currentNode is not None:
        countOne += 1
        currentNode = currentNode.next
    
    # count len LL2
    currentNode = linkedListTwo
    countTwo = 0
    while currentNode is not None:
        countTwo += 1
        currentNode = currentNode.next

    diff = abs (countTwo - countOne)

    # set bigger and smaller heads for later iteration
    biggerCurrentNode = linkedListOne if countOne > countTwo else linkedListTwo
    smallerCurrentNode = linkedListTwo if countOne > countTwo else linkedListOne

    # Move diff times the iterator in the longer linked list
    for i in range (diff):
        biggerCurrentNode = biggerCurrentNode.next

    # Now iterate at the same time until we found the not
    while biggerCurrentNode is not smallerCurrentNode:
        biggerCurrentNode = biggerCurrentNode.next
        smallerCurrentNode = smallerCurrentNode.next

    # Now return either of the values. they will both be the merging point or None
    return biggerCurrentNode













A = LinkedList(1)
B = LinkedList(2)
C = LinkedList(3)
D = LinkedList(4)
Z = LinkedList(1000)
E = LinkedList(11)
F = LinkedList(22)

A.next = B
B.next = C
C.next = D
D.next = Z
Z.next = None

E.next = F
F.next = C

# Common nodes are C,D, Z to both list. Merging point is C

sol = mergingLinkedListsBrute(A,E)
print(sol.value)


sol = mergingLinkedListsClever(A,E)
print(sol.value)