# def wildcardMatching(s1,s2,ind1,ind2):
#     if ind1<0 and ind2<0:
#         return True
#     elif ind1<0 and ind2>=0:
#         return False
#     elif ind2<0 and ind1>=0:
#         for i in range(ind1+1):
#             if s1[i]!="*":
#                 return False
#         return True
#     if s1[ind1]==s2[ind2] or s1[ind1]=="?":
#         return wildcardMatching(s1,s2,ind1-1,ind2-1)
#     if s1[ind1]=="*":
#         return wildcardMatching(s1,s2,ind1-1,ind2) or wildcardMatching(s1,s2,ind1,ind2-1)
#     return False
# p = "*a*b"  
# s = "adceb"
# print(wildcardMatching(p,s,len(p)-1,len(s)-1))

#Optimization using dp

def wildcardMatching(s1,s2,ind1,ind2,dp):
    if ind1<0 and ind2<0:
        return True
    elif ind1<0 and ind2>=0:
        return False
    elif ind2<0 and ind1>=0:
        for i in range(ind1+1):
            if s1[i]!="*":
                return False
        return True
    if dp[ind1][ind2]!=-1:return dp[ind1][ind2]
    if s1[ind1]==s2[ind2] or s1[ind1]=="?":
        dp[ind1][ind2]=wildcardMatching(s1,s2,ind1-1,ind2-1,dp)
        return dp[ind1][ind2]
    if s1[ind1]=="*":
        dp[ind1][ind2]=wildcardMatching(s1,s2,ind1-1,ind2,dp) or wildcardMatching(s1,s2,ind1,ind2-1,dp)
        return dp[ind1][ind2]
    return False
p = "*a*b"  
s = "adceb"
a=len(p)
b=len(s)
dp=[[-1 for i in range(b)] for i in range(a)]
print(wildcardMatching(p,s,len(p)-1,len(s)-1,dp))


# Optimization using Tabulation 

def wildcardMatchingTabu2(p,s):
    a=len(p)
    b=len(s)
    dp=[[False for i in range(b+1)] for i in range(a+1)]
    dp[0][0]=True
    for i in range(1, a + 1):
        if p[i - 1] == '*':
            dp[i][0] = dp[i - 1][0]
        else:
            break
    for ind1 in range(1,a+1):
        for ind2 in range(1,b+1):
            if p[ind1-1]==s[ind2-1] or p[ind1-1]=="?":
                dp[ind1][ind2]=dp[ind1-1][ind2-1]
            elif p[ind1-1]=="*":
                dp[ind1][ind2]=dp[ind1-1][ind2] or dp[ind1][ind2-1]
            else:dp[ind1][ind2]=False
    return dp[a][b]             
p = "*a*b"  
s = "adceb"
print(wildcardMatchingTabu2(p,s))   

# further more Optimization 

def wildcardMatchingTabu2(p,s):
    a=len(p)
    b=len(s)
    prev=[False]*(b+1)
    curr=[False]*(b+1)
    prev[0]=True    
    for ind1 in range(1,a+1):
        curr[0] = prev[0] if p[ind1 - 1] == '*' else False
        for ind2 in range(1,b+1):
            if p[ind1-1]==s[ind2-1] or p[ind1-1]=="?":
                curr[ind2]=prev[ind2-1]
            elif p[ind1-1]=="*":
                curr[ind2]=prev[ind2] or curr[ind2-1]
            else:curr[ind2]=False
        prev, curr = curr, [False] * (b + 1)   
    return prev[b]             
p = "*a*b"  
s = "adceb"
print(wildcardMatchingTabu2(p,s))       


        
            

    