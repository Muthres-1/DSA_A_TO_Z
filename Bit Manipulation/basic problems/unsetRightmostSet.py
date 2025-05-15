def unsetRightmostSet(n):
    n=n&n-1
    return n
print(unsetRightmostSet(40))