#brute force approach 
def largest_area(arr):
    n = len(arr)
    max_area = 0
    for i in range(n):
        min_height = float('inf')
        for j in range(i, n):
            min_height = min(min_height, arr[j])
            max_area = max(max_area, min_height * (j - i + 1))
    return max_area
arr = [2, 1, 5, 6, 2, 3, 1]
n = len(arr)
print(largest_area(arr))


# Optimization approach


def nextSmallerElements(nums,n):
        nse = [0]*n
        st=[]
        for i in range(n-1,-1,-1):
                while st and nums[st[-1]]>=nums[i]:
                        st.pop()
                
                if st:
                    nse[i]=st[-1]-1
                else:
                       nse[i]=n-1    
                        
                st.append(i)        
        return nse
def leftSmallerElements(nums,n):
        lse = [0]*n
        st=[]
        for i in range(n):
                while st and nums[st[-1]]>=nums[i]:
                        st.pop()   
                if st:
                    lse[i]=st[-1]+1
                else:
                       lse[i]=0                           
                st.append(i)        
        return lse
heights = [2,1,5,6,2,3]
n = len(heights)
lse=leftSmallerElements(heights,n)
nge=nextSmallerElements(heights,n)
maxArea=0
for i in range(n):
    maxArea=max(maxArea,(nge[i]-lse[i]+1)*heights[i])
print(maxArea)


 