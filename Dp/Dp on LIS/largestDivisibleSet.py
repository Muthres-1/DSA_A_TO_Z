def largestDivisible(arr):
    n=len(arr)
    if n==0 or n==1:return arr
    dp=[1]*(n)
    prev=[]
    arr.sort()
    length=0
    lastInd=-1
    for i in range(n):
        prev.append(i)
        for j in range(i):
            if arr[i]%arr[j]==0 and dp[i]<dp[j]+1:
                dp[i]=1+dp[j]
                prev[i]=j
        if length<dp[i]:
            length=dp[i]
            lastInd=i
    lst=[]
    lst.append(arr[lastInd])
    while(prev[lastInd]!=lastInd):
        lastInd=prev[lastInd]
        lst.append(arr[lastInd])
    return lst[::-1]
nums = [2,3,4,9,8]
print(largestDivisible(nums))

    
