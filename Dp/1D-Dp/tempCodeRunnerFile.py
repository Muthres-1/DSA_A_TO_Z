def robberedAmount(n,nums,count):
    if n<0: return count
    l=robberedAmount(n-2,nums,count+nums[n])
    count=max(l,robberedAmount(n-1,nums,count))
    return count
nums = [2,1,1,2]
n=len(nums)
count=0
print(robberedAmount(n-1,nums,count))