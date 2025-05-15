# def subsetSum(arr,sum,index):
#     if index<0:
#         if sum==0:
#             return 1
#         else:return 0
#     return subsetSum(arr,sum-arr[index],index-1) + subsetSum(arr,sum,index-1)
# arr=[0,1,2,5,3,8]
# sum=8
# print(subsetSum(arr,sum,len(arr)-1)) 

# Optimization using dp
# This won't work for negative but this will work for given question --- https://www.geeksforgeeks.org/problems/perfect-sum-problem5633/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=perfect-sum-problem

def subsetSum(arr,sum,index,dp):
    if index<0:
        if sum==0:
            return 1
        else:return 0
    if sum<0:return 0    
    if dp[index][sum]!=-1:return dp[index][sum]    
    dp[index][sum]= subsetSum(arr,sum-arr[index],index-1,dp) + subsetSum(arr,sum,index-1,dp)
    return dp[index][sum]
arr=[0,1,2,5,3,8]
sum=8
n=len(arr)
dp=[[-1 for i in range(sum+1)] for i in range(n)]
print(subsetSum(arr,sum,n-1,dp))
