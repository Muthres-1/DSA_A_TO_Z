// function climbing(n,index){
//     // base case
//     if(index==n){
//         return 1;
//     }
//     if(index>n)return 0; 
//     let m=0;  
//    if(index+1<=n){
//     m=climbing(n,index+1);
//    }
//    if(index+2<=n){
//     m+=climbing(n,index+2);
//    }
//    return m;
// }
// let n=3;
// console.log(climbing(n,0));
// n=2
// console.log(climbing(n,0));

// dp based solution 
// dp[index] telling the total number of way to reach nth stairs from zeroTh stairs.
// this problem exjactly same as well fibonacci problem 
// function climbing(tabu,n,index){
//     if(index==n){
//         return 1;
//     }
//     if(index>n)return 0; 
//     if(tabu[index]!=-1)return tabu[index];
//     if(index+1<=n){
//         tabu[index]=climbing(tabu,n,index+1);
//        }
//        if(index+2<=n){
//         tabu[index]+=climbing(tabu,n,index+2);
//        }
//     return tabu[index];
// }
// let n=3;
// let tabu=new Array(n+1).fill(-1);
// console.log(climbing(tabu,n,0));
// For to store in dp[index] from zero to that index up to require way given following code

function climbing(memo,n,index){
if(index==0){
    return 1;
}
if(index<0)return 0;
if(memo[index]!=-1)return memo[index];
memo[index]=climbing(memo,n,index-1);
memo[index]+=climbing(memo,n,index-2);
return memo[index];
}
let n=2;
let memo=new Array(n+1).fill(-1);
console.log(climbing(memo,n,n));

