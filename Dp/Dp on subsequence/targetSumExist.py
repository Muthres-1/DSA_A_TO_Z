# These solutions will not work for negative value of array for negative value there is another file negative Target sum file

# Recursive solution 
# def targetSum(i,n,arr,target):
#     if i>=n or target<0:
#         return 0
#     if target==0: 
#         return 1
#     return targetSum(i+1,n,arr,target-arr[i]) or targetSum(i+1,n,arr,target)
# arr = [3, 34, 4, 12, 5, 2]
# target = 30
# print(targetSum(0,len(arr),arr,target))
# time limit exceeded

# Dp based Solution  
# Tabulation vs. Memoization:
# Memoization: Top-down approach where recursion is used and results are stored in a table. This is what your code is doing.
# Tabulation: Bottom-up approach where you iteratively fill up a table based on previously computed values.
# memoization 
# def targetSum(n,arr,target,dp):
#     if target==0:
#         return 1
#     if n<0 or target<0:
#         return 0
#     if dp[n][target]!=-1:
#         return dp[n][target]    
#     dp[n][target]=targetSum(n-1,arr,target-arr[n],dp) or targetSum(n-1,arr,target,dp)
#     return dp[n][target]
# arr = [3, 34, 4, 12, 5, 2]
# sum = 9
# dp=[[-1 for _ in range(sum+1)] for _ in range(len(arr))]
# l=targetSum(len(arr)-1,arr,sum,dp)
# if l==1:
#     print("1")
# else:print("0")    

# Tabulation solution 
# def targetSum(n,arr,target):
#     dp=[[False for _ in range(target+1)] for _ in range(n)]
#     for i in range(n):
#         dp[i][0]=True
#     if arr[0]<=target:
#         dp[0][arr[0]]=True
#     for i in range(1,n):
#         for j in range(1,target+1):
#             not_take=dp[i-1][j]
#             take=False
#             if arr[i]<=j:
#                 take=dp[i-1][j-arr[i]]
#             dp[i][j]=take or not_take
#     return dp[n-1][target]                    
# arr = [3, 34, 4, 12, 5, 2]
# sum = 9
# print(targetSum(len(arr),arr,sum))
# space Optimization 
def targetSumOpt(n,arr,target):
    prev=[False]*(target+1)
    prev[0]=True
    if arr[0]<=target:
        prev[arr[0]]=True
    for i in range(1,n):
        curr=[False]*(target+1)
        curr[0]=True
        for j in range(1,target+1):
            take=prev[j]
            notTake=False
            if arr[i]<=j:
                notTake=prev[j-arr[i]]
            curr[j]=take or notTake
        prev=curr
    return prev[target]                
arr = [3, 34, 4, 12, 5, 2]
sum = 34
print(targetSumOpt(len(arr),arr,sum))
# These above all codes won't work for the negative value in array
