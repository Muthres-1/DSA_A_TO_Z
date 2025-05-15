def lowerBound(arr, n, x):
    left=0
    right=n
    while left<right:
        mid=(left+right)//2
        if x>arr[mid]:
            left=mid+1
        else:
            right=mid
    return left 
         

def LISbinary(arr,n):
    if n==0:return 0
    lst=[arr[0]]
    length=1
    for i in range(1,n):
        if arr[i]>lst[-1]:
            lst.append(arr[i])
            length+=1
        else:
            index=lowerBound(lst,length,arr[i])
            lst[index]=arr[i]
    return length
arr=[5,8,3,7,9,1]  
n=6
print(LISbinary(arr,n))   
    