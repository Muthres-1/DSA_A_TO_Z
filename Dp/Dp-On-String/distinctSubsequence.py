# def distinctSubsequence(s1,s2,ind1,ind2):
#     # important thing---> if we write "ind1<0" condition first than "ind2<0" condition then 
#     # it will throw error because if both are negative then the return value will be 0 
#     # which is wrong it should be 1 that's why we write "ind2<0" condition first
#     if ind2<0:
#         return 1 #if s2 is empty then empty subset of s1 is the answer
#     if ind1<0: 
#         return 0     
#     if s1[ind1]==s2[ind2]: 
#         return distinctSubsequence(s1,s2,ind1-1,ind2-1) + distinctSubsequence(s1,s2,ind1-1,ind2)
#     else: 
#         return distinctSubsequence(s1,s2,ind1-1,ind2)
# s1 = "ffff" 
# s2 = "fff"     
# a=len(s1)
# b=len(s2)
# print(distinctSubsequence(s1,s2,a-1,b-1))

# Optimization of time complexity
 
# def distinctSubsequence(s1,s2,ind1,ind2,dp):
#     if ind2<0:
#         return 1
#     if ind1<0:
#         return 0    
#     if dp[ind1][ind2]!=-1:return dp[ind1][ind2]
#     if s1[ind1]==s2[ind2]:
#         dp[ind1][ind2]=distinctSubsequence(s1,s2,ind1-1,ind2-1,dp) + distinctSubsequence(s1,s2,ind1-1,ind2,dp)
#         return dp[ind1][ind2]
#     else:
#         dp[ind1][ind2]= distinctSubsequence(s1,s2,ind1-1,ind2,dp)
#         return dp[ind1][ind2]
# s1 = "ffff"
# s2 = "fff"    
# a=len(s1)
# b=len(s2)
# dp=[[-1 for i in range(b)] for i in range(a)]
# print(distinctSubsequence(s1,s2,a-1,b-1,dp))   


# Tabulation method

# def distinctSubsequenceTabulation(s1,s2):
#     a=len(s1)
#     b=len(s2)
#     dp=[[0 for i in range(b+1)] for i in range(a+1)]
#     for i in range(a+1):
#         dp[i][0]=1
#     for i in range(1,a+1): #this should also start with 1 because this is also solved by base case ,if don't start with 
#         # 1 then there should comes a error in output 
#         for j in range(1,b+1):
#             if s1[i-1]==s2[j-1]:
#                 dp[i][j]=dp[i-1][j-1]+dp[i-1][j]
#             else:
#                 dp[i][j]=dp[i-1][j]
#     return dp[a][b]                    
# s1 = "ffff"
# s2 = "fff"  
# print(distinctSubsequenceTabulation(s1,s2))

# More Optimization 

def distinctSubsequenceTabulation(s1,s2):
    a=len(s1)
    b=len(s2)
    # prev=[0 for i in range(b+1)] if I use this instead of [0]*(b+1) then there comes an error into leetcode
    prev=[0]*(b+1)
    prev[0]=1
    for i in range(1,a+1):
        curr=[0]*(b+1)
        curr[0]=1
        for j in range(1,b+1):
            if s1[i-1]==s2[j-1]:
                curr[j]=prev[j-1]+prev[j]
            else:
                curr[j]=prev[j]
        prev=curr        
    return prev[b]                    
s1 = "babgbag"
s2 = "bag" 
print(distinctSubsequenceTabulation(s1,s2))



