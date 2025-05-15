# count prime lesser than n
# import math
# def isPrime(n):
#     if n <= 1:
#         return False
#     if n <= 3:
#         return True
#     if n % 2 == 0 or n % 3 == 0:
#         return False
#     for i in range(5, int(math.sqrt(n)) + 1, 6):
#         if n % i == 0 or n % (i + 2) == 0: #6k-1=i and 6k+1=i+2
#             return False
#     return True
# def countPrime(n):
#     count=0
#     if n==3:return 1
#     if n==4:return 2
#     for i in range(1,(n//2)+1):
#         if isPrime(i):
#             count+=1
#         if i!=n-i and n-i>=n//2 and isPrime(n-i):count+=1   
#     return count  
# print(countPrime(6))     


# def countPrime(n):
#     if n==0 or n==1:return 0
#     isPrime=[1]*(n)
#     isPrime[0]=0
#     isPrime[1]=0
#     for i in range(2,n):
#         if isPrime[i]:
#             for j in range(i+i,n,i):
#                 isPrime[j]=0
#     count=0            
#     for i in range(n):
#         if isPrime[i]:count+=1
#     return count                
 
# print(countPrime(20))    

# Optimization of time complexity

import math
def countPrime(n):
    if n==0 or n==1:return 0
    isPrime=[1]*(n)
    isPrime[0]=0
    isPrime[1]=0
    for i in range(2,int(math.sqrt(n)+1)):
        if isPrime[i]:
            for j in range(i*i,n,i):
                isPrime[j]=0
    count=0            
    for i in range(n):
        if isPrime[i]:count+=1
    return count                

print(countPrime(7))    
   
