# here the difference between price[i]and price[i+1] may not constant if this can be solve using greedy

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
n = 1
w = 1
val = [2]
wt = [1]
print(stealThing3(val,wt,w,n))

# Another method

def f(index,n,price):
    if index==0:
        return n*price[0]
    notTake=0+f(index-1,n,price)
    take=-int(1e9)
    rodlength=index+1
    if rodlength<=n:
        take=price[index]+f(index,n-rodlength,price)
    return max(take,notTake)
N = 8
Price = [1, 5, 8, 9, 10, 17, 17, 20]  
print(f(N-1,N,Price))
# in above recursion index shows that this length(index+1) should we take or not for making n length
# Optimization

def f2(index,n,price,dp):
    if index==0:
        return n*price[0]
    if dp[index][n]!=-int(1e9):return dp[index][n]
    notTake=0+f2(index-1,n,price,dp)
    take=-int(1e9)
    rodlength=index+1
    if rodlength<=n:
        take=price[index]+f2(index,n-rodlength,price,dp)
    dp[index][n]=max(take,notTake)
    return dp[index][n]
n = 8
price = [1, 5, 8, 9, 10, 17, 17, 20] 
dp=[[-int(1e9) for _ in range(n+1)]for _ in range(n)]
print(f2(n-1,n,Price,dp))

# Tabulation  

def f2(n,price):
    dp=[[-int(1e9) for _ in range(n+1)]for _ in range(n)]
    for i in range(n+1):
        dp[0][i]=i*price[0]
    for i in range(1,n):
        for j in range(n+1):
            notTake=dp[i-1][j]
            take=-int(1e9)
            rodLength=i+1
            if rodLength<=j:
                take=price[i]+dp[i][j-rodLength]
            dp[i][j]=max(take,notTake)
    return dp[n-1][n]                
   
n = 8
price = [1, 5, 8, 9, 10, 17, 17, 20]
print(f2(n,Price))

# further more Optimization 

def f2(n,price):
    prev=[0 for _ in range(n+1)]
    for i in range(n+1):
        prev[i]=i*price[0]
    for i in range(n):   
        curr=[0 for _ in range(n+1)]     
        for j in range(1,n+1):
            notTake=prev[j]
            take=-int(1e9)
            rodLength=i+1
            if rodLength<=j:
                take=price[i]+curr[j-rodLength]
            curr[j]=max(take,notTake)
        prev=curr    
    return prev[n]                
   
n = 8
price = [1, 5, 8, 9, 10, 17, 17, 20]
print(f2(n,Price))


def f2(n,price):
    curr=[0 for _ in range(n+1)]
    for i in range(n+1):
        curr[i]=i*price[0]
    for i in range(n):       
        for j in range(1,n+1):
            notTake=curr[j]
            take=-int(1e9)
            rodLength=i+1
            if rodLength<=j:
                take=price[i]+curr[j-rodLength]
            curr[j]=max(take,notTake)
            
    return curr[n]                
   
n = 8
price = [1, 5, 8, 9, 10, 17, 17, 20]
print(f2(n,Price))





