def lcs_recursive(s1, s2, n, m, count):
    if n == 0 or m == 0:
        return count    
    if s1[n-1] == s2[m-1]:
        count = lcs_recursive(s1, s2, n-1, m-1, count + 1) #we are not doing like count+=somethingh we are doing replace value of count        
    count = max(count, max(lcs_recursive(s1, s2, n, m-1, 0), lcs_recursive(s1, s2, n-1, m, 0)))    
    return count
s1 = "ABCDGH"
s2 = "ACDPHRD" 
print(lcs_recursive(s1, s2, len(s1), len(s2), 0))



# def lcs(s1,s2,n,m):
#     ans=0
#     dp=[[0 for i in range(m+1)] for j in range(n+1)]
#     for i in range(1,n+1):
#         for j in range(1,m+1):
#             if s1[i-1]==s2[j-1]:
#                 dp[i][j]=1+dp[i-1][j-1]                 
#                 ans=max(ans,dp[i][j])
#             else:dp[i][j]=0    
#     return ans 
# s1 = "ABCDGH"
# s2 = "ACDGHR"
# n = 6
# m = 6           
# print(lcs(s1,s2,n,m))

# Space optimization 

# def lcs(s1,s2,n,m):
#     ans=0
#     prev=[0]*(m+1)
#     for i in range(1,n+1):
#         curr=[0]*(m+1)
#         for j in range(1,m+1):
#             if s1[i-1]==s2[j-1]:
#                 curr[j]=1+prev[j-1]
#                 ans=max(ans,curr[j])
#             else:curr[j]=0
#         prev=curr    
#     return ans 
# s1 = "ABCDGH"
# s2 = "ACDGHR"
# n = 6
# m = 6           
# print(lcs(s1,s2,n,m))


# def lcs_helper(s1,s2,i1,i2,memo):
#     if i1<0 or i2<0:
#         return 0
#     if memo[i1][i2]!=-1:
#         return memo[i1][i2]
#     if s1[i1]==s2[i2]:
#         memo[i1][i2]=1+lcs_helper(s1,s2,i1-1,i2-1,memo)
#     else:
#         lcs_helper(s1, s2, i1 - 1, i2, memo)
#         lcs_helper(s1, s2, i1, i2 - 1, memo)
#         memo[i1][i2]=0
#     return memo[i1][i2]
# def lcs(s1,s2,n,m):
#     memo=[[-1 for i in range(m)] for i in range(n)]
#     lcs_helper(s1,s2,n-1,m-1,memo)
#     ans=0
#     for i in range(n):
#         for j in range(m):
#             if memo[i][j]!=-1:
#                 ans=max(ans,memo[i][j])
#     return ans        
# s1 = "ABCDGH"
# s2 = "ACDGHR"
# n = 6
# m = 6    
# print(lcs(s1,s2,n,m))    
        

# # Very Important information ----> if we want to send an variable as reference then there is a 
# # way to send it through implementing it with list like we did in following code with ans[0] instead writing of ans
   

# def lcs_helper(s1, s2, i1, i2, memo, ans):
#     if i1 < 0 or i2 < 0:
#         return 0
#     if memo[i1][i2] != -1:
#         return memo[i1][i2]

#     if s1[i1] == s2[i2]:
#         memo[i1][i2] = 1 + lcs_helper(s1, s2, i1 - 1, i2 - 1, memo, ans)
#         ans[0] = max(ans[0], memo[i1][i2])
#     else:
#         memo[i1][i2] = 0
#         lcs_helper(s1, s2, i1 - 1, i2, memo, ans)
#         lcs_helper(s1, s2, i1, i2 - 1, memo, ans)

#     return memo[i1][i2]

# def lcs(s1, s2,n,m):
#     memo = [[-1 for _ in range(m)] for _ in range(n)]
#     ans = [0]
#     for i in range(n):
#         for j in range(m):
#             lcs_helper(s1, s2, i, j, memo, ans)
#     return ans[0]
     
# s1 = "KXCGMTMVVGFQQWSPD"
# s2 = "JXZADDUKVLQPKUZJZHWSUTPCAFSYAIBJHAMMEGWBTPQELRNKBLDXGUZGCSEC"
# n = 17
# m = 60   
# print(lcs(s1,s2,n,m))    
        
# # The following code cann't give the correct answer because lcs_helper doesn't give corrected dp table for each i and j it throws 
# # correct answer only for that who is final i and j like n-1 and m-1 so here's why we need to know corrected answer for each so that's
# # why we run the lcs_helper function n*m times
  

# def lcs_helper(s1, s2, i1, i2, memo, ans):
#     if i1 < 0 or i2 < 0:
#         return 0
#     if memo[i1][i2] != -1:
#         return memo[i1][i2]
    
#     if s1[i1] == s2[i2]:
#         memo[i1][i2] = 1 + lcs_helper(s1, s2, i1 - 1, i2 - 1, memo, ans)
#         ans[0] = max(ans[0], memo[i1][i2])
#     else:
#         lcs_helper(s1, s2, i1 - 1, i2, memo, ans)
#         lcs_helper(s1, s2, i1, i2 - 1, memo, ans)
#         memo[i1][i2] = 0  # This should be 0 because it's for substring, not subsequence
    
#     return memo[i1][i2]

# def lcs(s1, s2):
#     n = len(s1)
#     m = len(s2)
#     memo = [[-1 for _ in range(m)] for _ in range(n)]
#     ans = [0]
#     lcs_helper(s1, s2, n - 1, m - 1, memo, ans)
#     return ans[0]

# s1 = "KXCGMTMVVGFQQWSPD"
# s2 = "JXZADDUKVLQPKUZJZHWSUTPCAFSYAIBJHAMMEGWBTPQELRNKBLDXGUZGCSEC"
# print(lcs(s1, s2)) #Output should be 2 but coming 1 

