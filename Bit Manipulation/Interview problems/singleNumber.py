# Brute force method 
def single_number(nums):
    for i in nums:
        count = 0
        for j in nums:
            if i == j:
                count += 1
        if count == 1:
            return i
nums = [4, 1, 2, 1, 2]
print(single_number(nums)) 
# Brute force using map
def find_single(nums):
    count_map = {}
    # Step 2: Iterate through the array and update the count map
    for num in nums:
        if num in count_map:
            count_map[num] += 1
        else:
            count_map[num] = 1
    # Step 3: Find the element with count 1
    for num in count_map:
        if count_map[num] == 1:
            return num
nums = [4, 1, 2, 1, 2]
print(find_single(nums))
# In this solution the time complexity is O(n*log(m)+m) and space complexity O(m),,where m is (n/2+1) and n is number of total element in given array 

# Optimization solution 
#  In this we will take xor of every element 
def find_single(arr):
    xor=0
    for i in range(len(arr)):
        xor=xor^arr[i]
    return xor
arr= [2,2,1]
print(find_single(arr))    
