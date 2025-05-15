
// This is combination sum3 problem
function getPermutation(n,k){
    let arr=[];
    let factorial=1;
    for(let i=1;i<n;i++){
        factorial*=i;
        arr.push(i);
    }
    arr.push(n);
    k-=1;
    let ans="";
    while(true){
        ans+=String(arr[Math.floor(k/factorial)]);
        arr.splice(Math.floor(k/factorial),1);
        if(arr.length==0){
            break;
        }
        k=k%factorial;
        factorial=factorial/arr.length;        
    }
    return ans;
}