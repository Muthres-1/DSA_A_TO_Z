# def uniquePath(m,n,row,col):
#     if row==m-1 and col ==n-1:
#         return 1
#     elif row>=m or col >=n: return 0
#     # right
#     return uniquePath(m,n,row,col+1)+uniquePath(m,n,row+1,col)
# m=3
# n=7
# print(uniquePath(m,n,0,0))    

# There is coming time limit exceed problem So we will this with the help of dp
# def uniquePath(m,n,row,col,memo):
#     if row==m-1 and col ==n-1:
#         return 1
#     elif row>=m or col >=n: return 0
#     if memo[row][col]!=-1: return memo[row][col]
#     # right and down
#     memo[row][col]=uniquePath(m,n,row,col+1,memo)+uniquePath(m,n,row+1,col,tabu)
#     return memo[row][col]
# m=3
# n=7
# memo=[[-1 for _ in range(n)] for _ in range(m)]
# print(uniquePath(m,n,0,0,memo))    

# Tabulation for above
def uniquePaths(m, n):#m=rows,n=coloums
        tabu=[[1 for i in range(n)] for j in range(m)]
        for i in range(n):
            tabu[0][i] = 1
        for i in range(m):
            tabu[i][0] = 1
        for i in range(1,m):
            for j in range(1,n):
                tabu[i][j]=tabu[i-1][j] + tabu[i][j-1]
        return tabu[m-1][n-1]       
# In above code at any i,j grid we can come from (0,0) via up or left side 
# more optimization
class Solution(object):
    def uniquePaths(self, m, n):
        curr=[1 for i in range(n)] 
        prev=[1 for i in range(n)]
        for i in range(1,m):
            for j in range(n):
                if j==0:
                    curr[j]=1
                else:
                    curr[j]=prev[j]+curr[j-1]
            prev=curr    
        return curr[n-1] 
         

# tabulation
#  we are going to question such that we are at (0,0) and we need to go (m-1,n-1) and we can take step bottom and left
# def uniquePath(m,n,tabu):    
#     for i in range(0,m,1):
#         for j in range(0,n,1):
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
    
# m=3
# n=7
# tabu=[[-1 for _ in range(n)] for _ in range(m)]
# print(uniquePath(m,n,tabu))    

# Space Optimization 

def uniquePath(m,n):
    tabu=[0]*(n) # tabu is for row and temp is for coloum
    for i in range(m):
        temp=[0]*(n)
        for j in range(n):
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
m=3
n=7
print(uniquePath(m,n))   
      