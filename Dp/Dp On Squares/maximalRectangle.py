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
def largestArea(heights):
       n = len(heights)
       lse=leftSmallerElements(heights,n)
       nge=nextSmallerElements(heights,n)
       maxArea=0
       for i in range(n):
           maxArea=max(maxArea,(nge[i]-lse[i]+1)*heights[i])
       return maxArea
def maximalRectangle(matrix):
       rows=len(matrix)
       cols=len(matrix[0])
       lst=[0]*cols
       maxi=float('-inf')
       for i in range(cols):
              lst[i]=int(matrix[0][i])
       maxi=largestArea(lst)       
       for i in range(1,rows):
              for j in range(cols):
                     if matrix[i][j]=='0':
                            lst[j]=0
                     else:
                            lst[j]=lst[j]+int(matrix[i][j])
              maxi=max(maxi,largestArea(lst))
       return maxi      
matrix = [["0","1"],["1","0"]]
print(maximalRectangle(matrix))
              

