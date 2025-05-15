# first method to generate all subsequence and check,that is palindromic or not 

#  Another method-- find the longest common subsequence between s1 and reverse(s1) 

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
s1="bbbab"
s2=s1[::-1]
print(lca(s1,s2))