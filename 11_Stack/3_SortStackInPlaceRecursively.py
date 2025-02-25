

# We use test as if it would be a stack. We can only append element at the end or pop element for the end. Essentially a push,pop

# This problem we will solve recursively, for sorting we need to pop all elements out of the stack, and then input then again in the correct order


# You need 2 recursive calls. 1 sort stack will call itself until popping all elements. After that recursive call enter the insertInsortedPosition, that will insert elements in place, also poping elements until reach the ordered palce and then inserting

# Complexity O(n^2)
def sortStack(stack):
    # Base case. Stack is already empty
    if len(stack) == 0:
      return stack
    
    # We need to pop an element before the recursive call
    top = stack.pop()

    # Then recursively call sort stack so continue popping elements before start to inserting in correct order
    sortStack(stack)

    # Now we need to insert an element, but we need to assure that the element is inserted in its correct position, for that we need another recursive call
    insertInSortedPosition(stack,top)

    return stack

# This function will assure that the element is inserted correctly. It will pop elements until reach the correct place
def insertInSortedPosition(stack,top):
  #  Base case. Stack empty or top in correct position. We simply need to insert top
  if len(stack) == 0 or stack[-1] <= top:
      stack.append(top)
      return
  
  # General case. The top element is not ordered. We need to pop elements fropm the stack until reach to itds final destination, and then append all elements after it
  tmp = stack.pop()

  # This function is recursively call until reach correct place and then return
  insertInSortedPosition(stack,top)

  # After inserting element, append the popped elemet

  stack.append(tmp)
  




  

























test = [5,3,7,3,8,9]

correctSolution = sorted(test)

print(correctSolution)




print(sortStack(test))