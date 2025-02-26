# This is an input class. Do not edit.



# Iterative solution. I need a stack
from collections import deque
class BinaryTree:
    def __init__(self, value, left=None, right=None):
        self.value = value
        self.left = left
        self.right = right


def symmetricalTree(tree):
    # Write your code here.
    # Represent Left subtree
    stackLeft = Stack()
    stackLeft.push(tree.left)
    # Represent Right subtree
    stackRight = Stack()
    stackRight.push(tree.right)

    while len(stackLeft) > 0:
        currentLeft = stackLeft.pop()
        currentRight = stackRight.pop()

        if currentLeft is None and currentRight is None:
            continue
        if currentLeft is None or currentRight is None or currentLeft.value != currentRight.value:
            return False


        # The stack keep the elements in the correct order and position so they can be compared at the beginning of the while loop
        stackLeft.push(currentLeft.left)
        stackLeft.push(currentLeft.right)
        stackRight.push(currentRight.right)
        stackRight.push(currentRight.left)
    # If we arrive to the end without finding a False
    return True
        
        

    

    
    


class Stack:
    def __init__(self):
        self.stack = deque()
    def push(self,item):
        self.stack.append(item)
    def pop(self):
        return self.stack.pop()
    def peek(self):
        return self.stack[-1]
    def __len__(self):
        return len(self.stack)

    

