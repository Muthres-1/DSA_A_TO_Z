def DecimalOfBinary(strr):
    sum=0
    n=len(strr)
    if strr[0]=='1':
        k=0
    else:k=-1    
    power=1
    for i in range(n-1,k,-1):
        if strr[i]=='1':
            sum+=power
        power*=2
    if k==0:sum=-sum    
    return sum
        
def convertBaseTwo(n):
    strr=""
    if n<0:x=abs(n)
    else:x=n
    while x!=0:
        if x%2:
            strr+='1'
        else:strr+='0'
        x=x//2
    if len(strr)<32:
        for i in range(len(strr),31,1):
            strr+="0"
        if n<0:
            strr+="1"
        else:strr+="0"        
    return strr[::-1]
n=100
print(DecimalOfBinary(convertBaseTwo(n)))     
 
        