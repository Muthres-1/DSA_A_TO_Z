// function subStrlst(str,result){    
//     result.push(" ");
//     for(let i=0;i<str.length;i++){
//         for(let j=i;j<str.length;j++){
//             let s=str.substring(i,j+1);
//             result.push(s);
//         }
        
//     }
// }

// function subStrlstHelper(str, end, result,countObj) {
//     if (end >= str.length) {
//         return;
//     }
//     // here for recursion we remove inner loop not outer loop
//     for(let i=0;i<=end;i++){
//         let s=str.substring(i,end+1);
//         countObj.count++;
//         result.push(s);              
//     }      
//     subStrlstHelper(str,end+1,result,countObj);
// }
function subStrlstHelper(str, start, result,countObj) {
    if (start >= str.length) {
        return;
    }
    // here for recursion we remove outer loop not inner loop
    for (let end = start; end < str.length; end++) {
        let s = str.substring(start, end + 1);
        countObj.count++;
        result.push(s);
    }
    subStrlstHelper(str, start + 1, result,countObj);
}

function subStrlst(str, result,countObj) {
    result.push(" ");
    subStrlstHelper(str, 0, result,countObj);
}
str="muthres";
const result =[];
let countObj={count:0};
subStrlst(str,result,countObj);
console.log(result);
console.log(countObj.count);