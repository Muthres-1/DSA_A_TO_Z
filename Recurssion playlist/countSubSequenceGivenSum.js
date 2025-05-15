function findsum(subarr)
{
    total=0;
    for(let x of subarr){
        total+=x;
    }
    return (total==sum);
}
function printSubsequences(arr,index,subarr,sum)
{
     //    we can also add if subarr sum is greater sum then we can return 0;
    if(index==arr.length)
        {
           if(findsum(subarr,sum)){
             return 1;
           }     
       
           else{
            return 0;
           }      
        }
    else{
        subarr.push(arr[index])
        let include = printSubsequences(arr,index+1,subarr,sum)
        subarr.pop();
        let exclude = printSubsequences(arr,index+1,subarr,sum);
       return include+exclude;
    }
}
arr=[1,3,45,556,787,3];
sum=3;
totalArrayOfGivenSum=[];
console.log(printSubsequences(arr,0,[],sum));



