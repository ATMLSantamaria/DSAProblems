#  Main thing here to remember is:

# Create list of sets to store unique values

# index flattening techniques

# The rest is easy

def isValidSudoku(board):
    # This problem is tricky. You need to iterate across all tlements in the board
    
    # You need to place them in sets() corresponding to each colum,row and subboard

    # Basically I need 9 dictionaries for the rows, 9 dictionaries for the columas...

    # I need vectors of sets

    rows = [set() for _ in range(9)]
    colums = [set() for _ in range(9)]
    subBoards = [set() for _ in range(9)]

    # Now iterate and place
    for i in range(9):
        for j in range(9):
            
            currentNum = board[i][j]

            if currentNum == ".":
                continue
            
            
            # boxIndex is result of index flattening 
            # Used to map a 2D grid (i,j) into a flat array
            boardIndex = (i // 3) * 3 + (j // 3)

            # check existance before adding

            if currentNum in rows[i] or currentNum in colums[j] or currentNum in subBoards[boardIndex]:
                return False

            # fill rows sets is trivial
            rows[i].add(currentNum)
            # fil colums is also easy
            colums[j].add(currentNum)

            subBoards[boardIndex].add(currentNum)

    return True