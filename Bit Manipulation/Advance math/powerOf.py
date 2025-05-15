# def power(x,y):
#     ans=1
#     for i in range(1,abs(y)+1):
#         ans=ans*x
#     if y <0 :return 1/ans    
#     return ans    
# print(power(2,3))

def power(x,n):
    ans=1 
    l=abs(n)
    while(l>0):
        if l&1:
            ans=ans*x
            l=l-1
        else:
            x=x*x
            l=l//2
    if n<0:return 1/ans        
    return ans
print(power(2,-3))            