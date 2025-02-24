# This is an input class. Do not edit.
class Node:
    def __init__(self, value):
        self.value = value
        self.prev = None
        self.next = None


# Feel free to add new properties and methods to the class.
class DoublyLinkedList:
    def __init__(self):
        self.head = None
        self.tail = None

    def setHead(self, node):
        if self.head is None: # tenemos una empty list, si no habria algo
             self.head = node
             self.tail = node
             return
        self.insertBefore(self.head,node)

    def setTail(self, node):
        if self.tail is None: # trabajamos con empty list
            self.setHead(node)
            return
        self.insertAfter(self.tail,node)

    def insertBefore(self, node, nodeToInsert):
        if nodeToInsert == self.head and nodeToInsert == self.tail:
            return
        self.remove(nodeToInsert) #si insertamos un nodo de nuestra propia lista en otra posicion, hy que quitarlo de la posicion anterior
        
        nodeToInsert.prev = node.prev
        nodeToInsert.next = node

        # Tener cuidado del caso donde node es head
        if node.prev is None:
            self.head = nodeToInsert
        else:
            node.prev.next = nodeToInsert
        node.prev = nodeToInsert

    def insertAfter(self, node, nodeToInsert):
        if nodeToInsert == self.head and nodeToInsert == self.tail:
            return
        # First remove bindings in the old location in case we are inserteing a node already in the list
        self.remove(nodeToInsert)
        # Second update values in nodeToInsert
        nodeToInsert.prev = node
        nodeToInsert.next = node.next

        # Third. Update node and node.next taking into consideration the possibility that node could be the tail
        if node.next is None:
            self.tail = nodeToInsert
        else:
            node.next.prev = nodeToInsert
        
        node.next = nodeToInsert
        

    def insertAtPosition(self, position, nodeToInsert):

        if position == 1: # we are inserting at head
            self.setHead(nodeToInsert)
            return
        node = self.head
        currentPosition = 1
        while node is not None and currentPosition != position:
            node = node.next
            currentPosition += 1

        if node is not None:
            self.insertBefore(node, nodeToInsert)
            # return
        else:
            self.setTail(nodeToInsert)
            
        
        

    def removeNodesWithValue(self, value):
        node = self.head
        while node is not None:
            potentialNodeToRemove = node
            node = node.next
            if potentialNodeToRemove.value == value:
                self.remove(potentialNodeToRemove)
        
    def remove(self, node):
        # edge cases are head and tail. A node can be head and tail at the same time and in that case need to pass both head and tail
        if node == self.head:
            self.head  = self.head.next
        if node == self.tail:
            self.tail = self.tail.prev
        
        # General case. Update pointing in surrioubnding nodes
        self.removeNodeBindings(node)

    def containsNodeWithValue(self, value):
        node = self.head
        while node is not None and node.value != value:
            node = node.next
        return node is not None

    def removeNodeBindings(self, node):
        if node.prev is not None:
            node.prev.next = node.next # bipass this node from the point of view of the previopus
        if node.next is not None:
            node.next.prev = node.prev
        node.next = None # cut the connection of this node to the next
        node.prev = None # cut the conenction from this node to the prev
        
        
        
        
        