def evaluateExp(exp,i,j,isTrue):
    if i>j:
        return 0
    if i==j:
        if isTrue:
            if exp[i]=='t':
                return 1
            else:
                return 0
        else:
            if exp[i]=='f':
                 return 1
            else:
                 return 0       
    ways=0
    for ind in range(i+1,j,2):
        lT=evaluateExp(exp,i,ind-1,1)    
        lF=evaluateExp(exp,i,ind-1,0)    
        rT=evaluateExp(exp,ind+1,j,1)    
        rF=evaluateExp(exp,ind+1,j,0)   
        if exp[ind] == '&':
                if isTrue:
                    ways+=lT*rT
                else:
                    ways+=(lF*rT) +(lT*rF) +(lF*rF) 
        elif exp[ind] == '|':    
                if isTrue:
                    ways+=(lF*rT)+(lT*rF) +(lT*rT) 
                else:
                    ways+=(lF*rF) 
        else:
                if isTrue:
                    ways+=(lF*rT)+(lT*rF) 
                else:
                    ways+=(lF*rF) +(lT*rT)              
    return ways    
expression = "|(f,f,f,t)"
n=len(expression)
print(evaluateExp(expression,0,n-1,1))

# Optimization using dp 

# def evaluateExp(exp,i,j,isTrue,dp):
#     if i>j:
#         return 0
#     if i==j:
#         if isTrue:
#             if exp[i]=='t':
#                 return 1
#             else:
#                 return 0
#         else:
#             if exp[i]=='f':
#                  return 1
#             else:
#                  return 0
#     if dp[i][j][isTrue]!=-1:return dp[i][j][isTrue]        
#     ways=0
#     for ind in range(i+1,j,2):
#         lT=evaluateExp(exp,i,ind-1,1,dp)    
#         lF=evaluateExp(exp,i,ind-1,0,dp)    
#         rT=evaluateExp(exp,ind+1,j,1,dp)    
#         rF=evaluateExp(exp,ind+1,j,0,dp)   
#         if exp[ind] == '&':
#                 if isTrue:
#                     ways+=lT*rT
#                 else:
#                     ways+=(lF*rT) +(lT*rF) +(lF*rF) 
#         elif exp[ind] == '|':    
#                 if isTrue:
#                     ways+=(lF*rT)+(lT*rF) +(lT*rT) 
#                 else:
#                     ways+=(lF*rF) 
#         else:
#                 if isTrue:
#                     ways+=(lF*rT)+(lT*rF) 
#                 else:
#                     ways+=(lF*rF) +(lT*rT)  
#     dp[i][j][isTrue]=ways                
#     return ways    
# expression = "&(|(f))"
# n=len(expression)
# dp =[[[-1 for i in range(2)]for i in range(n)] for i in range(n)]
# print(evaluateExp(expression,0,n-1,1,dp))