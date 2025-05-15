# def countSum(arr,target,n):
#     if n<0:
#         if target==0:return 1
#         else :return 0    
#     return countSum(arr,target,n-1) + countSum(arr,target-arr[n],n-1)
# n = 6
# arr = [0,2,3,-4,5,-1]
# target = -5
# print(countSum(arr,target,n-1)) 
# if we write a base condition like if target==0:return 1 not inside of condition n<0 then this
# code won't work for the array who also include zeros
# dp based solution 
# the following work also for zero but not for negative target and negative element like=-3,2,1 and target =0
# def countSumDp(arr,target,n,dp):
#     if n<0:
#         if target==0:return 1
#         else :return 0 
#     if target<0:return 0    
#     if dp[n][target]!=-1:
#         return dp[n][target]       
#     dp[n][target]= countSumDp(arr,target,n-1,dp) + countSumDp(arr,target-arr[n],n-1,dp)
#     return dp[n][target]
# n = 3
# arr = [0,0,1]
# target = 1
# print(countSumDp(arr,target,n-1,dp))

#  The following countPartitionUtilTab function won't work for zero value available in array 
# def countPartitionsUtilTab(n,target,arr):
#     dp = [[0 for j in range(target + 1)] for i in range(n)]
#     for i in range(n):
#         dp[i][0]=1
#     if arr[0]<=target:
#         dp[0][arr[0]]=1 # This tells that to make arr[0] total number of way in arr from ind 0 to 0 is one way but we will declare this as target>=arr[0] because if target 
#         # is greater than arr[0] because if target is less than then arr[0] will not use to gain  target ,its mean we are taking inside dp those are eligible to make target
#     for i in range(1,n):
#         for j in range(1,target+1,1):            
#             Taken=0
#             if arr[i]<=j: #taken
#                 Taken=dp[i-1][j-arr[i]] 
#             notTaken=dp[i-1][j]               
#             dp[i][j]=Taken+notTaken
#     return dp[n-1][target]        

# def countSubset(n,target,arr):
#     dp = [[0 for j in range(target + 1)] for i in range(n)]
#     if arr[0]<=target:
#         dp[0][arr[0]]=1 # This tells that to make arr[0] total number of way in arr from ind 0 to 0 is one way but we will declare this as target>=arr[0] because if target 
#         # is greater than arr[0] because if target is less than then arr[0] will not use to gain  target ,its mean we are taking inside dp those are eligible to make target
#     if arr[0]==0:
#         dp[0][0]=2 #take or not take zero index these are tow way 
#     else:
#         dp[0][0]=1
#     for i in range(1,n):
#         for j in range(target+1):
#             notTaken=dp[i-1][j]
#             Taken=0
#             if arr[i]<=j: #taken
#                 Taken=dp[i-1][j-arr[i]] 
#             dp[i][j]=(Taken+notTaken)
#     return dp[n-1][target]

# n=2
# arr=[0,0]
# target=1
# print(countSubset(n,target,arr))

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
        dp[0][arr[0]] = 1  # There is one way to form the subset {arr[0]}               
    for i in range(1,n):
        for j in range(target+1):
            notTaken=dp[i-1][j]
            Taken=0
            if arr[i]<=j: #taken
                Taken=dp[i-1][j-arr[i]] 
            dp[i][j]=(Taken+notTaken)
    return dp[n-1][target]
n=3
arr=[1,2,5]
target=5
print(countSubset(n,target,arr))

