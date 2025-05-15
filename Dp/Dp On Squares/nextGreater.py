#in this if we use array like circular to find next greater but in 
# histogram we don't use circular in that we just start from n-1 not from 2*n-1
def nextGreaterElements(nums):
        n = len(nums)
        nge = [-1] * n
        st=[]
        for i in range(2*n-1,-1,-1):
                while st and st[-1]<=nums[i%n]:
                        st.pop()
                if i<n:
                        if len(st)!=0:#len(st)=st
                                nge[i]=st[-1]
                st.append(nums[i%n])        
        return nge
nums = [1,2,1]
print(nextGreaterElements(nums)) 
                