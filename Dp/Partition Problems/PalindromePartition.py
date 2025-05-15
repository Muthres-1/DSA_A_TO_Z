# def isPalindrome(str,i,j):
#     while(i<j):
#         if str[i]!=str[j]:
#             return False
#         i+=1
#         j-=1
#     return True   
# def palindromePartition(str,i,j):
#     if i>=j or isPalindrome(str,i,j):
#         return 0
#     mini=int(1e9)
#     for index in range(i,j):
#         x=1+palindromePartition(str,i,index) + palindromePartition(str,index+1,j)
#         mini=min(mini,x)
#     return mini
# s = "aab" 
# print(palindromePartition(s,0,len(s)-1))


# Optimization using dp 

# def isPalindrome(str,i,j):
#     while(i<j):
#         if str[i]!=str[j]:
#             return False
#         i+=1
#         j-=1
#     return True   
# def palindromePartition(str,i,j,dp):
#     if i>=j or isPalindrome(str,i,j):
#         return 0
#     if dp[i][j]!=-1:return dp[i][j]
#     mini=int(1e9)
#     for index in range(i,j):
#         x=1+palindromePartition(str,i,index,dp) + palindromePartition(str,index+1,j,dp)
#         mini=min(mini,x)
#     dp[i][j]=mini    
#     return mini
# s = "aab" 
# n=len(s)
# dp=[[-1 for i in range(n)] for i in range(n)]
# print(palindromePartition(s,0,n-1,dp))

# Optimization using Tabulation 


# def isPalindrome(str,i,j):
#     while(i<j):
#         if str[i]!=str[j]:
#             return False
#         i+=1
#         j-=1
#     return True   
# def palindromePartition(str):
#     n=len(s)
#     if isPalindrome(str,0,n-1):return 0
#     dp=[[0 for i in range(n)] for i in range(n+1)]
#     for length in range(1,n+1):
#         for i in range(n-length+1):
#             j=i+length-1
#             mini=int(1e9)
#             if isPalindrome(str,i,j):
#                 dp[i][j]=0
#                 continue
#             for index in range(i,j):
#                 x=1+dp[i][index] + dp[index+1][j]
#                 mini=min(mini,x)
#             dp[i][j]=mini
#     return dp[0][n-1]  
# s = "aab"
# print(palindromePartition(s))


# Optimization 


# def isPalindrome(str,i,j):
#     while(i<j):
#         if str[i]!=str[j]:
#             return False
#         i+=1
#         j-=1
#     return True   

# def palindromePartition(str,i):
#     n=len(str)
#     if i>=n or isPalindrome(str,i,n-1):
#         return 0
#     mini=int(1e9)   
#     temp=""
#     for index in range(i,n):
#         temp+=str[index]
#         if isPalindrome(str,i,index):
#             x=1 + palindromePartition(str,index+1)
#         mini=min(mini,x)
#     return mini
# s = "aab" 
# print(palindromePartition(s,0))


# Optimization using dp


# def isPalindrome(str,i,j):
#     while(i<j):
#         if str[i]!=str[j]:
#             return False
#         i+=1
#         j-=1
#     return True   

# def palindromePartition(str,i,n,dp):
#     if i>=n or isPalindrome(str,i,n-1):
#         return 0
#     if dp[i]!=-1:return dp[i]
#     mini=int(1e9)   
#     temp=""
#     for index in range(i,n):
#         temp+=str[index]
#         if isPalindrome(str,i,index):
#             x=1 + palindromePartition(str,index+1,n,dp)
#         mini=min(mini,x)
#     dp[i]=mini    
#     return mini
# s = "aab" 
# n=len(s)
# dp=[-1 for i in range(n)]
# print(palindromePartition(s,0,n,dp))

# Optimization using Tabulation 


def isPalindrome(str,i,j):
    while(i<j):
        if str[i]!=str[j]:
            return False
        i+=1
        j-=1
    return True   

def palindromePartition(str):
    n=len(str)
    dp=[0 for i in range(n+1)]
    dp[n]=0
    for i in range(n-1,-1,-1):
            mini=int(1e9)
            temp=""
            for index in range(i,n):
                temp+=str[index]
                if isPalindrome(str,i,index):
                      x=1 + dp[index+1]
                      mini=min(mini,x)
            dp[i]=mini 
    # we subtract 1 because the meaning of dp[i]=in the string from i to n-1 how much partitioned required 
    # but dp[0]=ans+1 because we every time partitioned index we are adding one but when i=0 then there is no need to add it because i<0 there is no string
    return dp[0]-1        
s = "aab" 
print(palindromePartition(s))

# These all are giving time limit exceed so we are doing find first isPalindrome for every strong

def isPalindrome(str,i,j):
    while(i<j):
        if str[i]!=str[j]:
            return False
        i+=1
        j-=1
    return True   

def palindromePartition(str):
    n=len(str)
    dp=[0 for i in range(n+1)]
    dp[n]=0
    isPal=[[False for i in range(n)] for i in range(n)]
    for i in range(n):
         for j in range(i,n):
              isPal[i][j]=isPalindrome(str,i,j)              
    for i in range(n-1,-1,-1):
            mini=int(1e9)
            for index in range(i,n):
                if isPal[i][index]:
                      x=1 + dp[index+1]
                      mini=min(mini,x)
            dp[i]=mini 
    return dp[0]-1        
s = "aab" 
print(palindromePartition(s))

# Still in python this is showing time limit exceed problem but if we use cpp and there if we use 
# vector then it get solve