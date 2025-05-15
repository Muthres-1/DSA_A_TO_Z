# def editDistance(s1,s2,ind1,ind2):
#     if ind1<0:
#         return ind2+1
#     if ind2<0:
#         return ind1+1
#     if s1[ind1]==s2[ind2]:
#         return editDistance(s1,s2,ind1-1,ind2-1)
#     else:
#         return 1+min(editDistance(s1,s2,ind1-1,ind2-1),editDistance(s1,s2,ind1-1,ind2),editDistance(s1,s2,ind1,ind2-1))
# s1 = "horse"
# s2 = "ros"
# print(editDistance(s1,s2,len(s1)-1,len(s2)-1))

# Optimization using dp memoization 

def editDistance(s1,s2,ind1,ind2,dp):
    if ind1<0:
        return ind2+1
    if ind2<0:
        return ind1+1
    if dp[ind1][ind2]!=-1:return dp[ind1][ind2]
    if s1[ind1]==s2[ind2]:
        dp[ind1][ind2]=editDistance(s1,s2,ind1-1,ind2-1,dp)
        return dp[ind1][ind2]
    else:
        dp[ind1][ind2]=1+min(editDistance(s1,s2,ind1-1,ind2-1,dp),editDistance(s1,s2,ind1-1,ind2,dp),editDistance(s1,s2,ind1,ind2-1,dp))
        return dp[ind1][ind2]
s1 = "horse"
s2 = "ros"
a=len(s1)
b=len(s2)
dp=[[-1 for i in range(b)] for j in range(a)]
print(editDistance(s1,s2,a-1,b-1,dp))

# Optimization using Tabulation 
# def editDistanceTabu(s1,s2):
#     a=len(s1)
#     b=len(s2)
#     dp=[[0 for i in range(b+1)] for j in range(a+1)]
#     for i in range(b+1):
#         dp[0][i]=i #here will not added extra +1 because now we are using base 1 indexing
#     for j in range(a+1):
#         dp[j][0]=j
#     for i in range(1,a+1):
#         for j in range(1,b+1):
#             if s1[i-1]==s2[j-1]:
#                 dp[i][j]=dp[i-1][j-1]
#             else:
#                 dp[i][j]=1+min(dp[i-1][j-1],dp[i-1][j],dp[i][j-1])
#     return dp[a][b]                        
# s1 = "horse"
# s2 = "ros"
# print(editDistanceTabu(s1,s2))

# Optimization 

def editDistanceTabu(s1,s2):
    a=len(s1)
    b=len(s2)
    prev=[i for i in range(b+1)] 
    # for i in range(b+1):
    #     prev[i]=i #here will not added extra +1 because now we are using base 1 indexing
    # for j in range(a+1):
    #     dp[j][0]=j
    for i in range(1,a+1):
        curr=[0 for i in range(b+1)] 
        curr[0]=i
        for j in range(1,b+1):
            if s1[i-1]==s2[j-1]:
                curr[j]=prev[j-1]
            else:
                curr[j]=1+min(prev[j-1],prev[j],curr[j-1])
        prev=curr        
    return prev[b]                        
s1 = "horse"
s2 = "ros"
print(editDistanceTabu(s1,s2))

# When you write prev = cur, prev and cur will point to the same list. 
# Any changes made to cur in subsequent iterations will also affect prev,
#  which is not the intended behavior for dynamic programming,
#  where each row should be calculated independently based on the previous row.

# Using prev, cur = cur, prev
# This line correctly swaps the lists. After the swap, 
# prev points to the current row (which has been fully computed), 
# and cur is reset and ready for the next row computation. 
# This ensures that prev and cur are distinct and that cur can be 
# safely reused in the next iteration.


# so that's why if write in leetcode as prev=curr then there comes error but I am unable to get 
# that why in Vscode there doesn't shows any error?
