#include<iostream>
#include<vector>
#include<list>
using namespace std;
int main()
{
// List is similar to vector but it also give front opertion 
// doubly linklist is maintained for list and singly linklist is maintained for vector
// so here adding fron is very very cheap comparitive to vector
// all functions are similar to vector like begin,end,rbegin,rend,clear,insert,size,swap
list<int>ls;
ls.push_back(2); //{2}
ls.push_back(3); //{2,3}
ls.push_back(4); //{2,3,4}
ls.push_front(5);// {5,2,3,4}
ls.emplace_back(8);
ls.emplace_front(9);
ls.push_front(0);
for (auto it = ls.begin(); it != ls.end(); it++)
{
    cout<<*it<<" ";
}

// The push_front is very very cheaply(time complexity wise) than vector 
// All are function are similar to vector
// Vector is sinlgy list and list use doubly link list
return 0;
}