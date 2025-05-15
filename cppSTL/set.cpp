#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<list>
#include<set>
using namespace std;
int main()
{

    // this use tree
// It stored everything in sorted manner and unique and it takes O(log(n)) time to insert and remove ,find
set<int>s;
s.insert(1);// {1}
s.insert(1);// {1}
s.insert(4);// {1,4}
s.insert(4);// {1,4}
s.insert(2);// {1,2,4}
s.insert(8);// {1,2,4,8}

// Fucntionality of insert in vector can be used also,that only increase efficiency
// begin(),end(),rbegin(),rend(),size(),empty(),and swap() are same as those of above

// {1,2,3,4,5} lets assume s is 
auto it = s.find(3); // it will return an iterator which points to 3

 it = s.find(6); // because 6 is not in set so it will return s.end()

// In erase function we can give element as well iterator same as vector
s.erase(5); // erase 5  this will take logarithmic time 
cout<<s.count(1)<<endl; // output 1   , this count function counts that how many 1 are in s 

 it = s.lower_bound(2);
it= s.upper_bound(3);
// set have also lower_bound and upper_bound function also 

// In set everything hapening in logarithmic time complexity
return 0;
}

// 🔍 What Are They?
// Both lower_bound and upper_bound are functions used to perform binary search on sorted ranges (like vector, array, etc.).

// Function	Returns an iterator pointing to...
// lower_bound	The first element ≥ (greater than or equal to) val
// upper_bound	The first element > (strictly greater than) val

// ⚠️ The container must be sorted for correct results!

// 🔧 Syntax

// auto it = lower_bound(container.begin(), container.end(), value);
// auto it = upper_bound(container.begin(), container.end(), value);
// 🧠 Example

// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// int main() {
//     vector<int> arr = {10, 20, 20, 20, 30, 40, 50};  // sorted

//     auto lb = lower_bound(arr.begin(), arr.end(), 20);
//     auto ub = upper_bound(arr.begin(), arr.end(), 20);

//     cout << "lower_bound of 20: index = " << lb - arr.begin() << ", value = " << *lb << endl;
//     cout << "upper_bound of 20: index = " << ub - arr.begin() << ", value = " << *ub << endl;

//     return 0;
// }
// 🧾 Output:

// lower_bound of 20: index = 1, value = 20
// upper_bound of 20: index = 4, value = 30
// 📊 Visualization
// Index:     0   1   2   3   4   5   6
// Array:    [10, 20, 20, 20, 30, 40, 50]

// lower_bound(20) → index 1 → first ≥ 20
// upper_bound(20) → index 4 → first > 20
// 📦 Use Case: Count how many times 20 occurs

// int count = upper_bound(arr.begin(), arr.end(), 20) - lower_bound(arr.begin(), arr.end(), 20);
// cout << "20 occurs " << count << " times." << endl;
// ✅ Output: 20 occurs 3 times.

// 🔁 Summary
// Function	Returns iterator to...	Example (value = 20)
// lower_bound	First element ≥ value	index 1 (value 20)
// upper_bound	First element > value	index 4 (value 30)

