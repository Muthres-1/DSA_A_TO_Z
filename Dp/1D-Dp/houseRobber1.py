# Recursive way
# def robberedAmount(n,nums,count):
#     if n<0: return count
#     l=robberedAmount(n-2,nums,count+nums[n]) #take or not take current 
#     count=max(l,robberedAmount(n-1,nums,count))
#     return count
# nums = [2,1,1,2]
# n=len(nums)
# count=0
# print(robberedAmount(n-1,nums,count))
# memoization method 

# Function to solve the problem using dynamic programming
# def solveUtil(ind, arr, dp):   
#     if dp[ind] != -1:
#         return dp[ind]    
#     if ind == 0:
#         return arr[ind]    
#     if ind < 0:
#         return 0    
#     pick = arr[ind] + solveUtil(ind - 2, arr, dp)    
#     nonPick = 0 + solveUtil(ind - 1, arr, dp)   
#     dp[ind] = max(pick, nonPick)   
#     return dp[ind]
# def solve(n, arr):    
#     dp = [-1 for i in range(n)]   
#     return solveUtil(n - 1, arr, dp)

#  using Tabulation 
def houseRobbering(nums):
    n=len(nums)
    dp=[0]*(n+1)
    dp[1]=nums[0]
    for i in range(2,n+1):
        pick=nums[i-1]+dp[i-2]
        notPick=dp[i-1]
        dp[i]=max(pick,notPick)
    return dp[n]
nums = [2, 1, 1, 2]
print(houseRobbering(nums))


# This is more optimized
# def robberingAmount(nums,n):
#     prev1=0
#     prev2=0
#     for i in range(0,n,1):
#         curr=max(prev1,prev2+nums[i])
#         prev2=prev1
#         prev1=curr
#     return prev1
# nums = [2,1,1,2]
# n=len(nums)
# print(robberingAmount(nums,n))
   

