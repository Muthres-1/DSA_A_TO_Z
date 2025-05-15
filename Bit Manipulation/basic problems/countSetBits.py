# def countSetBits(n):
#     count=0
#     while(n):
#         if (n%2)==1:count+=1 #This is checking for odd so I can also n&1==1 
#         n=n//2
#     return count
# def countSetBits2(n):
#     count=0
#     while(n):
#         if (n&1)==1:count+=1 
#         n=n>>1
#     return count
# print(countSetBits2(4))    
# print(countSetBits2(17))    

def countSetBits(n):
    count=0
    while(n):
        n=n&n-1
        count+=1
    return count 
print(countSetBits(4))    
print(countSetBits(17)) 
   
