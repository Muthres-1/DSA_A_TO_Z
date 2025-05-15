# def primeFactor(n):
#     lst=[]
#     for i in range(2,n+1):
#         while(n%i==0):
#             lst.append(i)
#             n/=i    
#     return lst
# print(primeFactor(12246))        



import math
def sieve(size,sieveArr):    
    for i in range(2,int(math.sqrt(size)+1)):
        if sieveArr[i]==i:
            for j in range(i*i,size+1,i):
                sieveArr[j]=i
def primeFactorization(n,sieveArr):
    lst=[]
    while(n!=1):
        lst.append(sieveArr[n])
        n//=sieveArr[n] 
    lst.sort()    
    return lst  
size=2*(10**5)   
sieveArr=[0]*(size+1)                   
for i in range(size+1):
    sieveArr[i]=i
sieve(size,sieveArr)    
n=12246
print(primeFactorization(n,sieveArr))

