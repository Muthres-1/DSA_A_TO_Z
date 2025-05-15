# Recursive way
# This is same as the problem in which frog is standing at nth stair and he have to go at 1st stair
#  1st we will write the program for total case 
# def frogJump(n,k):
#     if n==1: # here one is written bcz he have to go until 1 not to go ahead of one 
#         return 1
#     if n<1:
#         return 0
#     count=0
#     for i in range(1,k+1):
#         count+=frogJump(n-i,k)
#     return count
# n=4
# k=2
# print(frogJump(n,k))

#  now we will write the program for min cost
# the problem is for n to 1 we can change this n-1 to 0 by this change there will not be affect bcz in coding it will be convienience
# def frogJumWithMinCost(n,k,height,memo):
#     if n==1:
#         memo[1]=height[1]-height[0]
#         return memo[1]
#     elif n<1: return 0
#     if memo[n]!=-1:return memo[n]
#     for i in range(1,k+1,1):
#         if n-i<0: break
#         if memo[n]!=-1:
#             memo[n]=min(memo[n],abs(height[n]-height[n-i])+frogJumWithMinCost(n-i,k,height,memo))
#         else:
#             memo[n]=frogJumWithMinCost(n-i,k,height,memo)+abs(height[n]-height[n-i])    
#     return memo[n]
# n = 5
# k = 3
# height = [10, 30, 40, 50, 20]
# memo=[-1]*(n+1)
# print(frogJumWithMinCost(n-1,k,height,memo))

#Tabulation approach 
def frogJumpIter(n,k,height,memo):
    if n==0 or k==0 :return 0
    memo[1]=height[1]-height[0]
    memo[0]=0
    for i in range(2,n+1,1):
        for j in range(1,k+1,1):
            if i-j<0:break
            if memo[i]!=-1:
                memo[i]=min(abs(height[i]-height[i-j])+memo[i-j],memo[i])
            else:
                memo[i]=abs(height[i]-height[i-j])+memo[i-j]
    return memo[n]
n = 5
k = 3
height = [10, 30, 40, 50, 20]
memo=[-1]*(n+1)
print(frogJumpIter(n-1,k,height,memo))


    

