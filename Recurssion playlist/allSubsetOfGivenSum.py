# def subsetSum(arr,sum,index,totalArr,subarr):
#     if index<0:
#         if sum==0:
#             totalArr.append(subarr)
#             return 
#         else:return 
#     subsetSum(arr,sum-arr[index],index-1,totalArr,subarr+[arr[index]])
#     subsetSum(arr,sum,index-1,totalArr,subarr)
# arr=[0,1,2,5,3,8]
# sum=8
# totalArr=[]
# subsetSum(arr,sum,len(arr)-1,totalArr,[])
# print(totalArr)    
def subsetSum(arr,sum,index,totalArr,subarr):
    if index<0:
        if sum==0:
            totalArr.append(subarr)
            return 
        else:return 
    subsetSum(arr,sum-arr[index],index-1,totalArr,subarr+[arr[index]])
    subsetSum(arr,sum,index-1,totalArr,subarr)
    return totalArr
arr=[0,1,2,5,3,8]
sum=8
print(subsetSum(arr,sum,len(arr)-1,[],[]))




