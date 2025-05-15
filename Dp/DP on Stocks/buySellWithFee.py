# def bestTime(prices,index,buy,fee):
#     if index==len(prices):
#         return 0
#     if buy:
#         profit=max(-prices[index] + bestTime(prices,index+1,0,fee),bestTime(prices,index+1,1,fee))
#     else:
#         profit=max(prices[index]-fee + bestTime(prices,index+1,1,fee),bestTime(prices,index+1,0,fee))
#     return profit
# prices = [1,3,2,8,4,9]
# fee = 2
# print(bestTime(prices,0,1,fee)) 
 
# Optimization

def bestTime(prices,index,buy,dp,fee):
    if index==len(prices):
        return 0
    if dp[index][buy]!=-1:return dp[index][buy]
    if buy:
        profit=max(-prices[index] + bestTime(prices,index+1,0,dp,fee),bestTime(prices,index+1,1,dp,fee))
    else:
        profit=max(prices[index] -fee + bestTime(prices,index+1,1,dp,fee),bestTime(prices,index+1,0,dp,fee))
    dp[index][buy]=profit    
    return profit
prices = [1,3,2,8,4,9]
fee = 2
dp = [[-1 for _ in range(2)] for _ in range(len(prices))]
print(bestTime(prices,0,1,dp,fee))