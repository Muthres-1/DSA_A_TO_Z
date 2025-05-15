# def targetSum(n,arr,target,dp):    
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
# def minPartitionDifference(nums):
#     n=len(nums)
#     sum=0
#     for i in range(n):
#         sum+=nums[i]
#     dp=[[False for _ in range(sum+1)] for _ in range(n)]
#     targetSum(n,nums,sum,dp)
#     mini=sum
#     for i in range(int(sum/2)):
#         if dp[n-1][i]:
#             s2=sum-i
#             mini=min(mini,abs(i-s2))
#     return mini
# nums = [3,9,7,3]
# print(minPartitionDifference(nums))

# This won't work for negative value in array

def targetSum(i,n,arr,target):
    if i==n and target==0:
        return 1
    elif i==n and target!=0:return 0
    if target==0:
        return 1
    return targetSum(i+1,n,arr,target-arr[i]) or targetSum(i+1,n,arr,target)
arr = [3, -34, 4, 12, 5, 2]
target =-34
print(targetSum(0,len(arr),arr,target))