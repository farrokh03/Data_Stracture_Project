def sparse_matrix(matrix,x):
    sparse = []
    for i in range(x): 
        for j in range(x):
            if matrix[i][j] != 0:               
                sparse.append([[i],[j],matrix[i][j]])

    return sparse