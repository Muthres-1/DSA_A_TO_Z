# def coinChange(deno,target,index):
#     if index==0:
#         if target%deno[0]==0:return target//deno[0]
#         else:return int(1e9)
#     if target==0:return 0
#     notTake=coinChange(deno,target,index-1)
#     take=int(1e9)
#     if target>=deno[index]:
#         # Very Important Message 
#         # l=target//deno[index]
#         # take=l + coinChange(deno,target-l*deno[index],index-1) # This will give wrong answer 
#         take=1 + coinChange(deno,target-deno[index],index)
#     return min(take,notTake)
# coins = [186,419,83,408]
# amount = 6249  
# print(coinChange(coins,amount,len(coins)-1))

#  DP Based solution Or Time complexity Optimization 

# def coinChange(deno,target,index,dp):
#     if index==0:
#         if target%deno[0]==0:return target//deno[0]
#         else:return int(1e9)
#     if target==0:return 0
#     if dp[index][target]!=int(1e9):return dp[index][target]
#     notTake=coinChange(deno,target,index-1,dp)
#     take=int(1e9)
#     if target>=deno[index]:
#         # Very Important Message 
#         # l=target//deno[index]
#         # take=l + coinChange(deno,target-l*deno[index],index-1) # This will give wrong answer 
#         take=1 + coinChange(deno,target-deno[index],index,dp)
#     dp[index][target]=min(take,notTake)
#     return dp[index][target]
# coins = [186,419,83,408]
# amount = 6249  
# n=len(coins)
# dp=[[int(1e9) for i in range(amount+1)] for j in range(n)]
# print(coinChange(coins,amount,n-1,dp))

# The above also getting time limit exceed 

# Time complexity Optimization using Tabulation 
# def coinChangeTabulation(deno,target):
#     n=len(deno)
#     dp=[[(1e9) for i in range(target+1)] for j in range(n)]
#     for i in range(target+1):
#         if i%deno[0]==0:dp[0][i]=i//deno[0]
#     for i in range(n):
#         dp[i][0]=0
#     for i in range(1,n):
#         for j in range(1,target+1):
#             notTake=dp[i-1][j]
#             take=int(1e9)
#             if j>=deno[i]:
#                 take=1+dp[i][j-deno[i]]
#             dp[i][j]=min(take,notTake)
#     return dp[n-1][target]                   
# coins = [186,419,83,408]
# amount = 6249  
# print(coinChangeTabulation(coins,amount))

# space Optimization 

def coinChangeTabulation(deno,target):
    n=len(deno)
    prev=[int(1e9)]*(target+1)
    for i in range(target+1):
        if i%deno[0]==0:prev[i]=i//deno[0]
    for i in range(1,n):
        curr=[int(1e9)]*(target+1)
        for j in range(target+1):
            notTake=prev[j]
            take=int(1e9)
            if j>=deno[i]:
                take=1+curr[j-deno[i]]
            curr[j]=min(take,notTake)
        prev=curr    
    return prev[target]                   
coins = [186,419,83,408]
amount = 6249  
print(coinChangeTabulation(coins,amount))


