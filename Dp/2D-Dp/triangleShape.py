def isEven(n):
    if n % 2 == 0:
        return 1
    else:
        return 0

def trianglePattern(row):
    col = 2 * (row - 1) + 1
    for i in range(row):
        for j in range(col):
            if row - i - 1 <= j <= row - 1 + i:
                mi = isEven(i)
                mj = isEven(j)
                if (mi and mj) or ((not mi) and (not mj)):
                    print("*", end="")
                else:
                    print(" ", end="")
            else:
                print(" ", end="")
        print()  # To move to the next line after each row

trianglePattern(20)
