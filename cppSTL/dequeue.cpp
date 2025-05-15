#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int main()
{
    // This is similar as vector and list all functions are similar to vector and list l
deque<int>dq;
dq.push_back(3);// {3}
dq.emplace_back(2); // {3,2}
cout<<dq.front()<<endl;
dq.push_front(4); //{4,3,2}
dq.emplace_front(8); //{8,4,3,2}
dq.pop_back(); //{8,4,3}
dq.pop_front(); // {4,3}
cout<<dq.back()<<endl;
cout<<dq.front()<<endl;
return 0;
}

// In C++, both deque and list are sequence containers from the STL, but they have different underlying data structures, performance characteristics, and use cases.

// 🔍 1. Underlying Structure
// Container	Internal Structure
// deque	Dynamic array of fixed-size arrays (double-ended queue)
// list	Doubly linked list

// ⚡ 2. Time Complexity Comparison
// Operation	deque	list
// Random access ([i])	✅ O(1)	❌ O(n)
// Push/Pop at ends	✅ O(1)	✅ O(1)
// Insertion/Erase in middle	❌ O(n)	✅ O(1) (with iterator)
// Memory locality	✅ Good (contiguous blocks)	❌ Poor (non-contiguous)

// 📌 3. When to Use Which?
// Use Case	Prefer deque when...	Prefer list when...
// Fast access by index	✅ Yes	❌ No
// Frequently insert/delete at both ends	✅ Yes	✅ Yes
// Need to insert/remove in the middle (with iterator)	❌ Costly	✅ Very fast (O(1))
// Memory overhead should be low	✅ Better cache performance	❌ Each node has extra pointer (memory overhead)

// 🧪 4. Code Example Comparison
// ✅ deque example:

// #include <deque>
// #include <iostream>
// using namespace std;

// int main() {
//     deque<int> dq = {1, 2, 3};
//     dq.push_front(0);  // fast
//     dq.push_back(4);   // fast
//     cout << dq[2] << endl;  // fast random access
// }
// ✅ list example:

// #include <list>
// #include <iostream>
// using namespace std;

// int main() {
//     list<int> lst = {1, 2, 3};
//     auto it = lst.begin();
//     advance(it, 1);
//     lst.insert(it, 99);  // fast insertion
//     for (int val : lst) cout << val << " ";
// }
// ✅ Summary Table
// Feature	deque	list
// Random access	✅ Yes	❌ No
// Fast insertion/removal	✅ Ends only	✅ Anywhere (with iterator)
// Memory layout	Contiguous blocks	Scattered (linked nodes)
// Performance in loops	Faster (better cache)	Slower (cache misses)

