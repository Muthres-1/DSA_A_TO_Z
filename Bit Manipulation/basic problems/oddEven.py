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
# def oddOrEven(n):
#     if n==0:return -1
#     if convertBaseTwo(n)[-1]=="1":return "odd"
#     else:return "even"
# print(oddOrEven(0))    

# Another best method
def oddOrEven(n):
    if (n &1)==1:
        return "odd"
    else:return "even"