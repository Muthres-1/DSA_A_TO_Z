# def targetSum(i,n,arr,target):
#     if i==n and target==0:
#         return 1
#     elif i==n and target!=0:return 0
#     if target==0:
#         return 1
#     return targetSum(i+1,n,arr,target-arr[i]) or targetSum(i+1,n,arr,target)
# arr = [3, -34, 4, 12, 5, 2]
# target =-34
# print(targetSum(0,len(arr),arr,target))

# time limit exceeded
# dp based solution 
def targetSum(n, arr, target, dp, offset):
    if target == 0:
        return 1  
    if n == 0:
        if arr[0] == target:
            return 1
        else:
            return 0    
    if dp[n][target + offset] != -1:
        return dp[n][target + offset]    
    not_taken = targetSum(n - 1, arr, target, dp, offset)
    taken = 0
    if target >= arr[n]:
        taken = targetSum(n - 1, arr, target - arr[n], dp, offset)    
    dp[n][target + offset] = not_taken + taken
    return dp[n][target + offset]

arr = [-10, 13, 16, -18, 8, -19, 12, 13]
target = -10
n = len(arr)
# Calculate the offset
offset = sum(abs(x) for x in arr)
# Initialize dp array with -1
dp = [[-1 for _ in range(2 * offset + 1)] for _ in range(n)]
print(targetSum(n - 1, arr, target, dp, offset))


