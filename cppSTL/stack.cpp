#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<list>
using namespace std;
int main()
{
stack<int>st;
// LIFO

// here operation happen in O(1) --> push,pop,top,emplace
st.push(1);
st.pop();
st.push(3);// {3}
st.push(5);// {5,3}
st.emplace(9); // {9,5,3}
cout<<st.top()<<endl;
cout<<st.empty()<<endl; // output false
cout<<st.size()<<endl; // output 3
stack<int>st2,st3;
st2.push(1);
st2.push(6);
st2.push(3);
st3.swap(st2);


return 0;
}