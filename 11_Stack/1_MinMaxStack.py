from collections import deque
# Feel free to add new properties and methods to the class.
class MinMaxStack:
    def __init__(self):
        self.minStack = deque()
        self.maxStack = deque()
        self.stack = deque()
    def peek(self):
        return self.stack[-1]

    def pop(self):
        self.minStack.pop()
        self.maxStack.pop()
        return self.stack.pop()

    def push(self, number):

        if not self.minStack:
            self.minStack.append(number)
        else:
            self.minStack.append(min(number,self.getMin()))

        if not self.maxStack:
            self.maxStack.append(number)
        else:
            self.maxStack.append(max(number,self.getMax()))
        
        
        self.stack.append(number)
        
        

    def getMin(self):
        return self.minStack[-1]

    def getMax(self):
        return self.maxStack[-1]
