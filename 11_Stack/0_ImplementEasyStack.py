from collections import deque


class Stack:
    
    # Stack follow LIFO -> Last In First Out
    def __init__(self):
        self.stack = deque()

    def push(self,item):
        # Add element to the top of the stack
        self.stack.append(item)

    def pop(self):
        # Remove element from deque
        if not self.is_empty():
            return self.stack.pop()
        else:
            raise IndexError("Pop from empty stack")
    
    def peek(self):

        if not self.is_empty():
            # Como implementamos el stack de una deque, necesitamos acceder al ultimo elemento de la deque, que seria el primero en el stack
            return self.stack[-1]    
        else:
            raise IndexError("Pop from empty stack")
        
    def is_empty(self):
        return len(self.stack) == 0
    
    def size(self):
        return len(self.stack)
    
            

    
    

myStack = Stack()

for i in range(10):
    myStack.push(i)

while not myStack.is_empty():
    print(myStack.pop())
