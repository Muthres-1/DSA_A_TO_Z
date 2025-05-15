# def minSumTriangle(triangle,row,col,m,sum):
#     if row>=m:
#         return sum
#     if col>=len(triangle[row]):
#         return int(1e9)#      
#     sameind=minSumTriangle(triangle,row+1,col,m,sum+triangle[row][col])
#     nextind=minSumTriangle(triangle,row+1,col+1,m,sum+triangle[row][col])
#     return min(sameind,nextind)
# triangle = [[-10]]
# print(minSumTriangle(triangle,0,0,len(triangle),0)) 
# in this we are going from top to bottom I mean first row to bottom row 
# dp based solution 

# def minSumTriangle(triangle,row,col,m,sum,dp):
#     if row>=m:
#         return sum
    
#     if col>=len(triangle[row]):
#         return int(1e9)
#     if dp[row][col]!=1e9:return dp[row][col]+sum    
      
#     sameind=minSumTriangle(triangle,row+1,col,m,sum+triangle[row][col],dp)
#     nextind=minSumTriangle(triangle,row+1,col+1,m,sum+triangle[row][col],dp)
#     dp[row][col]=min(sameind,nextind)-sum
#     return min(sameind,nextind)
# triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
# dp=[[ int(1e9) for _ in range(len(triangle[i]))] for i in range(len(triangle))]
# print(minSumTriangle(triangle,0,0,len(triangle),0,dp)) 
#  in above code we are going to bottom to up I mean last row to starting row and in dp we are storing the min path up to current row and col from last row 
#  to store in dp matrix like from top to bottom or first row to last row we take it different way like in we can come to any index from previous row's same index or previous row 
# for example if we are on the row number 2 and coloum number 1 then we can come either from row no 1's coloum 1 or coloum 0
# here is the code 
def minSumTriangle(triangle, row, col,dp):
    if row <  0:
        return 0

    if col < 0 or col>=len(triangle[row]):
        return int(1e9)
    
    if dp[row][col] != int(1e9):
        return dp[row][col]

    sameind = triangle[row][col] + minSumTriangle(triangle, row - 1, col,dp)
    nextind = triangle[row][col] + minSumTriangle(triangle, row - 1, col - 1,dp)
    
    dp[row][col] = min(sameind, nextind)
    return dp[row][col]

triangle = [[2], [3, 4], [6, 5, 7], [4, 1, 8, 3]]
m = len(triangle)
dp = [[int(1e9) for _ in range(len(triangle[i]))] for i in range(m)]
m=int(1e9)
for i in range(len(triangle[-1])):
    m=min(m,minSumTriangle(triangle, len(triangle)-1,i,dp))
print(m)

# Note :- if there is given a problem in which question asking to go from initial to end then if in recursive function if we apply like row and coloum decreasing order then 
# the meaning is we are going to from starting to curr row and col but if we apply col and row as increasing then its meaning will not be to go from initital to end 
# then the meaning is that current to first row 
# current to first and int he case of increasing and in case of decreasing first to current which is slight compatible 

# Space Optimization 
def minimumPathSum(triangle, n):
    # Initialize two lists: front and cur to represent the current and previous rows in dp
    front = [0] * n  # This represents the previous row
    cur = [0] * n    # This represents the current row    
    # Initialize the bottom row of dp (front) with the values from the last row of the triangle
    for j in range(n):
        front[j] = triangle[n - 1][j]    
    # Start from the second-to-last row and work upwards
    for i in range(n - 2, -1, -1):
        for j in range(i, -1, -1):
            # Calculate the minimum path sum for the current cell by considering two possible moves: down and diagonal
            down = triangle[i][j] + front[j]
            diagonal = triangle[i][j] + front[j + 1]            
            # Store the minimum of the two possible moves in the current row (cur)
            cur[j] = min(down, diagonal)        
        # Update the previous row (front) with the current row (cur) for the next iteration
        front = cur        
    # The minimum path sum will be stored in the first element of the front list after the loops
    return front[0]

def main():
    # Define the input triangle and its size
    triangle = [[1], [2, 3], [3, 6, 7], [8, 9, 6, 10]]
    n = len(triangle)
    
    # Call the minimumPathSum function and print the result
    print(minimumPathSum(triangle, n))

if __name__ == '__main__':
    main()



def minimumPathSumUtil(i, j, triangle, n, dp):
    # Check if we have already computed the minimum path sum for this cell
    if dp[i][j] != -1:
        return dp[i][j]
    # If we are at the bottom of the triangle, return the value in the current cell
    if i == n - 1:
        return triangle[i][j]
    # Calculate the minimum path sum by considering two possible moves: down and diagonal
    down = triangle[i][j] + minimumPathSumUtil(i + 1, j, triangle, n, dp)
    diagonal = triangle[i][j] + minimumPathSumUtil(i + 1, j + 1, triangle, n, dp)
    # Store the computed minimum path sum in the memoization table
    dp[i][j] = min(down, diagonal)
    return dp[i][j]
# Define a wrapper function to initialize memoization table and start the computation
def minimumPathSum(triangle, n):
    dp = [[-1 for j in range(n)] for i in range(n)]  # Initialize a memoization table with -1
    return minimumPathSumUtil(0, 0, triangle, n, dp)  # Start the recursive computation
# Define the main function where you set up the triangle and call the minimumPathSum function
def main():
    triangle = [[1], [2, 3], [3, 6, 7], [8, 9, 6, 10]]
    n = len(triangle)
    # Call the minimumPathSum function and print the result
    print(minimumPathSum(triangle, n))
# Check if this script is the main program entry point
if __name__ == "__main__":
    main()  # Call the main function to start the program



def minimum_path_sum(triangle, n):
    # Create a 2D array dp to store minimum path sums
    dp = [[0 for j in range(n)] for i in range(n)]    
    # Initialize the bottom row of dp with the values from the last row of the triangle
    for j in range(n):
        dp[n - 1][j] = triangle[n - 1][j]    
    # Start from the second-to-last row and work upwards
    for i in range(n - 2, -1, -1):
        for j in range(i, -1, -1):
            # Calculate the minimum path sum for the current cell by considering two possible moves: down and diagonal
            down = triangle[i][j] + dp[i + 1][j]
            diagonal = triangle[i][j] + dp[i + 1][j + 1]            
            # Store the minimum of the two possible moves in dp
            dp[i][j] = min(down, diagonal)    
    # The minimum path sum will be stored in dp[0][0] after the loops
    return dp[0][0]

def main():
    # Define the input triangle and its size
    triangle = [[1], [2, 3], [3, 6, 7], [8, 9, 6, 10]]
    n = len(triangle)
    
    # Call the minimum_path_sum function and print the result
    print(minimum_path_sum(triangle, n))

if __name__ == '__main__':
    main()


