function findsum(subarr)
{
    total=0;
    for(let x in subarr){
        total+=subarr[x];
    }
    return total;
}
function isSubsetPresent(arr,index,subarr,sum)
{
    if(index==arr.length)
        {
           if(findsum(subarr,sum)){
             return true;
           }            
        }
    else{
        subarr.push(arr[index])
        let include = isSubsetPresent(arr,index+1,subarr,sum)
        subarr.pop();
        let exclude = isSubsetPresent(arr,index+1,subarr,sum);
        return include|| exclude;
    }
}
function isSubsetPresent2(arr,index,subarr,sum)
{
    if(index==arr.length)
        {
           if(findsum(subarr,sum)){
             return true;
           }            
        }
    else{
        subarr.push(arr[index])
        let include = isSubsetPresent(arr,index+1,subarr,sum)
        if(include == true)return true;
        subarr.pop();
        let exclude = isSubsetPresent(arr,index+1,subarr,sum);
        if(exclude==true)return true;
        return false;
    }
}


arr=[1,3,45,556,787,3];

sum=3;

a=isSubsetPresent(arr,0,[],sum);
if(a){
    console.log("Sum of subsequence",sum," is available ");
}
else{
    console.log("Sum of any subsequence is not available");
}
a=isSubsetPresent2(arr,0,[],sum);
if(a){
    console.log("Sum of subsequence",sum," is available ");
}
else{
    console.log("Sum of any subsequence is not available");
}



// ✅ Main Difference:
// isSubsetPresent:

// return include || exclude;
// This expression evaluates both recursive branches regardless of whether include is already true.

// So, it does not short-circuit early, even if one successful subset is found.

// isSubsetPresent2:

// if (include == true) return true;
// // ...
// if (exclude == true) return true;
// This version returns early as soon as a matching subset is found.

// It avoids unnecessary recursion in many cases, especially when a valid subset appears early.

// 💡 Why is isSubsetPresent2 more efficient?
// Even though both explore the subset tree (O(2ⁿ)), isSubsetPresent2 can terminate early when the desired subset is found, reducing the actual number of function calls in the best or average case.

// This is known as short-circuiting.

// ⏱️ Time Complexity
// Function	Time Complexity	Optimization
// isSubsetPresent	O(2ⁿ)	No early termination
// isSubsetPresent2	O(2ⁿ)	Early termination in best/avg case

