# One way to solve go through each iteration of start and goal and see that 
# which bit of start is not equal to goal if equal to goal then no change required and if 
# not equal then change is required but this is too much time taking process 
# So I am taking first xor of start and goal and after set bit in result of taking xor
# tells me the number of operations required

def noOfBits(n):
    if n==0:
        return 0
    if n==1:return 1
    count=0
    while(n):
        if n%2:count+=1
        n=n//2
    return count
    
def minBitFlip(start,goal):
    if start==goal:
        return 0
    return noOfBits(start^goal)
print(minBitFlip(10,7))