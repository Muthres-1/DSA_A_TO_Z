function printSubsequences(arr, index, subarr,totalSubbarr) {   
    if (index >= arr.length) {        
           totalSubarr.push([...subarr]); // here spread process make a copy of subarr
    } else {
        // Pick the current index into the subsequence
        subarr.push(arr[index]);
        printSubsequences(arr, index + 1, subarr,totalSubbarr);
        // Not picking the element into the subsequence
        subarr.pop();
        printSubsequences(arr, index + 1, subarr,totalSubbarr);
    }
}
let arr = [1, 2, 3]; 
totalSubarr=new Array();
printSubsequences(arr, 0, [],totalSubarr);
console.log(totalSubarr);

// totalSubarr.push([...subarr]); // here spread process make a copy of subarr
// This is the spread operator, and it copies the elements of subarr into a new array.

// Example:

// let a = [1, 2];
// let b = [...a]; // creates a new array with same contents
// Why use it here?
// Java Script me pointer and variable ka working thoda c and cpp se different h agar hum 
// kisi variable ko function me pass karte h to uska new copy nhi create hota while vo same 
// ek different object hota h but point ussi address ko karta h
// Because subarr is reused in recursion (modified via .push() and .pop()), if you just did:

// totalSubarr.push(subarr);
// then all entries in totalSubarr would point to the same reference, which changes over time — so you'd end up with wrong/mutated results.
        

// In JavaScript, arrays are dynamic. When you push elements into an array, the array 
// can grow as needed. This means you can start with an empty 
// array (like totalSubarr = []), and as you recursively generate subsequences, 
// you can push those subsequences into totalSubarr — and it will automatically become a 2D array.


// #include <iostream>
// #include <vector>
// using namespace std;

// // Function to generate all subsequences
// void printSubsequences(vector<int>& arr, int index, vector<int>& subarr, vector<vector<int>>& totalSubarr) {
//     if (index >= arr.size()) {
//         // When we reach the end of the array, add the current subsequence to the result
//         totalSubarr.push_back(subarr);  // Add the subsequence (subarr) to the 2D vector
//         return;
//     }

//     // Include the current element in the subsequence
//     subarr.push_back(arr[index]);
//     // Move to the next index
//     printSubsequences(arr, index + 1, subarr, totalSubarr);

//     // Exclude the current element from the subsequence
//     subarr.pop_back();  // Remove the last element
//     // Move to the next index
//     printSubsequences(arr, index + 1, subarr, totalSubarr);
// }

// int main() {
//     vector<int> arr = {1, 2, 3};
//     vector<vector<int>> totalSubarr;  // 2D vector to store subsequences
//     vector<int> subarr;  // Temporary array to store the current subsequence

//     printSubsequences(arr, 0, subarr, totalSubarr);

//     // Print all subsequences
//     for (const auto& subseq : totalSubarr) {
//         for (int num : subseq) {
//             cout << num << " ";
//         }
//         cout << endl;
//     }

//     return 0;
// }


// 1. JavaScript Variable Handling
// In JavaScript, the behavior of passing variables to functions depends on whether the variable is a primitive value or a reference type (like objects or arrays).

// Primitive Types (Pass by Value)
// Primitive types in JavaScript include number, string, boolean, undefined, null, symbol, and bigint. When you pass a primitive value to a function, its value is copied (i.e., pass-by-value).

// Example:


// function modifyValue(x) {
//     x = 10;  // x is modified, but it won't affect the original value
// }

// let a = 5;
// modifyValue(a);
// console.log(a);  // Output: 5 (The original value remains unchanged)
// Here, a is passed by value, meaning that x in the function gets a copy of a. Any modifications to x do not affect the original a.

// Reference Types (Pass by Reference)
// Objects, arrays, and functions in JavaScript are passed by reference. This means that if you pass a reference type (an object or array) to a function, the function receives a reference to the same object, and any changes made within the function will affect the original object.

// Example:

// function modifyObject(obj) {
//     obj.name = 'Alice';  // Modifies the original object
// }

// let person = { name: 'Bob' };
// modifyObject(person);
// console.log(person.name);  // Output: Alice (The original object is modified)
// Here, person is passed by reference, so the object obj inside the function points to the same memory address as person. Modifying obj modifies person as well.