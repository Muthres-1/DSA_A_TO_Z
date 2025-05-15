// the combination sum problem is that we can pick any element any times and we want all subsets 
// whose elements's summation is equal to sum

function allCombination(arr,index,sum,subarr,totalarr)
{ 
    if(index==arr.length){
        if(sum==0){
            totalarr.push([...subarr]);
            return ;
        }
    }
    else{
       
        if(sum>=arr[index]){
            subarr.push(arr[index]);
            allCombination(arr,index,sum-arr[index],subarr,totalarr);
            subarr.pop();
            allCombination(arr,index+1,sum,subarr,totalarr);
        }
        else{
            allCombination(arr,index+1,sum,subarr,totalarr);
        }
    }
}
arr=[1,2,5];
sum =5
totalarr=[];
allCombination(arr,0,sum,[],totalarr);
console.log(totalarr);


function allCombination1(arr,index,sum,subarr,totalarr)
{
    if(index==arr.length){
        if(sum==0){
            totalarr.push([...subarr]);
            return ;
        }
        else{
            return ;
        } 
    } 
    allCombination1(arr,index+1,sum,subarr,totalarr);  
    if(sum>=arr[index]){
        subarr.push(arr[index]);
        allCombination1(arr,index,sum-arr[index],subarr,totalarr);
        subarr.pop()
    }          
    
}
arr=[1,2,5];
sum =5
totalarr=[];
allCombination1(arr,0,sum,[],totalarr);
console.log(totalarr);