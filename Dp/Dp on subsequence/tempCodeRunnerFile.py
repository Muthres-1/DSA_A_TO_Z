n = 8
# price = [1, 5, 8, 9, 10, 17, 17, 20]
# print(f2(n,Price))

# def f3(n,price):
#     prev=[-int(1e9)for _ in range(n+1)]
#     for i in range(n+1):
#         prev[i]=i*price[0]
#     for i in range(n+1):   
             
#         for j in range(1,n):
#             notTake=prev[j-1]
#             take=-int(1e9)
#             rodLength=j+1
#             if rodLength<=i:
#                 take=price[j]+prev[j-rodLength]
#             prev[j]=max(take,notTake)    
#     return prev[n]                
   
# n = 8
# price = [1, 5, 8, 9, 10, 17, 17, 20]
# print(f3(n,Price))