#include<unordered_map>
#include<unordered_set>
#include<iostream>
#include<string>
#include<vector>
#include<math.h>
#include<stack>
#include<queue>
#include<list>
#include<set>
#include<map>
#include<bits/stdc++.h>
using namespace std;

 bool comp(pair<int,int>p1,pair<int,int>p2){
    if(p1.second<p2.second)return true;
    if(p1.second>p2.second)return false;
    // if second of both is same
    if(p1.first>p2.first)return true;
    return false;
 }
int main()
{
vector<int>arr={2,1,4,5,3,8,7};
sort(arr.begin(),arr.end());
// To sort  in cpp everything not just vector 
// here start is included and end is not included , here we can give a part of array also 
int a[]={3,4,1,7,5};
sort(a,a+4); // it will sort starting 4 elemetn 0 to 3 not include 4 in array a
cout<<a[0]<<endl; // output 1
for (int i = 0; i < 5; i++)
{
    cout<<a[i]<<" ";
}


// To sort in descending order 
sort(a,a+5,greater<int>()); // greater<int> is a inbuilt comparator who automatrically sort in descending order 

// In C++, a comparator is a function or a function object (also called a functor) that defines a custom way to compare two elements, typically used with STL containers like std::sort(), std::set, std::map, std::priority_queue, etc.

// 1. Basic Comparator as a Function
// bool compare(int a, int b) {
//     return a > b;  // Sort in descending order
// }

// std::sort(arr.begin(), arr.end(), compare);
// 2. Lambda Comparator
// Useful for inline, short comparisons:

// std::sort(arr.begin(), arr.end(), [](int a, int b) {
//     return a > b;
// });

// Now sorting in data structure like pair etc.. for them we provide a comparator as needed
 pair<int,int>ab[]={{1,2},{2,1},{4,1}}; //now if I want to sort it increasing second element but if second element is same then sort accordingly first element descending order then I need to provide a comparator for that

 sort(ab,ab+3,comp);// This comparator is nothing just an boolean function 
cout<<endl;
string s = "123";
do
{
    cout<<s<<endl;
} while (next_permutation(s.begin(),s.end()));

//   vector<int> v = {10, 20, 5, 30, 25};
// auto it = max_element(v.begin(), v.end());
// cout << "Max element is: " << *it << endl;  // Output: 30
vector<int> v = {10, 20, 5, 30, 25};
auto it = max_element(v.begin(), v.end());
cout << "Max element is: " << *it << endl;  // Output: 30
return 0;
}

// __builtin_popcount() is a GCC/Clang built-in function in C++ that returns the number of 1-bits (also called set bits) in the binary representation of an integer.

// ✅ Syntax:

// int __builtin_popcount(unsigned int x);
// 🧠 What It Does:
// Counts how many 1s are present in the binary form of the number.

// 🧾 Example:

// #include <iostream>
// using namespace std;

// int main() {
//     int x = 13;  // binary: 1101 → 3 set bits
//     cout << "__builtin_popcount(13): " << __builtin_popcount(x) << endl;
//     return 0;
// }
// ✅ Output:

// __builtin_popcount(13): 3
// 🧠 Related Built-ins:
// Function	Purpose
// __builtin_popcount(x)	Count set bits in 32-bit int
// __builtin_popcountll(x)	Count set bits in 64-bit long long
// __builtin_clz(x)	Count leading zeros (from MSB side)
// __builtin_ctz(x)	Count trailing zeros (from LSB side)

// 📦 Use Cases:
// Bitmasking problems

// Hamming weight

// Subset generation

// Fast combinatorics



// A set bit is any bit in a binary number that is equal to 1.

// 🧠 In Simple Terms:
// Binary numbers are made up of 0s and 1s.
// Whenever a bit is 1, we say that bit is "set".