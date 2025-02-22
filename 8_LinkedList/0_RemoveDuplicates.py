# This is an input class. Do not edit.
class LinkedList:
    def __init__(self, value):
        self.value = value
        self.next = None


def removeDuplicatesFromLinkedList(linkedList):
    # Write your code here.
    currentNode = linkedList

    # Iterate across all the list
    while currentNode is not None:
        nextNode = currentNode.next
        while nextNode is not None and nextNode.value == currentNode.value:
                nextNode=nextNode.next
        
        currentNode.next=nextNode
        currentNode=nextNode
    return linkedList

a = LinkedList(1)
a.next = LinkedList(1)
a.next.next = LinkedList(1)
a.next.next.next = LinkedList(2)

removeDuplicatesFromLinkedList(a)
print(a.value,"->",a.next.value)