class Solution(object):
    def helper(self, nums, target, n, index, memo):
        # Base case: target is 0, which means we've found a subset
        if target == 0:
            return True
        # If we are out of bounds or the target is negative, return False
        if index >= n or target < 0:
            return False
        # Check if we've already solved this subproblem
        if (index, target) in memo:
            return memo[(index, target)]
        
        # Recursive call: choose the current element or skip it
        include = self.helper(nums, target - nums[index], n, index + 1, memo)
        exclude = self.helper(nums, target, n, index + 1, memo)
        
        # Store the result in the memoization dictionary
        memo[(index, target)] = include or exclude
        return memo[(index, target)]
   
    def canPartition(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        n = len(nums)
        total_sum = sum(nums)
        
        # If the total sum is odd, we cannot partition into two equal subsets
        if total_sum % 2 != 0:
            return False
        
        target = total_sum // 2
        memo = {}
        return self.helper(nums, target, n, 0, memo)

    
# def targetSumOpt(n,arr,target):
#     prev=[False]*(target+1)
#     prev[0]=True 
#     if arr[0]<=target:
#         prev[arr[0]]=True 
#     for i in range(1,n):
#         curr=[False]*(target+1)
#         curr[0]=True
#         for j in range(1,target+1):
#             take=prev[j]
#             notTake=False
#             if arr[i]<=j: 
#                 notTake=prev[j-arr[i]]
#             curr[j]=take or notTake
#         prev=curr
#     return prev[target]                
# def equalPartition(nums):
#     n=len(nums)
#     sum=0
#     for i in range(n):
#         sum+=nums[i]
#     if sum%2:return False
#     return targetSumOpt(n,nums,sum/2)