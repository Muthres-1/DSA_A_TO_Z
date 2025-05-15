# Here increasing meaning is not equal to "equal or greater than" here meaning is only "greatere than"
# def LIS(arr,index,preIndex):
#     if index==len(arr):
#         return 0
#     notTake=LIS(arr,index+1,preIndex)
#     take=0
#     if arr[index]>arr[preIndex] or preIndex==-1: 
#         take=1+LIS(arr,index+1,index)
#     return max(take,notTake)
# nums =[7,7,7,7,7,7,7]
# print(LIS(nums,0,-1))   

# Optimization using dp

# def LIS(arr,index,preIndex,dp,n):
#     if index==n:
#         return 0
#     if dp[index][preIndex+1]!=-1:return dp[index][preIndex+1]
#     notTake=LIS(arr,index+1,preIndex,dp,n)
#     take=0
#     if arr[index]>arr[preIndex] or preIndex==-1: 
#         take=1+LIS(arr,index+1,index,dp,n)
#     dp[index][preIndex+1]=max(take,notTake)
#     return dp[index][preIndex+1]
# nums =[7,7,7,7,7,7,7]
# n=len(nums)
# dp=[[-1 for i in range(n+1)] for i in range(n)]
# print(LIS(nums,0,-1,dp,n))    

# Further more Optimization using Tabulation 


# def LIS(nums):
#     n = len(nums)
#     if n == 0:
#         return 0
#     dp = [[0 for _ in range(n + 1)] for _ in range(n + 1)]    
#     for index in range(n - 1, -1, -1):
#         for prev_index in range(index - 1, -2, -1):
#             notTake = dp[index + 1][prev_index + 1]
#             take = 0
#             if prev_index == -1 or nums[index] > nums[prev_index]:
#                 take = 1 + dp[index + 1][index + 1]
#             dp[index][prev_index + 1] = max(take, notTake)    
#     return dp[0][0]
# nums = [7, 7, 7, 7, 7, 7, 7]
# print(LIS(nums))



def LIS(nums):
    n = len(nums)
    dp = [1] * n 
    maxi=0
    for i in range(n):
        for j in range(i):
            if nums[i] >nums[j]:
                dp[i] = max(dp[i], dp[j] + 1)
        maxi=max(maxi,dp[i])
    return maxi
nums = [2,5,7,101]
print(LIS(nums)) 
   
