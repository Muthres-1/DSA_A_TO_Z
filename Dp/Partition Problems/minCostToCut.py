# def cutToCost(cut,start,end,n):
#     if start+1>=end:
#         return 0    
#     mini=int(1e9) 
#     for i in range(0,n):#assuming that cut is sorted
#         if cut[i]>=end or cut[i]<=start:continue
#         x=end-start + cutToCost(cut,start,cut[i],n) + cutToCost(cut,cut[i],end,n)
#         mini=min(mini,x)
#     if mini==1e9:return 0    
#     return mini  
# length=7
# cut=[1,3,4,5]
# n=len(cut)
# print(cutToCost(cut,0,length,n))  


# Optimization using dp memoization 


# def cutToCost(cut,start,end,n,dp):
#     if start+1>=end:
#         return 0    
#     if dp[start][end]!=-1:return dp[start][end]
#     mini=int(1e9) 
#     for i in range(0,n):
#         if cut[i]>=end or cut[i]<=start:continue
#         x=end-start + cutToCost(cut,start,cut[i],n,dp) + cutToCost(cut,cut[i],end,n,dp)
#         mini=min(mini,x)
#     if mini==1e9:
#         mini=0
#     dp[start][end]=mini    
#     return mini  
# length=7
# cut=[1,3,4,5]
# n=len(cut)
# dp=[[-1 for i in range(length+1)] for i in range(length)]
# print(cutToCost(cut,0,length,n,dp)) 

# Optimization using Tabulation 

# def cutToCost(cut,length):
#     n=len(cut)
#     dp=[[0 for i in range(length+1)] for i in range(length+1)]
#     for leng in range(length+1): #length of wood
#         for start in range(length-leng+1):  # starting point of wood
#             end=start+leng             #ending point of wood
#             mini=int(1e9) 
#             for i in range(0,n):
#                 if cut[i]>=end or cut[i]<=start:continue
#                 x=end-start +dp[start][cut[i]] + dp[cut[i]][end]
#                 mini=min(mini,x)
#             if mini==1e9:
#                 mini=0
#             dp[start][end]=mini
#     return dp[0][length]    
# length=7
# cut=[1,3,4,5]
# print(cutToCost(cut,length))     


# The all above three are giving time limit exceed 
# Here is better method to solve 
# if we sort cut array then we not need to check whole inner most loop 

# def f(cuts,i,j):
#     if i>j:#here if we do i>=j then it will throw wrong output 
#         return 0
#     cost=int(1e9)
#     for index in range(i,j+1):
#         x=cuts[j+1]-cuts[i-1] + f(cuts,i,index-1) + f(cuts,index+1,j)
#         cost=min(cost,x)
#     return cost    

# def minCost(cuts,length):
#         n=len(cuts)
#         cuts.insert(0,0)
#         cuts.append(length)
#         cuts.sort()
#         return f(cuts,1,n)
# length= 7
# cuts = [1,3,4,5]
# print(minCost(cuts,length))


# Optimization using dp 


# def f(cuts,i,j,dp):
#     if i>j:#here if we do i>=j then it will throw wrong output 
#         return 0
#     if dp[i][j]!=-1:return dp[i][j]
#     cost=int(1e9)
#     for index in range(i,j+1):
#         x=cuts[j+1]-cuts[i-1] + f(cuts,i,index-1,dp) + f(cuts,index+1,j,dp)
#         cost=min(cost,x)
#     dp[i][j]=cost    
#     return cost
# def cutProblem(cuts,length):
#     n=len(cuts)
#     cuts.insert(0,0)
#     cuts.append(length)
#     cuts.sort()
#     dp=[[-1 for i in range(n+1)] for i in range(n+1)] #Very Important
#     return f(cuts,1,n,dp)
# length= 7
# cuts = [1,3,4,5]
# print(cutProblem(cuts,length))


# Tabulation method

    
def min_cost(cuts,length,n):
    cuts = [0] + cuts + [length] # add zero and length in the starting and end of cuts array
    cuts.sort()    
    dp = [[0] * (n + 2) for _ in range(n + 2)]
    for i in range(n, 0, -1):
        for j in range(1, n + 1):
            if i > j:
                continue            
            mini = float('inf')            
            for ind in range(i, j + 1):
                ans = cuts[j + 1] - cuts[i - 1] + dp[i][ind - 1] + dp[ind + 1][j]
                mini = min(mini, ans)            
            dp[i][j] = mini    
    return dp[1][n]
length= 7
cuts = [1,3,4,5]
n=len(cuts)
print(min_cost(cuts,length,n))


