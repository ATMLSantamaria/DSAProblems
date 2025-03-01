from collections import deque
# Do not edit the class below except
# for the breadthFirstSearch method.
# Feel free to add new properties
# and methods to the class.
class Node:
    def __init__(self, name):
        self.children = []
        self.name = name

    def addChild(self, name):
        self.children.append(Node(name))
        return self

    # Time O(v+e) space O(v)
    def breadthFirstSearch(self, array):
        queue = deque()
        queue.append(self)

        while len(queue) > 0:
            current = queue.popleft()
            array.append(current.name)
            for child in current.children:
                queue.append(child)
        return array
        
