# def bestTime(prices,index,buy):
#     if index>=len(prices):
#         return 0
#     if buy:
#         profit=max(-prices[index] + bestTime(prices,index+1,0),bestTime(prices,index+1,1))
#     else:
#         profit=max(prices[index] + bestTime(prices,index+2,1),bestTime(prices,index+1,0))
#     return profit 
# prices = [1,2,3,0,2]
# print(bestTime(prices,0,1))

# Optimization using dp


def bestTime(prices,index,buy,dp):
    if index>=len(prices):
        return 0
    if dp[index][buy]!=-1:return dp[index][buy]
    if buy:
        profit=max(-prices[index] + bestTime(prices,index+1,0,dp),bestTime(prices,index+1,1,dp))
    else:
        profit=max(prices[index] + bestTime(prices,index+2,1,dp),bestTime(prices,index+1,0,dp))
    dp[index][buy]=profit    
    return profit
prices = [1,2,4]
dp = [[-1 for _ in range(2)] for _ in range(len(prices))]
print(bestTime(prices,0,1,dp))    
