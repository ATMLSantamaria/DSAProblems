from collections import deque
class MinStack:

    def __init__(self):
        self.minStack = deque()
        self.stack = deque()
        

    def push(self, val: int) -> None:
        # stack empty
        if len(self.minStack) == 0:
            self.minStack.append(val)
            self.stack.append(val)
            return
        # General case. Element either bigger or smaller
        if val <= self.minStack[-1]:
            self.minStack.append(val)
        else:
            self.minStack.append(self.minStack[-1])
        
        self.stack.append(val)

        

    def pop(self) -> None:
        if len(self.stack) == 0:
            return
        self.minStack.pop()
        self.stack.pop()
        

    def top(self) -> int:
        if len(self.stack) == 0:
            raise Exception("Empty stack")
        return self.stack[-1]
        

    def getMin(self) -> int:
        if len(self.minStack) == 0:
            raise Exception("Empty stack")
        return self.minStack[-1]
        
        


# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(val)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()