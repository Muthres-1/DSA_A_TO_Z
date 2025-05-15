
function combinationSum2(arr,index,sum,subarr,totalArr,size){
    if(sum<0){
        return ;
    }    
    if(sum==0 &&subarr.length===size){
        totalArr.push([...subarr]);
        return ;
    }
    for(let i=index;i<arr.length;i++){
     if(i>index&&arr[i]==arr[i-1]){
        continue;
     }
     if(arr[i]>sum){
        break;
     }
     subarr.push(arr[i]);
     combinationSum2(arr,i+1,sum-arr[i],subarr,totalArr,size);
     subarr.pop();
    }
    }
    function combinationSum(arr,sum,size){
        arr.sort((a, b) => a - b);
        totalArr=[];
        combinationSum2(arr,0,sum,[],totalArr,size)
        return totalArr;
    }
var combinationSum3 = function(k, n) {
    arr=[1,2,3,4,5,6,7,8,9];
    return combinationSum(arr,n,k);
};