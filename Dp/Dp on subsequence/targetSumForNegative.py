# def printBool(n, len):
# 	while n:
# 		if n & 1:
# 			print("1 ")
# 		else:
# 			print("0 ")
# 		n = n >> 1
# 		len -= 1
# 	while len:
# 		print("0 ")
# 		len -= 1
# 	print()
#  the printBool function is to print all subset of the given set
# using power set algorithm
def printSubsetsCount(arr, n, val):
	sum = 0 
	count = 0
	for i in range(0, 1 << n):
		sum = 0
		print(i)
		for j in range(0, n): # by the help of this loop we are checking that the j th index element is present or not in the i th subset
			if (i & 1 << j) > 0:
				sum += arr[j] 
		if (sum == val):
			count += 1
	if (count == 0):
		print("No subset is found")
	else:
		print(count)
arr = [1, 2, 3,]
n=3
# print(1<<n) # 2^n
printSubsetsCount(arr, 3, 0)
