def countSquare(matrix,rows,cols):
    dp=[[0 for i in range(cols)] for i in range(rows)]
    for i in range(rows):
        dp[i][0]=matrix[i][0]
    for j in range(cols):
        dp[0][j]=matrix[0][j]
    for i in range(1,rows):
        for j in range(1,cols):
            if matrix[i][j]==0:
                dp[i][j]=0
            else:
                dp[i][j]=1+ min(dp[i-1][j],dp[i][j-1],dp[i-1][j-1])
    sum=0            
    for i in range(rows):
        for j in range(cols):
            sum+=dp[i][j]
    return sum
matrix =[[1,0,1],[1,1,0],[1,1,0]]
print(countSquare(matrix,len(matrix),len(matrix[0])))


def countSquare(matrix,rows,cols):
    dp=[[0 for i in range(cols)] for i in range(rows)]
    sum=0
    for i in range(rows):
        dp[i][0]=matrix[i][0]
        sum+=dp[i][0]
    for j in range(1,cols):# here we started from 1 becase 0 is already counted or initilized in first loop
        dp[0][j]=matrix[0][j]
        sum+=dp[0][j]
    for i in range(1,rows):
        for j in range(1,cols):
            if matrix[i][j]==0:
                dp[i][j]=0
            else:
                dp[i][j]=1+ min(dp[i-1][j],dp[i][j-1],dp[i-1][j-1])
                sum+=dp[i][j]
    return sum
matrix =[[1,0,1],[1,1,0],[1,1,0]]
print(countSquare(matrix,len(matrix),len(matrix[0])))