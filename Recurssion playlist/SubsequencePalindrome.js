function reverseHelper(str,left=0,right=str.length-1){
     if(left>=right){
        return ;
     }
     let temp=str[left];
     str[left]=str[right];
     str[right]=temp;
     reverseHelper(str,left+1,right-1)
}
function reverse(str) {
     let arr = str.split('');
     reverseHelper(arr)
     return arr.join('');
}
function isPalindrome(str){
    if(str===reverse(str)){
        return true;
    }
    else{
        return false;
    }
}
function allCombinationPalindrom(str,totalStr,subStr,index){
    if(index>=str.length){
        let subStrJoined=subStr.join('');
        if(isPalindrome(subStrJoined)){
            totalStr.push(subStrJoined);            
        }
        return ;
    }
    else{
        subStr.push(str[index]);
        allCombinationPalindrom(str,totalStr,subStr,index+1);
        subStr.pop();
        allCombinationPalindrom(str,totalStr,subStr,index+1);
    }
}
str="aab";
const totalStr=[];
allCombinationPalindrom(str,totalStr,[],0);
console.log(totalStr);





