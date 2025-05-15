#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<list>
using namespace std;
int main()
{
    // This follows FIFO
queue<int>q;
q.push(10); // {10}
q.push(45); // {10,45}
q.emplace(2); // {10,45,2}
cout<<q.front()<<endl;// 10
q.back()+=5;
cout<<q.back(); // 7
q.pop(); // 10 is removed 
// size swap empty are similar to stack
//  here all operations are happeniing in constant time 
return 0;
}


// ✅ STL stack
// By default, stack is implemented using a deque.

// 📦 Underlying container:

// template <class T, class Container = deque<T>>
// class stack;
// ✅ You can also use vector or list:

// stack<int, vector<int>> s1;  // using vector
// stack<int, list<int>> s2;    // using list
// 🔧 Operations:
// push(), pop(), top(), empty(), size()

// LIFO (Last In First Out)

// ✅ STL queue
// By default, queue is also implemented using a deque.

// 📦 Underlying container:

// template <class T, class Container = deque<T>>
// class queue;
// ✅ You can use list too:

// queue<int, list<int>> q;     // using list
// 🔧 Operations:
// push(), pop(), front(), back(), empty(), size()

// FIFO (First In First Out)

// 📌 Why deque is preferred by default?
// Supports fast insertions/removals at both ends.

// Efficient memory usage (better than list).

// Random access (though not used in stack/queue).

// ✅ Summary Table
// Adapter	Default Container	Other Allowed Containers	Access Pattern
// stack	deque	vector, list	LIFO
// queue	deque	list	FIFO