// // bottom-up approach (tabulation) recursive way
// function tabulation(dp,i,n){
//     if(i<=1){
//         dp[i]=i;      
//     }
//     else{
//         dp[i]=dp[i-1]+dp[i-2]; 
//     }
//     if(i>n)return ;       
//     tabulation(dp,i+1,n);    
// }
// let n=12;
// let dp=[n+1];
// tabulation(dp,0,n);
// console.log(dp[n]);
// // time complexity O(n) and space complexity O(n)+O(n)
// // memoization recursive way
// function memoization(dp,n){
//     if(n<=1){
//         return dp[n]=n;
//     }
//     if(dp[n]!=-1)return dp[n];
//     else{
//     return dp[n]=memoization(dp,n-1)+memoization(dp,n-2);
//     }      
//     
// }
// console.log(memoization(dp,n));
// // without return anything 
// function memoization2(memo,n){
//     if(n<=1){
//         memo[n]=n;
//         return ;
//     }
//     else{
//        if(memo[n]!=-1)return ;
//        memoization2(memo,n-1)
//        memoization2(memo,n-2);
//        memo[n]=memo[n-1]+memo[n-2];
//        return ;
//     }
// }
// let memo=[n+1].fill(-1)
// memoization2(memo,n)
// console.log(memo[n]);
// time complexity O(n) and space complexity is O(n)+O(n)
// tabulation Optimization  
//   dp[0]= 0;
//   dp[1]= 1;  
//   for(i=2; i<=n; i++){
//       dp[i] = dp[i-1]+ dp[i-2];
//   }
//  console.log(dp[n]);
 // time complexity O(n) and space complexity O(n){only for used extra dp array not for used stack}
 
 // Optimal optimization
//  prev2 = 0;// keep remember prev2 and prev we defined first out of the loop if we define inside of loop then need of if condition
//  prev = 1; 
//  for(i=2; i<=n; i++){
//      cur_i = prev2+ prev;
//      prev2 = prev;
//      prev= cur_i;
//  }
//  console.log(cur_i);
 // recurssion Optimization
 function tabulation(prev,prev2,curr,i,n){
    if(i<=1){
        curr=i;
    }    
    else if(i<=n){curr=prev+prev2}
    if(i>n){
       return curr;
    }
    return tabulation(curr,prev,curr,i+1,n);
}

console.log(tabulation(0,0,0,0,n));

