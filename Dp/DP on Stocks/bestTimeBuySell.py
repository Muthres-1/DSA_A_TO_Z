#In this problem we can buy and sell pair of transaction may be at most one not more than one 

# def bestTime(prices,index):
#     if index==1:
#         if prices[0]<=prices[1]:
#             return prices[1]-prices[0]
#         else:return 0
#     if index==0:return 0    
#     ans=0    
#     for i in range(index):
#         ans=max(ans,prices[index]-prices[i])
#     ans=max(ans,bestTime(prices,index-1))
#     return ans
# prices = [1,2]  
# print(bestTime(prices,len(prices)-1))


# But there is also available best method 

def bestTime(prices):
    a=len(prices)
    if a==1:return 0
    mini=prices[0]
    preProfit=0
    for i in range(1,a):
        currProfit=prices[i]-mini
        preProfit=max(preProfit,currProfit)
        mini=min(mini,prices[i]) # mini is remembering the minimum in prices from 0th day to till now doing work as dp 
    return preProfit    
prices = [1,2]  
print(bestTime(prices))