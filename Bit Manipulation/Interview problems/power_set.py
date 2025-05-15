def powerSet(arr,n):
    if n==0:return [{}]
    if n==1:return [{},{arr[0]}]
    ans=[]
    for i in range(1<<n):
        subset=[]
        for j in range(n):
            if i&(1<<j):
                subset.append(arr[j])
        ans.append(subset)
    return ans
print(powerSet([1,2,3],3))            
# print(1<<0)