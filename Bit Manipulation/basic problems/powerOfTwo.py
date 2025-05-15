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

def isPowerOfTwo(n):
    if (n//1)!=n or n<1:return "false" # for non-integer because there is given for integer
    strr=convertBaseTwo(n)
    total=0
    for i in range(len(strr)):
        if strr[i]=="1":
            total+=1
    if total==1:
        return "true"
    else:return "false"
def powerOfTwo(n):
    if n<1:return False
    else:
        if (n&(n-1))==0:return True;   
        return False 
 
print(isPowerOfTwo(3)) 
print(powerOfTwo(2))       

