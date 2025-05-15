def minMulplication(arr,start,end):
    if start>=end:
        return 0
    mini=int(1e9)
    for i in range(start,end):
        x=minMulplication(arr,start,i) + minMulplication(arr,i+1,end) + arr[start-1]*arr[i]*arr[end]
        mini=min(mini,x)
    return mini   
n = 5
arr = [40, 20, 30, 10, 30]
print(minMulplication(arr,1,4))

# Optimization using dp memoization 

def minMulplication(arr,start,end,dp):
    if start==end:
        return 0
    if dp[start][end]!=1e9:return dp[start][end]
    mini=int(1e9)
    for i in range(start,end):
        x=minMulplication(arr,start,i,dp) + minMulplication(arr,i+1,end,dp) + arr[start-1]*arr[i]*arr[end]
        dp[start][end]=min(dp[start][end],x)
    return dp[start][end]   
n=5
arr=[40, 20, 30, 10, 30]
dp=[[int(1e9) for i in range(n)] for i in range(n)]
print(minMulplication(arr,1,n-1,dp))


# Optimization using Tabulation 

def minMultiplicationTabu(arr,n):
    dp=[[0 for i in range(n)] for j in range(n)]
    for length in range(2,n):
        for i in range(1,n-length+1):
            j=i+length-1
            mini=int(1e9)
            for k in range(i,j):#spliting point
                x=arr[i-1]*arr[k]*arr[j]+dp[i][k]+dp[k+1][j]
                mini=min(mini,x)
            dp[i][j]=mini    
    return dp[1][n-1]        
n = 5
arr = [40, 20, 30, 10, 30]
print(minMultiplicationTabu(arr,n))            

