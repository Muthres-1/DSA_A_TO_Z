def oddOccuredNumber(arr,n):
    xor=0
    for i in range(n):
        xor=xor^arr[i]
    xor=(xor^xor-1)&xor
    b1=0
    b2=0
    for i in range(n):
        if xor&arr[i]:
            b1=b1^arr[i]
        if xor&arr[i]==0:
            b2=b2^arr[i]    
    if b1>b2:
        return [b2,b1]
    else:return [b1,b2]
print(oddOccuredNumber([1,7,5,7,5,4,7,4],8))        
      