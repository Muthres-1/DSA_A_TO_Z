def powerSet(arr,n):
    if n==0:return [{}]
    if n==1:return [{},{arr[0]}]
    ans=[]
    for i in range(1<<n):
        subset=[]
        for j in range(n): # yaha hum n isliye le rhe h bcz total element bhi n and sabhi number from 0 to 2^n-1 ko bhi n bits me represent kiya ja sakta h
            if i&(1<<j):#left shift = << and right shift = >>
                subset.append(arr[j])
        ans.append(subset)
    return ans
class Solution(object):
    def subsets(self, arr):
        return powerSet(arr,len(arr))
        
        