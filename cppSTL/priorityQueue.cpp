#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<list>
using namespace std;
int main()
{
// It will return as front largets or smallest element 
// the following will return largest as front 

// Max Heap
priority_queue<int>pq;
pq.push(4);
pq.push(3);
pq.push(8);
pq.push(1);
cout<<pq.top()<<endl; // output 8

// Min Heap
priority_queue<int,vector<int>,greater<int>>pq1;
pq1.push(3);
pq1.push(5);
pq1.push(1);
pq1.push(7);
pq1.push(8);
pq1.push(9);
cout<<pq1.top()<<endl;// output 1

// Push and pop =O(logn) and top =O(1)
return 0;
}