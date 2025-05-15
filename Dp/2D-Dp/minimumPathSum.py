# def allPathSum(row,col,grid):
#     if row==0 and col==0:
#         return grid[row][col]
#     if row<0 or col<0 : return int(1e9)
#     return grid[row][col]+min(allPathSum(row-1,col,grid),allPathSum(row,col-1,grid))
# grid = [[1,3,1],[1,5,1],[4,2,1]] 
# print(allPathSum(2,2,grid))

#dp solution 

def allPathSum(row,col,grid,dp):
    if row==0 and col==0:
        return grid[row][col]
    if row<0 or col<0 : return int(1e9)
    if dp[row][col]!=-1 :return dp[row][col]
    dp[row][col]=grid[row][col]+min(allPathSum(row-1,col,grid,dp),allPathSum(row,col-1,grid,dp))
    return dp[row][col]
grid = [[1,3,1],[1,5,1],[4,2,1]] 
dp=[[-1 for _ in range(len(grid[0]))] for _ in range(len(grid))]
print(allPathSum(2,2,grid,dp))

# Tabulation Approach (meaning base case to upper case)
def allPathSumTabu(row,col,grid):
    dp=[[int(1e9) for _ in range(len(grid[0]))] for _ in range(len(grid))]
    for i in range(row):
        for j in range(col):
            if i==0 and j==0:
                dp[0][0]=grid[0][0]
                continue
            # find how many may come at index i,j from index (0,0)=> from top and left side se aa sakte h
            left=int(1e9)
            top=int(1e9)
            if j>0:
                left=dp[i][j-1]
            if i>0:
                top=dp[i-1][j]
            dp[i][j]=min(left,top)+grid[i][j]
    return dp[row-1][col-1]
grid = [[1,3,1],[1,5,1],[4,2,1]] 
print(allPathSumTabu(3,3,grid))        

# Space Optimization 
def allPathSumOptimize(row,col,grid):
    dp=[int(1e9)]*(col)
    for i in range(row):
        temp=[int(1e9)]*(col)
        for j in range(col):
            if i==0 and j==0:
                temp[0]=grid[0][0]
                continue
            # find how many may come at index i,j from index (0,0)=> from top and left side se aa sakte h
            left=int(1e9)
            top=int(1e9)
            if j>0:
                left=temp[j-1]
            if i>0:
                top=dp[j]
            temp[j]=min(left,top)+grid[i][j]
        dp=temp    
    return dp[col-1]
grid = [[1,3,1],[1,5,1],[4,2,1]] 
print(allPathSumOptimize(3,3,grid))      