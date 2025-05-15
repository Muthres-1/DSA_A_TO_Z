# def longestBitonic(nums,n):
#     dp1=[1]*(n)
#     dp2=[1]*(n)
#     for i in range(n):
#         for j in range(i):
#             if nums[i]>nums[j] and dp1[i]<dp1[j]+1:
#                 dp1[i]=dp1[j]+1
#     for i in range(n-1,-1,-1):
#         for j in range(n-1,i,-1):
#             if nums[i]>nums[j] and dp2[i]<dp2[j]+1:
#                 dp2[i]=dp2[j]+1
#     maxi=1            
#     for i in range(n):
#         maxi=max(maxi,dp1[i]+dp2[i]-1)
#     return maxi 
# n = 3
# nums= [5,7,9]  
# print(longestBitonic(nums,n))


# If we don't consider those who are just increasing and decreasing 
def longestBitonic(nums,n):
    dp1=[1]*(n)
    dp2=[1]*(n)
    for i in range(n):
        for j in range(i):
            if nums[i]>nums[j] and dp1[i]<dp1[j]+1:
                dp1[i]=dp1[j]+1
    for i in range(n-1,-1,-1):
        for j in range(n-1,i,-1):
            if nums[i]>nums[j] and dp2[i]<dp2[j]+1:
                dp2[i]=dp2[j]+1
    print(dp1)
    print(dp2)            
    maxi=0          
    for i in range(n):
        if dp1[i]!=1 and dp2[i]!=1:
            maxi=max(maxi,dp1[i]+dp2[i]-1)
    return maxi 
n = 3
nums= [5,7,9]  
print(longestBitonic(nums,n))
