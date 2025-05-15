// function findSum(sum,subarr){
//     let i=0;
//     let temp=0;
// while(i<subarr.length){
//  temp+=subarr[i];
//  i++;
// } 
// sum.push(temp);
// }
// function sumOfAllSubsequences(arr,sum,subarr,index){
//     if(index>=arr.length){
//         findSum(sum,subarr);
//         return ;
//     }
//     else
//     {
//         subarr.push(arr[index]);
//         sumOfAllSubsequences(arr,sum,subarr,index+1);
//         subarr.pop();
//         sumOfAllSubsequences(arr,sum,subarr,index+1);
//     }
// }
// arr=[2,4,3]
// sum=[];
// sumOfAllSubsequences(arr,sum,[],0);
// console.log(sum);


function subsetSum(arr,sum,list,index){
    if(index<0){
        list.push(sum)
        return 
    }
    subsetSum(arr,sum+arr[index],list,index-1)
    subsetSum(arr,sum,list,index-1)
    return list
}
arr=[2,4,3]
console.log(subsetSum(arr,0,[],arr.length-1));

