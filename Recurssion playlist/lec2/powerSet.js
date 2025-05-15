function printSubsequences(arr, index, subarr,totalSubbarr) {   
    if (index === arr.length) {        
           totalSubbarr.push([...subarr]); 
        
    } else {
        // Pick the current index into the subsequence
        subarr.push(arr[index]);
        printSubsequences(arr, index + 1, subarr,totalSubbarr);

        // Not picking the element into the subsequence
        subarr.pop();
        printSubsequences(arr, index + 1, subarr,totalSubbarr);
    }
}
var subsets = function(nums) {
   totalSubbarr=[];
   printSubsequences(nums,0,[],totalSubbarr);
   return totalSubbarr; 
};