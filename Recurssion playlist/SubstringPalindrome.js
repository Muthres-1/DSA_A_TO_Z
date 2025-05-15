function isPalindrome(str){
    left=0;
    right=str.length-1;
    while(left<right){
        if(str[left]!==str[right]){
            return false;
        }
        left++;
        right--;
    }
    return true;
}

function findPalindromepartion(str,index,path,result){
if(index==str.length){

}
}function isPalindrome(str) {
    let left = 0;
    let right = str.length - 1;
    while (left < right) {
        if (str[left] !== str[right]) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

function findPalindromicPartitions(s, start, path, result) {
    if (start === s.length) {
        result.push([...path]);
        return;
    }

    for (let i = start; i < s.length; i++) {
        let substring = s.substring(start, i + 1);
        if (isPalindrome(substring)) {
            path.push(substring);
            findPalindromicPartitions(s, i + 1, path, result);
            path.pop();
        }
    }
}

function partition(s) {
    const result = [];
    findPalindromicPartitions(s, 0, [], result);
    return result;
}


const s1 = "aab";
const s2 = "a";
console.log(partition(s1)); // Output: [["a","a","b"],["aa","b"]]
console.log(partition(s2)); // Output: [["a"]]

function partition(s){
result=[];
findPalindromepartion(s,0,[],result);
return result;
}