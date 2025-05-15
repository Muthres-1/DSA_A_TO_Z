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
# def set(n,i):
#     strr=convertBaseTwo(n)
#     lengthOfString=len(strr)
#     ithBit=strr[lengthOfString-1-i]
#     if ithBit=="1":return True
#     else:return False
# print(set(4,0))   

def set(n,i):
    if i<0:return -1
    if n&(1<<i):return True
    else:return False
print(set(500,3))     

    