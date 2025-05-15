def xorL_to_R(L,R):
    xor=0
    for i in range(L,R+1,1):
        xor=xor^i
    return xor
print(xorL_to_R(1,3))   

# Optimizing solution of above 
# if L=1 and R=n then following is the solution 
# if n%4==1 then return 1
# if n%4==2 then return n+1
# if n%4==3 then return 0
# if n%4==0 then return n
# after for L to R take both of xor L and R
# (1^2^3)^(1^2^3^4^5^6)=(4^5^6)
def xorOneToN(n):
    if n%4==0:return n
    if n%4==1:return 1
    if n%4==2:return n+1
    if n%4==3:return 0    

def xorL_to_R(L,R):
    return xorOneToN(L-1)^xorOneToN(R)
print(xorL_to_R(1,3))

