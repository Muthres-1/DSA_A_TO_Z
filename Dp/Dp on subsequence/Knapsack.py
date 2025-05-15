# def stealThing(val,wt,weight,index):
#     if index==0:
#         if weight>=wt[0]:return val[0]
#         else:return 0 
#     if weight==0:
#         return 0    
#     notTake=stealThing(val,wt,weight,index-1)
#     take=-int(1e9)
#     if weight>=wt[index]:
#         take=val[index] + stealThing(val,wt,weight-wt[index],index-1)
#     return max(take,notTake)        
# n = 3
# w = 4
# val= [1,2,3]
# wt = [4,5,1]
# print(stealThing(val,wt,w,n-1))

# DP solution or Time complexity Optimization 
# def stealThing(val,wt,weight,index,dp):
#     if index==0:
#         if weight>=wt[0]:return val[0]
#         else:return 0
#     if weight==0:
#         return 0    
#     if dp[index][weight]!=-1:return dp[index][weight]
#     notTake=stealThing(val,wt,weight,index-1,dp)
#     take=-int(1e9)
#     if weight>=wt[index]:
#         take=val[index] + stealThing(val,wt,weight-wt[index],index-1,dp)
#     dp[index][weight]=max(take,notTake) 
#     return dp[index][weight]
# n = 3
# w = 4
# val= [1,2,3]
# wt = [4,5,1]
# dp=[[-1 for _ in range(w+1)] for _ in range(n)]
# print(stealThing(val,wt,w,n-1,dp))

# Space Optimization  using Tabulation 

# def stealThingTabulation(val,wt,w,n):
#     dp=[[0 for _ in range(w+1)] for _ in range(n)]
#     for i in range(w+1):
#         if i>=wt[0]:
#             dp[0][i]=val[0]
#     for i in range(1,n):
#         for j in range(w+1):
#             notTake=dp[i-1][j]
#             take=-int(1e9)
#             if j>=wt[i]:
#                 take=val[i]+dp[i-1][j-wt[i]]
#             dp[i][j]=max(take,notTake)
#     return dp[n-1][w]                    
# n = 3
# w = 4
# val= [1,2,3]
# wt = [4,5,1]
# print(stealThingTabulation(val,wt,w,n))

# more Space and time complexity Optimization 

# def stealThingTabulation(val,wt,w,n):
#     prev=[0]*(w+1)
#     for i in range(w+1):
#         if i>=wt[0]:
#             prev[i]=val[0]
#     for i in range(1,n):
#         curr=[0]*(w+1)
#         for j in range(w+1):
#             notTake=prev[j]
#             take=-int(1e9)
#             if j>=wt[i]:
#                 take=val[i]+prev[j-wt[i]]
#             curr[j]=max(take,notTake)
#         prev=curr    
#     return prev[w]                    
# n = 3
# w = 4
# val= [1,2,3]
# wt = [4,5,1]
# print(stealThingTabulation(val,wt,w,n))

#  More Optimization 
def stealThingTabulation(val,wt,w,n):
    prev=[0]*(w+1)
    for i in range(w+1):
        if i>=wt[0]:
            prev[i]=val[0]
    for i in range(1,n):
        for j in range(w,-1,-1):
            notTake=prev[j]
            take=-int(1e9)
            if j>=wt[i]:
                take=val[i]+prev[j-wt[i]]
            prev[j]=max(take,notTake)
    return prev[w]                    
n = 3
w = 4
val= [1,2,3]
wt = [4,5,1]
print(stealThingTabulation(val,wt,w,n))