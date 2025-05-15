# increasing meaning only "greater than "
def countLIS(nums):
    n = len(nums)
    dp = [1] * n 
    count=[1]*(n)
    maxi=1
    for i in range(n):
        for j in range(i):
            if nums[i] > nums[j] and dp[j]+1>dp[i]: #This don't execute in the time of dp[i]+1 =dp[i]
                dp[i] = dp[j]+1
                count[i]=count[j]  
            elif nums[i]>nums[j] and dp[j]+1==dp[i]:
                count[i]+=count[j]
        maxi=max(maxi,dp[i])        
    countLIS=0
    print(dp)
    print(count)
    for i in range(n):
        if maxi==dp[i]:
            countLIS+=count[i]                              
    return countLIS                
nums = [10,9,2,5,3,7,101,18]
print(countLIS(nums))