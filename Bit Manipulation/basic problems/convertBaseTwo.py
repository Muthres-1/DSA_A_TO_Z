# Loop way to solve the convert Base two 
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
#         for i in range(len(strr),31,1):
#             strr+="0"
#         if n<0:
#             strr+="1"
#         else:strr+="0"        
#     return strr[::-1]
# n=0
# print(convertBaseTwo(n))

# Recursive way to solve the problem 

def convertBaseTwoRecurrHelp(n,strr):
    if n==1:
        strr+="1"
        return strr
    if n==0:
        strr+="0"
        return strr      
    strr=convertBaseTwoRecurrHelp(n//2,strr)
    if n%2:
        strr+="1"
    else:strr+="0"
    return strr
def convertBaseTwoRecurr(n,strr):
    if n<0:
        strr=convertBaseTwoRecurrHelp(abs(n),strr)
    else: strr=convertBaseTwoRecurrHelp(n,strr)
    x=""
    if n<0:
        x+="1"
    else:x+="0"    
    for i in range(32-len(strr)-1):
        x+="0"    
    x+=strr
    return x
n=-13
strr=""
strr=convertBaseTwoRecurr(n,strr)
print(strr)