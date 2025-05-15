def isPredecessor(word1,word2):
    n1=len(word1)
    n2=len(word2)
    if n1!=n2+1:return False
    first=0
    second=0
    while first<n1:
        if second<n2 and word1[first]==word2[second]:
            first+=1
            second+=1
        else:
            first+=1
    if first==n1 and second==n2:return True
    else:return False            

def stringChain(words):
    n=len(words)
    words.sort(key=len)
    dp=[1]*(n)
    maxi=1
    for i in range(n):
        for j in range(i):
            if isPredecessor(words[i],words[j]) and dp[j]+1>dp[i]:
                dp[i]=dp[j]+1
        if dp[i]>maxi:maxi=dp[i] 
    return maxi           
words = ["a","b","ba","bca","bda","bdca"]
print(stringChain(words))