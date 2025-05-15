# Recursive solution
# def NinjaFriend(matrix,i,j1,j2,n,m):
#     if i>=n:
#         return 0
#     if j1<0 or j2<0 or j1>=m or j2>=m:
#         return -int(1e9)
#     maxi=-int(1e9)
#     for di in range(-1,2,1):
#         for dj in range(-1,2,1):
#             if j1==j2:
#                 ans=matrix[i][j1]+NinjaFriend(matrix,i+1,j1+di,j2+dj,n,m)
#             else:
#                 ans=matrix[i][j1]+matrix[i][j2]+NinjaFriend(matrix,i+1,j1+di,j2+dj,n,m)    
#             maxi=max(maxi,ans)    
  
#     return   maxi
# matrix = [[2, 3, 1, 2], [3, 4, 2, 2], [5, 6, 3, 5]]
# n=3
# m=4
# print(NinjaFriend(matrix,0,0,m-1,n,m))

# time limit exceeded

# memoization approach
# def NinjaFriend(matrix,i,j1,j2,n,m,dp):
#     if i>=n:
#         return 0
#     if j1<0 or j2<0 or j1>=m or j2>=m:
#         return -int(1e9)
#     if dp[i][j1][j2]!=-1:
#         return dp[i][j1][j2]
#     maxi=-int(1e9)
#     for di in range(-1,2,1):
#         for dj in range(-1,2,1):
#             if j1==j2:
#                 ans=matrix[i][j1]+NinjaFriend(matrix,i+1,j1+di,j2+dj,n,m,dp)
#             else:
#                 ans=matrix[i][j1]+matrix[i][j2]+NinjaFriend(matrix,i+1,j1+di,j2+dj,n,m,dp)    
#             maxi=max(maxi,ans)    
#     dp[i][j1][j2]=maxi
#     return   maxi
# matrix = [[2, 3, 1, 2], [3, 4, 2, 2], [5, 6, 3, 5]]
# n=3
# m=4
# dp = [[[-1 for j in range(m)] for i in range(m)] for k in range(n)]
# print(NinjaFriend(matrix,0,0,m-1,n,m,dp))

# time limit exceeded
# tabulation approach

# def NinjaFriend(matrix,n,m):
#     dp=[[[-1 for _ in range(m)] for i in range(m)] for j in range(n)]
#     for j1 in range(m):
#         for j2 in range(m):
#             if j1==j2:
#                 dp[n-1][j1][j2]=matrix[n-1][j2]
#             else:
#                 dp[n-1][j1][j2]=matrix[n-1][j1] + matrix[n-1][j2] 

#     for i in range(n - 2, -1, -1):
#         for j1 in range(m):
#             for j2 in range(m):
#                 maxi=-int(1e9)
#                 for di in range(-1, 2):
#                     for dj in range(-1, 2):
#                         ans = 0
#                         if j1 == j2:
#                             ans = matrix[i][j1]
#                         else:
#                             ans = matrix[i][j1] + matrix[i][j2]
#                         if ((j1 + di < 0 or j1 + di >= m) or (j2 + dj < 0 or j2 + dj >= m)):
#                             ans += int(-1e9)  # A large negative value if out of bounds
#                         else:
#                             ans += dp[i + 1][j1 + di][j2 + dj]  # Add the value from the next row
#                         maxi = max(ans, maxi)
#                 # Store the maximum chocolates collected in the memoization table
#                 dp[i][j1][j2] = maxi
#     # Return the maximum chocolates collected in the top row and the last column
#     return dp[0][0][m - 1]                
# matrix = [[2, 3, 1, 2], [3, 4, 2, 2], [5, 6, 3, 5]]
# n=3
# m=4
# print(NinjaFriend(matrix,n,m))

# This is also giving time limit exceed 
