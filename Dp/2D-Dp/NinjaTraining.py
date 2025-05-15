# Greedy solution but this won't give correct solution bcz this gives wrong output for following input or [[1,50,2],[1,100,2]] also for this one 
#  Greedy method gives wrong answer
# def point(n,points,last,previous,count):   
#     for i in range(0,n,1):        
#         for j in range(0,len(points[i]),1):
#             if previous!=j:
#                 last=points[i].index(max(points[i][j],points[i][last]))
#             else:
#                 if j==0: last=1                 
#         previous=last        
#         count+=points[i][previous]
#         last=0
#     return count
# n = 10
# points = [[5,10, 7], [4, 8, 9], [9, 3, 10],[2, 4, 6],[10, 9, 5], [1, 8, 7], [4, 7, 2], [6, 5, 3], [1, 10, 8],[4,8,3]]
# print(point(n,points,0,-1,0))  
#  So Greedy approach fails so we will go with another approach in which we find all pairs and return the max amount having pair

# class Solution {
#   public:
#     int helper(vector<vector<int>> arr,int rows,int cols,int pc,int currRow,int total){
#         if(currRow>=rows)return total;
#         else{
#             for(int i=0;i<cols;i++){
#                 if(i!=pc){
#                     total=max(total,helper(arr,rows,cols,i,currRow+1,total+arr[currRow][i]));
                    
#                 }
#             }
#         }
#         return total;
#     }
#     int maximumPoints(vector<vector<int>>& arr, int n) {
#         return helper(arr,n,3,-1,0,0);
#     }
# };
# there is a problem with the above recursive solution that if we go from col =0 in row=0 to col=1 in row=0 then total has already value so total do increment in that same as for row =1 and 2 and so on
# so the following is the correct answer
# def point(n,points,previous,count):
#     if n<0 : return count
#     precount=0
#     for i in range(0,3,1):        
#         if previous!=i:
#             precount=max(precount,point(n-1,points,i,count+points[n][i]))                   
#     return precount;         
# n = 10
# points = [[5,10, 7], [4, 8, 9], [9, 3, 10],[2, 4, 6],[10, 9, 5], [1, 8, 7], [4, 7, 2], [6, 5, 3], [1, 10, 8],[4,8,3]]
# print(point(n-1,points,-1,0))

# Optimization of time complexity using dp memo
# The meaning of memo[i][j] is that =taking that element of matrix what is the max answer from 0 to that row or till that day

# def point(n,points,previous,memo):
#     if previous!=-1 and memo[n][previous]!=-1:return memo[n][previous]
#     if n<0 : return memo[0][previous]     
#     for i in range(0,3,1):          
#         if previous!=i:
#             memo[n][i]=max(memo[n][i],point(n-1,points,i,memo)) #Don't do such kind of thing here in each iteration i will change it's own value so 
#             # we memo[n][i] will not update properly
#     return max(memo[n])

# def point(n,points,previous,memo):
#     if n<0 : return 0
#     if previous!=-1 and memo[n][previous]!=-1:return memo[n][previous]    
#     maxi=0     
#     for i in range(0,3,1):          
#         if previous!=i:
#             maxi=max(maxi,points[n][i]+point(n-1,points,i,memo))                   
#     memo[n][previous]=maxi
#     return memo[n][previous]
# n = 10
# points = [[5,10, 7], [4, 8, 9], [9, 3, 10],[2, 4, 6],[10, 9, 5], [1, 8, 7], [4, 7, 2], [6, 5, 3], [1, 10, 8],[4,8,3]]
# memo=[[-1 for _ in range(3)] for _ in range(n)]
# print(point(n-1,points,-1,memo))

#  For large input So we will this problem by iterative approach 
# def pointsIter(points,n):
#     if n==0: return 0
#     memo=[[-1 for _ in range(3)] for _ in range(n)]
#     for i in range(3):
#         memo[0][i]=points[0][i]
#     for i in range(1,n):
#         for k in range(3):
#             for j in range(3):
#                 if j!=k:
#                     memo[i][j]=max(memo[i][j],memo[i-1][k]+points[i][j])
#     return max(memo[n-1])
# n = 10
# points = [[5,10, 7], [4, 8, 9], [9, 3, 10],[2, 4, 6],[10, 9, 5], [1, 8, 7], [4, 7, 2], [6, 5, 3], [1, 10, 8],[4,8,3]]
# print(pointsIter(points,n))        

  

# # for large loop this above 3 loop program also giving time limit exceed
# # So we will reduce number of loop to two loop 

# def pointsIter2(points,n):
#     if n==0: return 0
#     memo=[[-1 for _ in range(3)] for _ in range(n)]
#     for i in range(3):
#         memo[0][i]=points[0][i]
#     for i in range(1,n):
#         for j in range(3):
#             memo[i][j]=points[i][j]+max(memo[i-1][(j+1)%3],memo[i-1][(j+2)%3])
        
#     return max(memo[n-1])
# n = 10
# points = [[5,10, 7], [4, 8, 9], [9, 3, 10],[2, 4, 6],[10, 9, 5], [1, 8, 7], [4, 7, 2], [6, 5, 3], [1, 10, 8],[4,8,3]]
# print(pointsIter2(points,n))        



# def NINJA(points,n,total,preactivity):
#     if n<0:
#         return total
#     if preactivity==0:
#         return max(NINJA(points,n-1,total+points[n][1],1),NINJA(points,n-1,total+points[n][2],2))
#     elif preactivity==1:
#         return max(NINJA(points,n-1,total+points[n][0],0),NINJA(points,n-1,total+points[n][2],2))
#     elif preactivity==2:
#         return max(NINJA(points,n-1,total+points[n][1],1),NINJA(points,n-1,total+points[n][0],0))
#     else:
#         return max(NINJA(points,n-1,total+points[n][1],1),NINJA(points,n-1,total+points[n][0],0),NINJA(points,n-1,total+points[n][2],2))
# points = [[5,10, 7], [4, 8, 9], [9, 3, 10],[2, 4, 6],[10, 9, 5], [1, 8, 7], [4, 7, 2], [6, 5, 3], [1, 10, 8],[4,8,3]]
# print(NINJA(points,len(points)-1,0,-1))

