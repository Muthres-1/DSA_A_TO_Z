# def lcs(s1,s2,ind1,ind2,str):
#     if ind1>=len(s1) or ind2>=len(s2):
#         return str
#     if s1[ind1]==s2[ind2]:
#         c=lcs(s1,s2,ind1+1,ind2+1,str+s1[ind1])
#     else:
#         a=lcs(s1,s2,ind1+1,ind2,str)
#         b=lcs(s1,s2,ind1,ind2+1,str)
#         if len(a)>len(b): 
#             return a
#         else:return b   
#     return c 
# s1="abaaa"
# s2="baabaca"
# print(lcs(s1,s2,0,0,""))       
def lcs(s1, s2):
    n = len(s1)
    m = len(s2)    
    dp = [[0 for j in range(m + 1)] for i in range(n + 1)]
    # we commented follow four line becauase we already set to zero
    # for i in range(n + 1):
    #     dp[i][0] = 0
    # for i in range(m + 1):
    #     dp[0][i] = 0
    for ind1 in range(1, n + 1):
        for ind2 in range(1, m + 1):
            if s1[ind1 - 1] == s2[ind2 - 1]:
                dp[ind1][ind2] = 1 + dp[ind1 - 1][ind2 - 1]
            else:
                dp[ind1][ind2] = 0+max(dp[ind1 - 1][ind2], dp[ind1][ind2 - 1])    
    i = n
    j = m
    str_ = ""    
    while i > 0 and j > 0:
        if s1[i - 1] == s2[j - 1]:
            str_ = s1[i - 1] + str_
            i -= 1
            j -= 1
        elif dp[i - 1][j] > dp[i][j - 1]:
            i -= 1
        else:
            j -= 1
    return str_[::-1]       
    
s1 = "abaabaaaaa"
s2 = "aabbaaaaaabb"
print(lcs(s1,s2))    
# The above code prints only one longest common string 


# The following code print all lcs

# from collections import deque

# def all_longest_common_subsequences(s, t):
#     n = len(s)
#     m = len(t)
#     dp = [[-1] * (m + 1) for _ in range(n + 1)]
    
#     # Base cases
#     for j in range(m + 1):
#         dp[0][j] = 0
#     for i in range(n + 1):
#         dp[i][0] = 0
    
#     # Fill the dp array
#     for i in range(1, n + 1):
#         for j in range(1, m + 1):
#             if s[i - 1] == t[j - 1]:
#                 dp[i][j] = 1 + dp[i - 1][j - 1]
#             else:
#                 dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])
    
#     # Set to store unique longest common subsequences
#     ans = set()
#     q = deque()
#     q.append(((n, m), ""))
    
#     # BFS in dp array
#     while q:
#         x, y = q[0][0] #x=n,y=m  
#         str = q[0][1]
#         q.popleft()
#         #     in cpp # int x = q.front().first.first;
# 	        # int y = q.front().first.second;
# 	        # string str = q.front().second;
# 	        # q.pop();
#         if x == 0 or y == 0:
#             ans.add(str)
#         else:
#             if s[x - 1] == t[y - 1]:
#                 q.append(((x - 1, y - 1), s[x - 1] + str))
#             else:
#                 if dp[x - 1][y] >= dp[x][y - 1]:
#                     q.append(((x - 1, y), str))
#                 if dp[x][y - 1] >= dp[x - 1][y]:
#                     q.append(((x, y - 1), str))
    
#     return sorted(ans)

# # Example usage
# s1 = "abaabaaaaa"
# s2 = "aabbaaaaaabb"
# print(all_longest_common_subsequences(s1, s2))
# output should be - aaaaaaaa aabaaaaa abaaaaaa abbaaaaa



def find_lcs(s, t, dp, i, j):
    if i == 0 or j == 0:
        return [""]
    elif s[i - 1] == t[j - 1]:
        lcs_list = []
        lcs_list.extend([lcs + s[i - 1] for lcs in find_lcs(s, t, dp, i - 1, j - 1)]) #This insert all outcom of find_lcs function into lcs_list
        return lcs_list
    else:
        lcs_list = []
        if dp[i - 1][j] >= dp[i][j - 1]:
            lcs_list.extend(find_lcs(s, t, dp, i - 1, j))
        if dp[i][j - 1] >= dp[i - 1][j]:
            lcs_list.extend(find_lcs(s, t, dp, i, j - 1))
        return lcs_list

def ALCS(s, t):
    n = len(s)
    m = len(t)
    
    # Initialize DP array
    dp = [[0] * (m + 1) for _ in range(n + 1)]
    
    # Fill the DP array
    for i in range(1, n + 1):
        for j in range(1, m + 1):
            if s[i - 1] == t[j - 1]:
                dp[i][j] = dp[i - 1][j - 1] + 1
            else:
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])
    
    # Find all LCSs using DP table
    lcs_length = dp[n][m]
    lcs_list = find_lcs(s, t, dp, n, m)
    
    return set(sorted(lcs_list))

# Example usage
s1 = "abaabaaaaa"
s2 = "aabbaaaaaabb"
print(ALCS(s1, s2))
