# class Solution:
#     def f(self, height, n):
#         if n <= 0:
#             return 0
#         elif n == 1:
#             return abs(height[n] - height[n-1])
#         else:
#             return min(
#                 abs(height[n] - height[n-1]) + self.f(height, n-1),
#                 abs(height[n] - height[n-2]) + self.f(height, n-2)
#             )

#     def minimumEnergy(self, height):
#         n = len(height)
#         return self.f(height, n-1)

# def frogJump(memo,n,index,arr):
#     if index==1: return abs(arr[1]-arr[0])
#     elif index==0: return 0 # don't return arr[0] because we are starting from zero so now arr[0]-arr[0]
#     if index<0: return 0
#     if memo[index]!=-1 : return memo[index]     
#     l=abs(abs(arr[index]-arr[index-1])+frogJump(memo,n,index-1,arr))
#     m=abs(arr[index]-arr[index-2])+frogJump(memo,n,index-2,arr)
#     memo[index]=min(l,m)
#     return memo[index]
# n=4
# arr=[10,20,30,10]
# memo=[-1]*(n)
# print(frogJump(memo,n-1,n-1,arr))        
    
#Tabulation approach
# def frogJumpIter(memo,n,arr):
#     if n==0 : return 0
#     memo[0]=0
#     for i in range(0,n+1,1):
#         for index in range(i,n+1,2):
#             if index+1 < n+1:
#                 if memo[index+1]!=-1:
#                     memo[index+1]=min(memo[index+1],memo[index]+abs(arr[index+1]-arr[index]))  
#                 else:
#                     memo[index+1]=memo[index]+abs(arr[index+1]-arr[index]) 
#             if index +2 < n+1:
#                 if memo[index+2]!=-1:
#                     memo[index+2]=min(memo[index+2],memo[index]+abs(arr[index+2]-arr[index]))  
#                 else:
#                     memo[index+2]=memo[index]+abs(arr[index+2]-arr[index])   
#     return memo[n]        

# n=4
# arr=[10,20,30,10]
# memo=[-1]*(n)
# print(frogJumpIter(memo,n-1,arr)) 

# This code is also correct but there is coming a problem of time limit exceed 
# This code can be done also using single loop
# Tabulation approach
def frogJumpIterSingleLoop(memo,n,arr):
    if n==0:return 0
    memo[0]=0
    memo[1]=abs(arr[1]-arr[0])
    for i in range(2,n+1):
        sJump=memo[i-1]+abs(arr[i]-arr[i-1])
        fJump=memo[i-2]+abs(arr[i]-arr[i-2])
        memo[i]=min(sJump,fJump)
    return memo[n]
n=4
arr=[10,20,30,10]
memo=[-1]*(n)
print(frogJumpIterSingleLoop(memo,n-1,arr))



            