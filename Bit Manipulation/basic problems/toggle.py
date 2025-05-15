def togle(n,i):
    n=n^(1<<i)
    return n
print(togle(13,1))