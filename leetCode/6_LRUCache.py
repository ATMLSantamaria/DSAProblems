class LRUCache:

    def __init__(self, capacity: int):
        self.maxCapacity = capacity
        self.currentSize = 0
        self.cache = {} # {key : DLinkedListNode}
        self.listMostRecentlyUsed = DLinkedList()
        

    def get(self, key: int) -> int:
        # First is the case where the key is not in the dict
        if key not in self.cache:
            return -1
        
        # Caso general. If it is in the cache, we retrieve the data and set this element to the most recently used
        self.listMostRecentlyUsed.setHeadToNode(self.cache[key])
        return self.cache[key].value

    def put(self, key: int, value: int) -> None:
        # Key already there, we simply replace value and update to Most recently used
        if key in self.cache:
            self.cache[key].value = value
            self.listMostRecentlyUsed.setHeadToNode(self.cache[key])
            return
        
        # Key not there. Append the data to the dict. Append the node to the Linked list. And if currentSize == maxCapacity evict least recently used item
        else:
            # New node
            newNode = DLinkedListNode(key,value)
            #  2 possibilities. cache full or not
            if self.currentSize == self.maxCapacity:
                self.evictLeastRecentlyUsed()

                # Add node to dictionary
                self.cache[key] = newNode
                # add node to list
                self.listMostRecentlyUsed.setHeadToNode(newNode)
            else:
                self.currentSize += 1
                
                # Add node to dictionary
                self.cache[key] = newNode
                # add node to list
                self.listMostRecentlyUsed.setHeadToNode(newNode)



    def evictLeastRecentlyUsed(self):
        # Get item to remove
        itemToRemove = self.listMostRecentlyUsed.tail
        
        # Remove from the dict
        del self.cache[itemToRemove.key]
        
        # Remove from the list
        self.listMostRecentlyUsed.removeTail()
        


# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)

class DLinkedList:
    def __init__(self):
        self.head = None
        self.tail = None
    
    # Either if is a new Node, or a old node I will use same method
    def setHeadToNode(self,node):
        # First. If node already head
        if self.head == node:
            return
        if self.head is None:
            self.head = node
            self.tail = node
            return
        if self.head == self.tail:
            self.head = node
            node.next = self.tail
            self.tail.prev = node
            return
        if node == self.tail:
            self.removeTail()
            # self.tail = node.prev
        # General case
        # Erase bindings of the node if there is any
        node.eraseBindings()

        node.next = self.head
        self.head.prev = node
        self.head = node

    def removeTail(self):
        if self.tail is None:
            return
        if self.tail == self.head:
            self.tail = None
            self.head = None
            return

        newTail = self.tail.prev
        self.tail.eraseBindings()
        self.tail = newTail


class DLinkedListNode:
    def __init__(self,key,value):
        self.key = key
        self.value = value
        self.next = None
        self.prev = None


    # Clean prev and next nodes if they exist
    def eraseBindings(self):
        if self.next is None and self.prev is None:
            return

        # Remove this node from the LinkedList, Be careful if prev or next does not exist
        if self.next is not None:
            self.next.prev = self.prev
        
        if self.prev is not None:
            self.prev.next = self.next

        self.next = None
        self.prev = None    



