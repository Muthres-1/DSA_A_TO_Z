# def minSumTriangle(triangle,row,col,m,sum):
#     if col<0:
#         return int(1e9)
#     if row>=m:
#         return sum  
#     if col>=len(triangle[row]):
#         return int(1e9)            
#     prevind=minSumTriangle(triangle,row+1,col-1,m,sum+triangle[row][col])
#     sameind=minSumTriangle(triangle,row+1,col,m,sum+triangle[row][col])
#     nextind=minSumTriangle(triangle,row+1,col+1,m,sum+triangle[row][col])
#     return min(sameind,nextind,prevind)
# triangle = [[-19,57],[-40,-5]]
# mini=int(1e9)
# for i in range(len(triangle[0])):
#     mini=min(mini,minSumTriangle(triangle,0,i,len(triangle),0))
# print(mini)    

# time limit exceeded here is dp based solution 

def minSumTriangle(triangle, row, col,dp):
    if row <  0:
        return 0
    if col>len(triangle[row]):
        return int(1e9)
    if col < 0 or col>=len(triangle[row]):
        return int(1e9)    
    if dp[row][col] != int(1e9):
        return dp[row][col]
    preind = triangle[row][col] + minSumTriangle(triangle, row - 1, col+1,dp)
    sameind = triangle[row][col] + minSumTriangle(triangle, row - 1, col,dp)
    nextind = triangle[row][col] + minSumTriangle(triangle, row - 1, col - 1,dp)
    
    dp[row][col] = min(sameind, nextind,preind)
    return dp[row][col]

triangle = [[-19,57],[-40,-5]]
m = len(triangle)
dp = [[int(1e9) for _ in range(len(triangle[i]))] for i in range(m)]
m=int(1e9)
for i in range(len(triangle[-1])):
    m=min(m,minSumTriangle(triangle, len(triangle)-1,i,dp))
print(m)