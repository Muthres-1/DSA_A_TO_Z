#In this problem we can buy and sell pair of transaction may be at most k times
# def bestTime(prices,index,buy,k):
#     if index==len(prices) or k==0:
#         return 0
#     if buy:
#         profit=max(-prices[index] + bestTime(prices,index+1,0,k),bestTime(prices,index+1,1,k))
#     else: 
#         profit=max(prices[index] + bestTime(prices,index+1,1,k-1),bestTime(prices,index+1,0,k))
#     return profit
# k = 2
# prices = [3,2,6,5,0,3]
# print(bestTime(prices,0,1,k)) 


# Optimization using dp

# def bestTime(prices,index,buy,k,dp):
#     if index==len(prices) or k==0:
#         return 0
#     if dp[index][buy][k]!=-1:return dp[index][buy][k]
#     if buy:
#         profit=max(-prices[index] + bestTime(prices,index+1,0,k,dp),bestTime(prices,index+1,1,k,dp))
#     else:
#         profit=max(prices[index] + bestTime(prices,index+1,1,k-1,dp),bestTime(prices,index+1,0,k,dp))
#     dp[index][buy][k]=profit    
#     return profit
# k = 2
# prices = [3,2,6,5,0,3]
# n=len(prices)
# dp=[[[-1  for i in range(k+1)] for i in range(2)]for i in range(n)]  # index 0 and 1 up to index 1 when we write range(2)
# print(bestTime(prices,0,1,k,dp)) 

# Optimization using Tabulation 

def bestTime(prices,k):
    n=len(prices)
    dp=[[[0  for i in range(k+1)] for i in range(2)]for i in range(n+1)] 
    for index in range(n-1,-1,-1):
        for buy in range(2):
            for i in range(1,k+1):
                profit = 0  
                if buy == 1:
                    profit = max(0 + dp[index + 1][buy][i], -prices[index] + dp[index + 1][0][i])
                else:
                    profit = max(0 + dp[index + 1][buy][i], prices[index] + dp[index + 1][1][i-1])          
                dp[index][buy][i] = profit
    return dp[0][1][k]      
k = 2
prices = [3,3,5,0,0,3,1,4]
print(bestTime(prices,k)) 
