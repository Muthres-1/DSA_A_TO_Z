// function allPermutation(arr,subarr,totalArr,freq){
//     if(arr.length==subarr.length){
//         totalArr.push([...subarr]);
//         return ;
//     }    
//     else{
//         for(let i=0;i<arr.length;i++){
//             if(!freq[i]){
//                 subarr.push(arr[i]);
//                 freq[i]=true;
//                  allPermutation(arr,subarr,totalArr,freq);
//                  subarr.pop();
//                  freq[i]=false;
//             }
//         }
//     }
// }
// arr=[1,2,3];
// totalArr=[];
// freq=new Array(arr.length).fill(false);
// allPermutation(arr,[],totalArr,freq);
// console.log(totalArr);

// Approach 2-

// here index stands in permutation we fixed until index - 1 position & now we are going to fix index position of permutation
function allPermutation(arr,index,totalArr){
    if(index>=arr.length){
        totalArr.push([...arr]);
        return ;
    }
    else{
        for(let i=index;i<arr.length;i++){
            // taken
            let temp=arr[i];
            arr[i]=arr[index];
            arr[index]=temp;
            allPermutation(arr,index+1,totalArr);
            // not taken
            temp=arr[i];
            arr[i]=arr[index];
            arr[index]=temp;
        }
    }
}
arr=[1,2,3];
const totalArr=[];
allPermutation(arr,0,totalArr);
console.log(totalArr);
