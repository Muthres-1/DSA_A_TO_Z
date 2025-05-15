// function subset2(arr,totalArr,subarr,index){
//     if(index>=arr.length){
//         totalArr.push([...subarr]);
//         return ;
//     }
//     else{ 
//         // very very very very IMPORTANT MESSAGE
//         // Using var (or not using let or var): If you use var instead of let (or omit the declaration),
//         // i will be function-scoped. This means that all recursive calls to subset2 will share the same
//         //  i variable, leading to incorrect behavior as the value of i will be overwritten during each
//         // iteration of the loop.
//           for(let i=index;i<arr.length;i++){
//              if(arr[i]===arr[i-1] && i>index ){
//                 continue;
//             }
//             subarr.push(arr[i]);
//             subset2(arr,totalArr,subarr,i+1);
//             subarr.pop();
//             // here we will not write subset2 for not take bcz that will already come in next iteration of loop
           
//           }
//           subset2(arr,totalArr,subarr,arr.length);
//     }
// }
// function subSet(arr,totalArr){
//     arr.sort((a,b)=>a-b);
//     subset2(arr,totalArr,[],0);
// }
// arr=[1,2,2]
// totalArr=[];
// subSet(arr,totalArr);
// console.log(totalArr);


function combinationSum2(arr, index, subarr, totalArr) {    
    if ( index == arr.length) {
        totalArr.push([...subarr]);        
        return;
    }    
    // Include the current element and proceed
    subarr.push(arr[index]);
    combinationSum2(arr, index + 1, subarr, totalArr);
    subarr.pop();    
    // Exclude the current element and skip all duplicates
    while (index + 1 < arr.length && arr[index] == arr[index + 1]) {
        index++;
    }
    combinationSum2(arr, index + 1, subarr, totalArr);
}
function combinationSum(arr) {
    arr.sort((a, b) => a - b);
    let totalArr = [];
    combinationSum2(arr, 0, [], totalArr);
    return totalArr;
}

let arr = [10, 1, 2];
let totalArr = combinationSum(arr);
console.log(totalArr);



    



