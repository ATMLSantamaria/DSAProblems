from collections import deque
def removeIslands(matrix):

    

    # we will add here visited nodes
    visited = set()

    # We will set this to 1s when we are in continents
    continent = [[0 for value in row] for row in matrix]

    # Next Nodes to visit. We use a deque and pop to simulate a stack
    nextNodesToExplore = []

    rows = len(matrix)
    cols = len(matrix[0])

    for j in range(cols):
        nextNodesToExplore.append((0,j)) # write j in first row
        nextNodesToExplore.append((rows - 1,j)) #write j in last row
        
    for i in range(rows):
        nextNodesToExplore.append((i,0))
        nextNodesToExplore.append((i,cols - 1)) #last colum

    # Now we have all the nodes that could be a continent added to the nodes to explore.
    # we need to traverse them adn their neighbours 
        
        
    while len(nextNodesToExplore):
        currentNode = nextNodesToExplore.pop()
        i = currentNode[0]
        j = currentNode[1]
        if currentNode in visited:
            continue
        if matrix[i][j] == 1:
            continent[i][j] = 1
            # Check next nodes only if we are in a 0
            # Extract the nodes to visit
            unVisitedNeighbours = traverseNodes(i,j,matrix,visited)
            # Add them to the stack
            for node in unVisitedNeighbours:
                nextNodesToExplore.append(node)
        visited.add((i,j))



    
    return continent



def traverseNodes(i,j,matrix,visited):
    nextNodes = []
    if i > 0 and (i - 1,j) not in visited:# and matrix[i-1][j] == 1:
        nextNodes.append((i - 1,j))
        
    if i < len(matrix) - 1 and (i + 1,j) not in visited:# and matrix[i+1][j] == 1:
        nextNodes.append((i + 1,j))
        
    if j > 0 and (i,j - 1) not in visited:# and matrix[i][j-1] == 1:
        nextNodes.append(((i,j - 1)))
        
    if j < len(matrix[0]) - 1 and (i,j + 1) not in visited:# and matrix[i][j+1] == 1:
       nextNodes.append((i,j + 1)) 
    return nextNodes
        