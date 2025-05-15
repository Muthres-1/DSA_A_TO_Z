# def divisors(n):
#     lst=[]
#     for i in range(1,n+1):
#         if n%i==0:
#             lst.append(i)
#     return lst
# print(divisors(20))  
import math      
def divisors(n):
    lst=[]
    for i in range(1,int(math.sqrt(n)+1)):
        if n%i==0:
            l=len(lst)
            lst.insert(l//2,i)
            if i!=n//i:
                lst.insert((l//2)+1,n//i)

    return lst
print(divisors(2))        
# at len(lst)/2 and len(lst)/2 +1 