#In this problem we can buy and sell pair of transaction may be infinite times no any constraints
# def bestTime(prices,index,buy):
#     if index==len(prices):
#         return 0
#     if buy:
#         profit=max(-prices[index] + bestTime(prices,index+1,0),bestTime(prices,index+1,1))
#     else:
#         profit=max(prices[index] + bestTime(prices,index+1,1),bestTime(prices,index+1,0))
#     return profit
# prices = [7,1,5,3,6,4]
# print(bestTime(prices,0,1))     


#Optimization using dp 


# def bestTime(prices,index,buy,dp):
#     if index==len(prices):
#         return 0
#     if dp[index][buy]!=-1:return dp[index][buy]
#     if buy:
#         profit=max(-prices[index] + bestTime(prices,index+1,0,dp),bestTime(prices,index+1,1,dp))
#     else:
#         profit=max(prices[index] + bestTime(prices,index+1,1,dp),bestTime(prices,index+1,0,dp))
#     dp[index][buy]=profit    
#     return profit
# prices = [7,1,5,3,6,4]
# dp = [[-1 for _ in range(2)] for _ in range(len(prices))]
# print(bestTime(prices,0,1,dp))     

# Optimization using Tabulation 

def bestTime(prices):
    n=len(prices)
    dp = [[0 for _ in range(2)] for _ in range(n+1)]
    for ind in range(n - 1, -1, -1):
        for buy in range(2):
            profit = 0            
            if buy == 1:
                profit = max(0 + dp[ind + 1][1], prices[ind] + dp[ind + 1][0])
            else:
                profit = max(0 + dp[ind + 1][0], -prices[ind] + dp[ind + 1][1])           
            dp[ind][buy] = profit  
    return dp[0][0]       
prices = [7,1,5,3,6,4]
print(bestTime(prices))        
    