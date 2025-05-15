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
def minNoOfDeletion(word1,word2):
    n=lca(word1,word2)
    return len(word1)+len(word2)-2*n
word1 = "leetcode"
word2 = "etco"
print(minNoOfDeletion(word1,word2))