
class LinkedList:
    def __init__(self, value):
        self.value = value
        self.next = None


def mergeLinkedLists(headOne, headTwo):


    if (headOne.value > headTwo.value):
        startNode = headTwo
        headTwo = headTwo.next
    else:
        startNode = headOne
        headOne = headOne.next
    
    iterator = startNode

    while headOne is not None and headTwo is not None:
        if (headOne.value > headTwo.value):
            iterator.next = headTwo
            iterator = iterator.next
            headTwo = headTwo.next
        else:
            iterator.next = headOne
            iterator = iterator.next
            headOne = headOne.next
    if headOne is not None:
        iterator.next = headOne
        # iterator = iterator.next
        # headOne = headOne.next      
    if headTwo is not None:
        iterator.next = headTwo
        # iterator = iterator.next
        # headTwo = headTwo.next

    return startNode   






A = LinkedList(2)
B = LinkedList(10)
C = LinkedList(340)
Z = LinkedList(1000)


D = LinkedList(0)
E = LinkedList(3)
F = LinkedList(4)

A.next = B
B.next = C
C.next = Z
Z.next = None

D.next = E
E.next = F
F.next = None

def printLL(head):
    while head is not None:
        print(head.value)
        head = head.next

printLL(A)
printLL(D)
print("----")

printLL(mergeLinkedLists(A,D))