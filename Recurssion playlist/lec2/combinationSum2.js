// in this problem there should not be member inside of final answer like [1,3,5] and [3,1,5] or two same array
// function combinationSum2(arr,index,sum,subarr,totalArr){
// if(sum==0){
//     totalArr.push([...subarr]);
//     return ;
// }
// for(let i=index;i<arr.length;i++){
//  if(i>index&&arr[i]==arr[i-1]){
//     continue;
//  }
//  if(arr[i]>sum){
//     break;
//  }
//  subarr.push(arr[i]);
//  combinationSum2(arr,i+1,sum-arr[i],subarr,totalArr);
//  subarr.pop();
// }
// }
// function combinationSum(arr,sum){
//     arr.sort((a, b) => a - b);
//     totalArr=[];
//     combinationSum2(arr,0,sum,[],totalArr)
//     return totalArr;
// }
// arr=[10,1,2,7,6,1,5]
// sum=8
// totalArr=combinationSum(arr,sum);
// console.log(totalArr);
//  by above way there is coming a time limit exceed problem and also show wrong output 
// above does not show any answer for negative sum


// function combinationSum2(arr,index,sum,subarr,totalArr){
//     if(sum<0){
//         return ;
//     }    
//     if(sum==0){
//         totalArr.push([...subarr]);
//         return ;
//     }
//     // by this loop we are taking one of the element for current index out of index to arr.length-1 
//     for(let i=index;i<arr.length;i++){
//      if(i>index&&arr[i]==arr[i-1]){
//         continue;
//      }
//      if(arr[i]>sum){
//         break;
//      }
//      subarr.push(arr[i]);
//      combinationSum2(arr,i+1,sum-arr[i],subarr,totalArr);
//      subarr.pop();
//     }
//     }
//     function combinationSum(arr,sum){
//         arr.sort((a, b) => a - b);
//         totalArr=[];
//         combinationSum2(arr,0,sum,[],totalArr)
//         return totalArr;
//     }
//     arr=[10,1,2,7,6,1,5]
//     sum=7
//     totalArr=combinationSum(arr,sum);
//     console.log(totalArr);
function combinationSum2(arr, index, sum, subarr, totalArr) {    
    if (sum < 0 || index == arr.length) {
        if (sum == 0) {
            totalArr.push([...subarr]);
            return;
        }
        return;
    }    
    // Include the current element and proceed
    subarr.push(arr[index]);
    combinationSum2(arr, index + 1, sum - arr[index], subarr, totalArr);
    subarr.pop();    
    // Exclude the current element and skip all duplicates
    while (index + 1 < arr.length && arr[index] == arr[index + 1]) {
        index++;
    }
    combinationSum2(arr, index + 1, sum, subarr, totalArr);
}

function combinationSum(arr, sum) {
    arr.sort((a, b) => a - b);
    let totalArr = [];
    combinationSum2(arr, 0, sum, [], totalArr);
    return totalArr;
}

let arr = [10, 1, 2, 7, 6, 1, 5];
let sum = 7;
let totalArr = combinationSum(arr, sum);
console.log(totalArr);



    


