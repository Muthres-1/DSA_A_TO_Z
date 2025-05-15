def countSubset(n,target,arr):
    dp = [[0 for j in range(target + 1)] for i in range(n)]
    if arr[0]==0:
        dp[0][0]=2
    else:dp[0][0]=1
    for i in range(1,n):
        if arr[i]==0:
            dp[i][0]=dp[i-1][0]+1
        else:dp[i][0]=dp[i-1][0] 
    if arr[0] != 0 and arr[0] <= target:
        dp[0][arr[0]] = 1 
    for i in range(1,n):
        for j in range(target+1):
            notTaken=dp[i-1][j]
            Taken=0
            if arr[i]<=j:
                Taken=dp[i-1][j-arr[i]] 
            dp[i][j]=(Taken+notTaken)
    return dp[n-1][target]
           
class Solution(object):
    def findTargetSumWays(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        total_sum=0
        n =len(nums)
        for i in range(n):
            total_sum+=nums[i]
        if(total_sum-target<0):return 0
        if((total_sum-target)%2):return 0
        s2=(total_sum-target)//2
        return countSubset(n,s2,nums)