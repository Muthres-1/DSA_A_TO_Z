def printLIS(nums):
    n=len(nums)
    dp=[1]*(n)
    maxi=-1
    lastInd=-1
    # hash=list(range(n)) #create a list and initialize with i also itself
    prev=[]
    # very important if we create a empty list and after if we assign like hash[i]=i then 
    # it will show error because we create empty list to increase the length of this
    # we need to use append method 
    for i in range(n):
        prev.append(i)
        for preInd in range(i):
            if nums[i]>nums[preInd] and dp[i]<1+dp[preInd]:
                dp[i]=1+dp[preInd]
                prev[i]=preInd
        if maxi<dp[i]:
            maxi=dp[i]
            lastInd=i
    lst=[]
    lst.append(nums[lastInd])        
    while prev[lastInd]!=lastInd:
        lastInd=prev[lastInd]
        lst.append(nums[lastInd])
    return lst[::-1]    
        

nums=[0,8,4,12,2,10,6,14,1,9,5,13,3,11,7,15]
print(printLIS(nums))                  

                

