# def stealThing(val,wt,weight,index):
#     if index==0:
#         if weight>=wt[0]:return (weight//wt[0])*val[0]
#         else:return 0
#     if weight==0: 
#         return 0    
#     notTake=stealThing(val,wt,weight,index-1)
#     take=-int(1e9)
#     if weight>=wt[index]:
#         take=val[index] + stealThing(val,wt,weight-wt[index],index)
#     return max(take,notTake)        
# n = 4
# w = 8
# val = [6, 1, 7, 7]
# wt = [1, 3, 4, 5]
# print(stealThing(val,wt,w,n-1))

# Optimization of time complexity using dp memoizatio approach 


def stealThing(val,wt,weight,index,dp):
    if index==0:
        if weight>=wt[0]:return (weight//wt[0])*val[0]
        else:return 0
    if weight==0:
        return 0 
    if dp[index][weight]!=-int(1e9):return dp[index][weight]   
    notTake=stealThing(val,wt,weight,index-1,dp)
    take=-int(1e9)
    if weight>=wt[index]:
        take=val[index] + stealThing(val,wt,weight-wt[index],index,dp)
    dp[index][weight]=max(take,notTake)        
    return dp[index][weight]
n = 4
w = 8
val = [6, 1, 7, 7]
wt = [1, 3, 4, 5]
dp=[[-int(1e9) for _ in range(w+1)] for _ in range(n)]
print(stealThing(val,wt,w,n-1,dp))

#  Further more Optimization using Tabulation

def stealThing3(val,wt,w,n):
    dp=[[-int(1e9) for _ in range(w+1)] for _ in range(n)]
    for i in range(w+1):
        if i>=wt[0]:
            dp[0][i]=(i//wt[0])*val[0]
        else:dp[0][i]=0
    for i in range(n):
        dp[i][0]=0
    for i in range(1,n):
        for j in range(1,w+1):
            notTake=dp[i-1][j]
            take=-int(1e9)
            if j>=wt[i]:
                take=val[i]+dp[i][j-wt[i]]
            dp[i][j]=max(take,notTake)
    return dp[n-1][w]             
n = 4
w = 8
val = [6, 1, 7, 7]
wt = [1, 3, 4, 5]
print(stealThing3(val,wt,w,n))

# Further more Optimization 

def stealThing3(val,wt,w,n):
    prev=[-int(1e9) for _ in range(w+1)] 
    for i in range(w+1):
        if i>=wt[0]:
            prev[i]=(i//wt[0])*val[0]
        else:prev[i]=0
    for i in range(1,n):
        curr=[-int(1e9) for _ in range(w+1)] 
        curr[0]=0
        for j in range(1,w+1):
            notTake=prev[j]
            take=-int(1e9)
            if j>=wt[i]:
                take=val[i]+curr[j-wt[i]]
            curr[j]=max(take,notTake)
        prev=curr    
    return prev[w]             
n = 4
w = 8
val = [6, 1, 7, 7]
wt = [1, 3, 4, 5]
print(stealThing3(val,wt,w,n))
