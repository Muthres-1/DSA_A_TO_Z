# def devideTwoInteger(dividend,divisor):
#     count=0
#     sum=0
#     sign=True
#     if dividend>0 and divisor<0:sign=False
#     if divisor >0 and dividend<0:sign =False
#     while(sum+abs(divisor)<=abs(dividend)):
#         sum+=abs(divisor) 
#         count+=1
#     if sign==False:count=-count    
#     if count<-2**31:return -2**31
#     if count>2**31:return 2**31
#     return count
# print(devideTwoInteger(8,3))    

def devideTwoInteger(dividend,divisor):
    if divisor==1:return dividend
    if divisor==-1:return -dividend    
    if dividend==divisor:return 1
    count=0
    divi=abs(dividend)
    sor=abs(divisor)
    # while(sum+(1<<i)<=abs(dividend)):
    #     sum+=(1<<i)
    #     count+=(1<<i)
    #     i+=1  #this will throw error because first of all most number comes after devision 
    # don't come lowest number so that's why we use to highest
    while(sor<=divi):
        i=0
        while(divi>=(sor*(1<<(i+1)))):i+=1
        divi=divi-(sor*(1<<i))
        count+=(1<<i)  
    sign=True
    if dividend>0 and divisor<0:sign=False
    if divisor >0 and dividend<0:sign =False
    if sign==False:count=-count    
    if count<-2**31:return -2**31
    if count>2**31:return 2**31
    return count
print(devideTwoInteger(7,3))
    
