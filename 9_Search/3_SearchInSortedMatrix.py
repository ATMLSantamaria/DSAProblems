def searchInSortedMatrix(matrix, target):

    min_j = 0
    j = len(matrix[0]) - 1

    i = 0
    max_i = len(matrix) - 1

    while i <= max_i and j >= min_j:
        
        if matrix[i][j] == target:
            return [i,j]
        # if target < elemento arriba de columna, descartamops todos los elementos de esa columna
        #  Nos movemos hacia la columna previda
        elif target < matrix[i][j]:
            j -= 1
            continue
        # target > elemento a la derecha de la fila. Descartamos esa fila
        # nos movemos hacia la siguiente fila
        else:
            i += 1
    return [-1,-1]
        
