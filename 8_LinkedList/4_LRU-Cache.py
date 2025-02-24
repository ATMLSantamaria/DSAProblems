
# So, for this we need. A LRUCache class and a doubly LinkedList Class

# LRUCache class
class LRUCache:
    def __init__(self,maxSize):
        self.maxSize = maxSize or 1
        self.currentSize = 0
        self.cache = {}
        self.listMostRecentUsed = DoublyLinkedList()
    
    def insertKeyValuePair(self,key,value):
        if key not in self.cache:
            # Key not in the case. 2 cases. We need to evict or we dont need
            if self.currentSize == self.maxSize:
                # We evict tail before adding anything
                self.evictLeastRecent()
            else:
                # Cache not full
                self.currentSize += 1
            # In Both cases we need to add the key,value to the cache
            self.cache[key] = DoublyLinkedListNode(key,value)
                
        else:
            # Simply replace value
            self.replaceValueInKey(key,value)
        
        # Now we need to make this last value the Most recently Used key,value pair
        self.updateMostRecent(self.cache[key])
        # self.listMostRecentUsed.setHeadTo(self.cache[key])
            
    
    def getValueFromKey(self,key):
        # Check if present
        if key not in self.cache:
            return None
        # Access if Present and update it to the most recent value
        self.updateMostRecent(self.cache[key])
        # self.listMostRecentUsed.setHeadTo(self.cache[key])
        return self.cache[key].value
    
    def getMostRecentKey(self):
        return self.listMostRecentUsed.head.key
    
    def evictLeastRecent(self):
        # We delete last element from the linked list and from the cache

        # Get key to evict
        keyToEvict = self.listMostRecentUsed.tail.key

        # Remove from the linked list
        self.listMostRecentUsed.removeTail()

        # Remove from se;f.Cache
        del self.cache[keyToEvict]

    def updateMostRecent(self,node):
        # Put the node in the head of the list
        self.listMostRecentUsed.setHeadTo(node)
        

        
    
    def replaceValueInKey(self,key,value):
        if key not in self.cache:
            raise Exception("Error: Key not in cache")
        # Recuerda que el cache es un hastacbe de key : DoublyLinkedListNode
        self.cache[key].value = value
    
# DoublyLinked List

class DoublyLinkedList:
    def __init__(self):
        self.head = None
        self.tail = None
    
    def setHeadTo(self,node):
        # Already head
        if self.head == node:
            return
        # head = None. Empty List
        elif self.head is None:
            self.head = node
            self.tail = node
        # head == tail
        elif self.head == self.tail:
            self.head = node
            self.head.next = self.tail
            self.tail.prev = self.head
        
        else:
            # General
            ## Case where the node was the tail
            if node == self.tail:
                self.removeTail()
            node.removeBindings()

            self.head.prev = node
            node.next = self.head
            self.head = node
    def removeTail(self):
        # Tail none
        if self.tail is None:
            return
        # tail==head
        if self.tail == self.head:
            self.tail = None
            self.head = None
            return
        # General
        self.tail = self.tail.prev
        self.tail.next = None



# DoublyLinkedListNode
class DoublyLinkedListNode:
    def __init__(self,key,value):
        self.key = key
        self.value = value
        self.next = None
        self.prev = None

    def removeBindings(self):
        # self.next is None
        if self.next is not None:
            self.next.prev = self.prev
        # self.prev is None
        if self.prev is not None:
            self.prev.next = self.next

        # General
        self.prev = None
        self.next = None