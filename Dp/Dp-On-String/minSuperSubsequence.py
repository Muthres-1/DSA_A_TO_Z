def lca(s1,s2,n1,n2,dp):
    for ind1 in range(1,n1+1):
        for ind2 in range(1,n2+1):
            if s1[ind1-1]==s2[ind2-1]:
                dp[ind1][ind2]=1+dp[ind1-1][ind2-1]
            else:
                dp[ind1][ind2]= max(dp[ind1-1][ind2],dp[ind1][ind2-1]) 
def minSuperSub(s1,s2):
    n1=len(s1)
    n2=len(s2)
    dp=[[0 for _ in range(n2+1)] for _ in range(n1+1)]
    lca(s1,s2,n1,n2,dp)
    ans=""
    while n1>0 and n2>0:
        if s1[n1-1]==s2[n2-1]:
            ans+=s1[n1-1]
            n1-=1
            n2-=1
        elif dp[n1-1][n2]>dp[n1][n2-1]:
            ans+=s1[n1-1]
            n1-=1
        else:
            ans+=s2[n2-1]
            n2-=1  
    while(n1>0):
            ans+=s1[n1-1]
            n1-=1
    while(n2>0):
            ans+=s2[n2-1]    
            n2-=1 
    return ans[::-1]
s1 = "abac"
s2 = "cab"           
print(minSuperSub(s1,s2))

