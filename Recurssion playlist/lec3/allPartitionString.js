
// https://www.youtube.com/watch?v=dxFBNqt9_2o
// for this problem best video 
// starts tells us that we have partitioned upto start-1 index now we are going to decide that next 
// where we will do 
function partitionHelper(str, start, path, result) {
    if (start === str.length) {
        result.push([...path]);
        return;
    }  
// here what are we doing, we are partition of a string and left part of it is fixed mtlb that is fixed partition for that string and now we will look for right one from that index
    for (let end = start; end < str.length; end++) {
        let substr = str.substring(start, end + 1);
        path.push(substr);
        partitionHelper(str, end + 1, path, result);
        path.pop();
    }
}

function partition(str) {
    const result = [];
    partitionHelper(str, 0, [], result);
    return result;
}

// Example usage
let str = "GOLU ";
const partitions = partition(str);
console.log(partitions);





