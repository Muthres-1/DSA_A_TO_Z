def uniquePath(m,n,row,col,matrix): 
    if m==1 and n==1 and matrix[0][0]==1:return 0    
    if m==1 and n==1 and matrix[0][0]==0:return 1    
    if row>=0 and col>=0 and matrix[row][col]==1:return 0
    if row==m-1 and col ==n-1 :
        return 1
    elif row>=m or col >=n: return 0
    right=0
    up=0
    if col<n-1 and matrix[row][col+1]!=1:
        right=uniquePath(m,n,row,col+1,matrix)
    if row<m-1 and matrix[row+1][col]!=1:
        up=uniquePath(m,n,row+1,col,matrix)
        
    return up+right 
m=1
n=3
matrix=[[0,1,0]]
print(uniquePath(m,n,0,0,matrix)) 

# dp solution
# def uniquePath(m,n,row,col,matrix,tabu): 
#     if m==1 and n==1 and matrix[0][0]==1:return 0    
#     if m==1 and n==1 and matrix[0][0]==0:return 1    
#     if row>=0 and col>=0 and matrix[row][col]==1:return 0
#     if row==m-1 and col ==n-1 :
#         return 1
#     elif row>=m or col >=n: return 0
#     if tabu[row][col]!=-1:return tabu[row][col]
#     right=0
#     up=0
#     if col<n-1 and matrix[row][col+1]!=1:
#         right=uniquePath(m,n,row,col+1,matrix,tabu)
#     if row<m-1 and matrix[row+1][col]!=1:
#         up=uniquePath(m,n,row+1,col,matrix,tabu)
#     tabu[row][col]=up+right    
#     return tabu[row][col]
# m=3
# n=3
# matrix=[[0,0,0],[0,1,0],[0,0,0]]
# tabu=[[-1 for _ in range(n)] for _ in range(m)]
# print(uniquePath(m,n,0,0,matrix,tabu)) 

# tabulation with the help of for loop
#  we are going to question such that we are at (0,0) and we need to go (m-1,n-1) and we can take step bottom and left
# def uniquePath(m,n,tabu,matrix):
    # if m==1 and n==1 and matrix[0][0]==1:return 0    
    # if m==1 and n==1 and matrix[0][0]==0:return 1        
#     for i in range(0,m,1):
#         for j in range(0,n,1):
#             if matrix[i][j]==1:
#                 tabu[i][j]=0
#                 continue
#             if i==0 and j==0 :
#                 tabu[i][j]=1
#                 continue
#             up=0
#             left=0
#             # there is given according to question bottom and right. but we are moving far away from destination so opposite of both up and left
#             if i>=1:
#                 up=tabu[i-1][j]
#             if j>0:
#                 left=tabu[i][j-1]
#             tabu[i][j]=up+left
#     return tabu[m-1][n-1]
# m=1
# n=3
# matrix=[[0,1,0]]
# tabu=[[-1 for _ in range(n)] for _ in range(m)]
# print(uniquePath(m,n,tabu,matrix))    

# Space Optimization
def uniquePath(m,n,matrix):
    if m==1 and n==1 and matrix[0][0]==1:return 0    
    if m==1 and n==1 and matrix[0][0]==0:return 1
    tabu=[0]*(n)
    for i in range(m):
        temp=[0]*(n)
        for j in range(n):
            if matrix[i][j]==1:
                temp[j]=0
                continue
            if i==0 and j==0:
                temp[i]=1
                continue
            up=0
            left=0
            if i>0:
                up=tabu[j]
            if j>0:
                left=temp[j-1]
            temp[j]=up+left
        tabu=temp    
    return tabu[n-1]    
m=1
n=1
matrix=[[1]]
print(uniquePath(m,n,matrix))  
    