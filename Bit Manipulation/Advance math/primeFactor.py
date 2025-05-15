import math
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
# def primeFactor(n):
#     count=0
#     lst=[]
#     for i in range(1,n+1,1):
#         if n%i==0 and isPrime(i):lst.append(i)
#     return lst
# print(primeFactor(2))


# method 2

# def primeFactor(n):
#     lst=[]
#     for i in range(1,int(math.sqrt(n))+1):
#         if n%i==0:
#             if isPrime(i):lst.append(i)
#             if n//i!=i:
#                 if isPrime(n//i):lst.append(n//i)
#     return lst            
# print(primeFactor(35))                

# There is following another solution also but this takes too long time rather than above codes
# def primeFactor(n):
#     lst=[]
#     for i in range(2,n+1):
#         if n%i==0: #here I need not to check isPrime because we are starting from and after we are deviding n by only primes because we are decreasing for further information see striver video
#             lst.append(i)
#         while(n%i==0):
#             n/=i    
#     return lst
# print(primeFactor(35))        


def primeFactor(n):
    lst=[]
    for i in range(2,int(math.sqrt(n)+1)):
        if n%i==0:
            lst.append(i)
        while(n%i==0):
            n//=i
    if n!=1:
        lst.append(n)        
    return lst    
print(primeFactor(35)) 
# in just above solution we don't look complement of i even we are goint till square root of n 
# because we are again deviding that by same or next prime if and if dividend also prime then at the end we added that also
