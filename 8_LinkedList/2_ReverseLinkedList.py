# This is an input class. Do not edit.
class LinkedList:
    def __init__(self, value):
        self.value = value
        self.next = None

# O(m)time and O(1) space
def reverseLinkedList(head):
    oldNode = None
    while head is not None:
        tmpNode = head.next
        head.next = oldNode
        oldNode = head
        head = tmpNode
    return oldNode
        



A = LinkedList(1)
B = LinkedList(2)
C = LinkedList(3)
D = LinkedList(4)
E = LinkedList(5)
F = LinkedList(6)

A.next = B
B.next = C
C.next = D
D.next = E
E.next = F
F.next = None

def printLL(head):
    while head is not None:
        print(head.value)
        head = head.next

printLL(A)


print("--")
printLL(reverseLinkedList(A))