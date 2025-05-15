# def minStepForPalindrome(s,ind1,ind2,count):
#     if ind1>ind2:return count
#     if s[ind1]==s[ind2]:
#         count=minStepForPalindrome(s,ind1+1,ind2-1,count)
#     else:count=min(minStepForPalindrome(s,ind1+1,ind2,count+1),minStepForPalindrome(s,ind1,ind2-1,count+1))
#     return count
# s ="zjveiiwvc"
# print(minStepForPalindrome(s,0,len(s)-1,0))

# Dp solution 

# def minStepForPalindrome(s,ind1,ind2,dp):
#     if ind1>ind2:return 0
#     if dp[ind1][ind2]!=-1:return dp[ind1][ind2]
#     if s[ind1]==s[ind2]:
#         dp[ind1][ind2]=minStepForPalindrome(s,ind1+1,ind2-1,dp)
#     else:dp[ind1][ind2]=1+min(minStepForPalindrome(s,ind1+1,ind2,dp),minStepForPalindrome(s,ind1,ind2-1,dp))
#     return dp[ind1][ind2]
# s ="zjveiiwvc"
# n=len(s)
# dp=[[-1 for i in range(n)] for j in range(n)]
# print(minStepForPalindrome(s,0,len(s)-1,dp))

# Optimization using Tabulation 
# n=5,a=3,b=2 and n=6,a=3,b=3

# Another method to solve this problem is 
#  no of Operations = lengthOfString(s)-lengthOfLongestPalindromeSubsequence(s)

