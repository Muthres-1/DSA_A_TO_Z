# def coinChange(coins,amount,index):
#     if index==0:
#         if amount%coins[index]==0:
#             return 1
#         else:return 0
#     if amount==0:return 1
#     notTake=coinChange(coins,amount,index-1)    
#     take=0
#     if amount>=coins[index]:
#         take=coinChange(coins,amount-coins[index],index)
#     return notTake+take
# amount = 5
# coins = [1,2,5]    
# print(coinChange(coins,amount,len(coins)-1))    

# Time complexity Optimization using dp memoization 

def coinChange(coins,amount,index,dp):
    if index==0:
        if amount%coins[index]==0:
            return 1
        else:return 0
    if amount==0:return 1
    if dp[index][amount]!=-1:return dp[index][amount]
    notTake=coinChange(coins,amount,index-1,dp)    
    take=0
    if amount>=coins[index]:
        take=coinChange(coins,amount-coins[index],index,dp)
    dp[index][amount]=notTake+take
    return dp[index][amount]
amount = 5
coins = [1,2,5]    
n=len(coins)
dp=[[-1 for _ in range(amount+1)] for _ in range(n)]
print(coinChange(coins,amount,n-1,dp))    
    
# further more Optimization using tabulation method 

def coinChange2(coins,amount):
    n=len(coins)
    dp=[[0 for _ in range(amount+1)] for _ in range(n)]
    for i in range(amount+1):
        if i>=coins[0] and i%coins[0]==0:
            dp[0][i]=1
    for i in range(n):
        dp[i][0]=1
    for i in range(1,n):
        for j in range(amount+1):
            notTake=dp[i-1][j]
            take=0
            if j>=coins[i]:
                take=dp[i][j-coins[i]]
            dp[i][j]=take+notTake
    return dp[n-1][amount]
print(coinChange2(coins,amount))   

# further more Optimization 

def coinChange3(coins,amount):
    n=len(coins)
    prev=[0 for _ in range(amount+1)] 
    prev[0]=1   
    for i in range(amount+1):
        if i>=coins[0] and i%coins[0]==0:
            prev[i]=1   
    for i in range(1,n):
        curr=[0 for _ in range(amount+1)]
        curr[0]=1
        for j in range(1,amount+1):
            notTake=prev[j]
            take=0
            if j>=coins[i]:
                take=curr[j-coins[i]]
            curr[j]=take+notTake
        prev=curr    
    return prev[amount]
print(coinChange3(coins,amount)) 
                     