function findsum(subarr,sum)
{
    total=0;
    for(let x of subarr){
        total+=x;
    }
    return (total==sum);
}
function printSubsequences(arr,index,subarr,sum,totalArrayOfGivenSum)
{
    if(index==arr.length)
        {
           if(findsum(subarr,sum)){
             totalArrayOfGivenSum.push([...subarr]);
           }           
        }
    else{
        subarr.push(arr[index])
        printSubsequences(arr,index+1,subarr,sum,totalArrayOfGivenSum)
        subarr.pop();
        printSubsequences(arr,index+1,subarr,sum,totalArrayOfGivenSum);
       
    }
}
arr=[10,1,2,7,6,1,5];
sum=8;
totalArrayOfGivenSum=[];
printSubsequences(arr,0,[],sum,totalArrayOfGivenSum);
console.log(totalArrayOfGivenSum);


