def lca(s1,s2,ind1,ind2):  
    if ind1<0 or ind2<0 :
        return 0
    if s1[ind1]==s2[ind2]:
        return 1+lca(s1,s2,ind1-1,ind2-1)
    else:
        return max(lca(s1,s2,ind1-1,ind2),lca(s1,s2,ind1,ind2-1))
s1="abc"
s2="def" 
print(lca(s1,s2,len(s1)-1,len(s2)-1))

# Optimization using dp memoization 

def lca(s1,s2,ind1,ind2,dp): 
    if ind1<0 or ind2<0:
        return 0
    if s1[ind1]==s2[ind2]:
        dp[ind1][ind2]=1+lca(s1,s2,ind1-1,ind2-1,dp)
    else:
        dp[ind1][ind2]= max(lca(s1,s2,ind1-1,ind2,dp),lca(s1,s2,ind1,ind2-1,dp))
    return dp[ind1][ind2]    
s1="abc"
s2="def"
dp=[[-1 for _ in range(len(s2))] for _ in range(len(s1))]
print(lca(s1,s2,len(s1)-1,len(s2)-1,dp))  

# Optimization using Tabulation Bottom up approach

# def lca(s1,s2):
#     n1=len(s1)
#     n2=len(s2)
#     dp=[[0 for _ in range(n2)] for _ in range(n1)]
#     for ind1 in range(n1):
#         for ind2 in range(n2):
#             if s1[ind1]==s2[ind2]:
#                 dp[ind1][ind2]=1+dp[ind1-1][ind2-1]
#             else:
#                 dp[ind1][ind2]= max(dp[ind1-1][ind2],dp[ind1][ind2-1])
#     return dp[n1-1][n2-1]            

# s1="oxcpqrsvwf"
# s2="shmtulqrypy"
# print(lca(s1,s2)) 

# the above tabulation bottom -up gives wrong answer because we didn't write the base case for so to do that we need to 
# shift indices so that's why we take dp array of size n,m and in previous we took n-1,m-1 

# def lca(s1,s2):
#     n1=len(s1)
#     n2=len(s2)
#     dp=[[0 for _ in range(n2+1)] for _ in range(n1+1)]
#     for ind1 in range(1,n1+1):
#         for ind2 in range(1,n2+1):
#             if s1[ind1-1]==s2[ind2-1]:
#                 dp[ind1][ind2]=1+dp[ind1-1][ind2-1]
#             else:
#                 dp[ind1][ind2]= max(dp[ind1-1][ind2],dp[ind1][ind2-1])
#     return dp[n1][n2]     

# s1="oxcpqrsvwf"
# s2="shmtulqrypy"
# print(lca(s1,s2)) 

# further space Optimization 

def lca(s1,s2):
    n1=len(s1)
    n2=len(s2)
    prev=[0 for _ in range(n2+1)]
    for ind1 in range(1,n1+1):
        curr= [0 for _ in range(n2+1)] 
        for ind2 in range(1,n2+1):
            if s1[ind1-1]==s2[ind2-1]:
                curr[ind2]=1+prev[ind2-1]
            else:
                curr[ind2]= max(prev[ind2],curr[ind2-1])
        prev=curr        
    return prev[n2]       

s1="oxcpqrsvwf"
s2="shmtulqrypy"
print(lca(s1,s2)) 




    
