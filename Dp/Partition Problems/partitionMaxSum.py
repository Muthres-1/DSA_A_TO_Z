# def maxSum(arr,index,k,n):
#     if index==n:
#         return 0
#     length=0
#     maxi=float('-inf')
#     sum=0
#     ans= float('-inf')
#     for i in range(index,min(n,index+k)):
#         length+=1
#         maxi=max(maxi,arr[i])
#         sum=length*maxi+maxSum(arr,i+1,k,n)
#         ans=max(ans,sum)
#     return ans  
# arr = [1,15,7,9,2,5,10]
# k = 3  
# print(maxSum(arr,0,k,len(arr)))

# Optimization using dp 

# def maxSum(arr,index,k,n,dp):
#     if index==n:
#         return 0
#     if dp[index]!=-1:return dp[index]
#     length=0
#     maxi=float('-inf')
#     sum=0
#     ans= float('-inf')
#     for i in range(index,min(n,index+k)):
#         length+=1
#         maxi=max(maxi,arr[i])
#         sum=length*maxi+maxSum(arr,i+1,k,n,dp)
#         ans=max(ans,sum)
#     dp[index]=ans    
#     return ans  
# arr = [1,15,7,9,2,5,10]
# k = 3  
# n=len(arr)
# dp=[-1 for i in range(n)] 
# print(maxSum(arr,0,k,n,dp))

#Optimization using Tabulation  


def maxSum(arr,k):
    n=len(arr)
    dp=[0 for i in range(n+1)]
    for endPoint in range(n-1,-1,-1):
            length=0
            maxi=float('-inf')
            sum=0
            ans= float('-inf')
            for i in range(endPoint,min(n,endPoint+k)):
                length+=1
                maxi=max(maxi,arr[i])
                sum=length*maxi+dp[i+1]
                ans=max(ans,sum)
            dp[endPoint]=ans
    return dp[0]     
arr = [1,15,7,9,2,5,10]
k = 3  
print(maxSum(arr,k))
