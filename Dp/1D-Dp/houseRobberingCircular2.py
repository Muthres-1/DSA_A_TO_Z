def robberingAmount(nums,s,e,n):
    if n==1:return nums[0]
    prev1=0
    prev2=0
    for i in range(s,e+1,1):
        curr=max(prev1,prev2+nums[i])
        prev2=prev1
        prev1=curr
    return prev1


nums=[2,3,2]    
n=len(nums)
print(max(robberingAmount(nums,0,n-2,n),robberingAmount(nums,1,n-1,n)))
        