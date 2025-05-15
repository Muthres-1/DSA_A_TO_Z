# def convertBaseTwo(n):
#     strr=""
#     if n<0:x=abs(n)
#     else:x=n
#     while x!=0:
#         if x%2:
#             strr+='1'
#         else:strr+='0'
#         x=x//2
#     if len(strr)<32:
#         for i in range(len(strr),32,1):
#             strr+="0"
#         if n<0:
#             strr+="1"
#         else:strr+="0"        
#     return strr[::-1]
# def getSetClear(n,i):
#     if i<0:return -1
#     strr=convertBaseTwo(n)
#     lengthOfString=len(strr)
#     ithBit=strr[lengthOfString-i]
#     print(ithBit,end=" ")
#     if ithBit=='0':
#         n=n+2**(i-1)  
#     print(n,end=" ")
#     print(n-2**(i-1))
# getSetClear(70,3)    

# Here is better method for that solution
 
# def getSetClear(n,i):
#     if i<1:return -1
#     if n & (1<<i-1)>0:print(1,n,n-(2**(i-1)))
#     else:print(0,n+(2**(i-1)),n)
# getSetClear(8,1)     
def getSetClear(n,i):
    if i<1:return -1
    if n & (1<<i-1)>0:
        print(1,end=" ")
        print(n,end=" ")
        n=n&~(1<<i-1)
        print(n)
    else:
        print(0,end=" ")
        x=n
        n=n|(1<<i-1)
        print(n,end=" ")
        print(x)   


getSetClear(70,3)     

    


