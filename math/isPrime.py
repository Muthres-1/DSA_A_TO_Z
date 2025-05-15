import math 
# def isPrime(n):
#     count=0
#     for i in range(1,n+1):
#         if n%i==0:count+=1
#     if count==2:return True
#     return False    
# print(isPrime(21))   
# # Time complexity is O(n)
# # here is the optimization solution 
# def isPrime(n):
#     count=0
#     for i in range(1,int(math.sqrt(n))+1):
#         if n%i==0:count+=1
#         if n//i!=i:count+=1 # If n is not a perfect square,count its reciprocal factor or complement of i
#         if count>2:return False
#     if count==2:return True
#     return False
# print(isPrime(2))    
# print(isPrime(3))    
# print(isPrime(20))    
# print(isPrime(21))  
# more optimal solutions

def isPrime(n):
    if n <= 1:
        return False
    if n <= 3:
        return True
    if n % 2 == 0 or n % 3 == 0:
        return False
    for i in range(5, int(math.sqrt(n)) + 1, 6):
        if n % i == 0 or n % (i + 2) == 0: #6k-1=i and 6k+1=i+2
            return False
    return True 
print(isPrime(7)) 
# explanation ---> any number(greater than 3) can be written in the 
# format of 6k+i,i=-1,0,2,3,4  so for we need to check these 
# format of number that they are prime or not 
# and because 6k+2,6k+3,6k+4,6k these are divisable by 2 or 3 so
#  we know that they can not be prime so now we need to check that
#  remaining kind of format or multiple of  6k+1 and 6k-1