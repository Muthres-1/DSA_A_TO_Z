function wordBreak(start,str,ans,i){
    if(start==str.length){

        return i==ans.length;
    } 
    if(i>=ans.length){
        return true;
    }
    for(let end =start;end<str.length;end++){
        let s=str.substring(start,end+1);
        if(s===ans[i]){
            i+=1;
        }
        if(wordBreak(end+1,str,ans,i))return true;
    }
    return false;
}
let str = "leetcode", ans = ["leet","code"];
console.log(wordBreak(0,str,ans,0));

// in above should be but actually the answer is looking such kind of question that 
// in wordDict have its partition or not (here not need to store all partition)

// function partitionSearch(s,index,set){
//     if(index==s.length){
//       return true;
//     }
//     for(let i=index;i<s.length;i++){
//         let substr=s.substring(index,i+1);
//         if(set.has(substr)){
//            if(partitionSearch(s,i+1,set))return true;
//         }
//     }
//     return false;
// }
// let s = "leetcode", wordDict = ["leet","code"]
// const set =new Set(wordDict);// conert wordDict for O(1) lookup
// console.log(partitionSearch(s,0,set));

// Optimize solution
// here memo is storing in that perticular string's 0 to index up to partion present in wordDict or not
// function dpSolution(s,index,set,memo={}){
//     if(index==s.length){
//         return true; // we reach doing partition up to index= s.length-1 and all exist inside of wordDict
//     }
//     if(index in memo){
//         return memo[index];
//     }
//     for(let i=index;i<s.length;i++){
//         let str=s.substring(index,i+1);
//         if(set.has(str)){
//             if(dpSolution(s,i+1,set,memo)){
//                 memo[index]=true;
//                 return true;
//             }
//         }
//     }
//     memo[index]=false;
//     return false;
// }
// let s = "leetcode", wordDict = ["leet","code"]
// const set =new Set(wordDict);// conert wordDict for O(1) lookup
// console.log(dpSolution(s,0,set));
