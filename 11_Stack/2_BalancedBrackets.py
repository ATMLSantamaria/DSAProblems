from collections import deque
def balancedBrackets(string):
    stack = Stack()
    balanced = True
    openingBrackets = "([{"
    closingBrackets = ")]}"
    matchingBrackets = {")" : "(","]" : "[" , "}" : "{"}
    
    for char in string:
        if char in openingBrackets:
            stack.push(char)
        elif char in closingBrackets:
            # SI no hay closing Bracket para el char MALO
            if len(stack) == 0:
                return False
            # Si el closing que esta en char, no tiene su correspondiented opening arriba del Stach MALO. Pero si lo tiene BIEN
            top = stack.peek()
            if top == matchingBrackets[char]:
                stack.pop()
            # Si no entramos en la opcion anterior MALO
            else:
                return False
    return len(stack) == 0

            

class Stack:
    def __init__(self):
        self.stack = deque()

    def push(self,item):
        self.stack.append(item)
    
    def pop(self):
        if len(self.stack) == 0:
            return None
        else:
            return self.stack.pop()
    def peek(self):
        if len(self.stack) == 0:
            return None
        return self.stack[-1]

    def __len__(self):
        return len(self.stack)