# def getCoin(nums,start,end):
#     if start>end:
#         return 0
#     maxi=-int(1e9)
#     for j in range(start,end+1):
#         left=1
#         right=1
#         if start>0:
#             left=nums[start-1]
#         if end<len(nums)-1:
#             right=nums[end+1] 
#         cost=left*nums[j]*right+ getCoin(nums,start,j-1) + getCoin(nums,j+1,end)
#         maxi=max(maxi,cost)
#     return maxi   
# nums = [3,1,5,8]
# print(getCoin(nums,0,len(nums)-1))

# Optimization using memoization

def getCoin(nums,start,end,dp,n):
    if start>end:
        return 0
    if dp[start][end]!=-1:return dp[start][end]
    maxi=-int(1e9)
    for j in range(start,end+1):
        left=1
        right=1
        if start>0:
            left=nums[start-1]
        if end<n-1:
            right=nums[end+1] 
        cost=left*nums[j]*right+ getCoin(nums,start,j-1,dp,n) + getCoin(nums,j+1,end,dp,n)
        maxi=max(maxi,cost)
    dp[start][end]=maxi    
    return maxi   
nums = [3,1,5,8]
n=len(nums)
dp=[[-1 for i in range(n)] for i in range(n)]
print(getCoin(nums,0,n-1,dp,n))

# Optimization using Tabulation 

def getCoin(nums):
    n=len(nums)
    dp=[[0 for i in range(n+1)] for i in range(n+1)]
    for length in range(1,n+1):
        for start in range(n-length+1):
            end=start+length-1
            maxi=-int(1e9)
            for j in range(start,end+1):
                left=1
                right=1
                if start>0:
                    left=nums[start-1]
                if end<n-1:
                    right=nums[end+1] 
                cost=left*nums[j]*right+ dp[start][j-1] + dp[j+1][end]
                maxi=max(maxi,cost)
            dp[start][end]=maxi 
    return dp[0][n-1]              
nums = [3,1,5,8]
print(getCoin(nums))

# This can be done by this method add two one at starting and ending and after calling 


def maxCoins(a):
    n = len(a)
    a.insert(0, 1)
    a.append(1)
    def f(i, j):
        if i > j:
            return 0
        maxi = float('-inf')
        for ind in range(i, j + 1):
            cost = a[i - 1] * a[ind] * a[j + 1] + f(i, ind - 1) + f(ind + 1, j)
            maxi = max(maxi, cost)
        return maxi
    return f(1, n)
a = [3, 1, 5, 8]
ans = maxCoins(a)
print(ans)


