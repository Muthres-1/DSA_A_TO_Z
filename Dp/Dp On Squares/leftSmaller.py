def leftSmallerElements(nums):
        n = len(nums)
        lse = [-1] * n
        st=[]
        for i in range(n):
                while st and st[-1]>=nums[i]:
                        st.pop()   
                if len(st)!=0:#len(st)=st
                                lse[i]=st[-1]
                st.append(nums[i])        
        return lse
nums = [1,2,1]
print(leftSmallerElements(nums)) 