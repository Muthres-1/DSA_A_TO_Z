#include<unordered_map>
#include<unordered_set>
#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
#include<math.h>
#include<stack>
#include<queue>
#include<list>
#include<set>
#include<map>
using namespace std;

// Problem type 1 
// given row and col number and want output of that position 
// the element at give row and col is (row-1)C(col-1)
// The time complexity is O(r) and space complexity is O(1)
long long findNCR(int N,int R){
    long long ans = 1;
    for (int i = 0; i < R; i++)
    {
        // ans*=(N-i)/(i+1); // This will give wrong answer
        ans*=(N-i);
        ans/=(i+1);
    }
    return ans;   
}

// 2nd type of Problem
// Print any row
// the time complexity is O(N*R) and space compelxity is O(N)
vector<int> findRow(int row){
    vector<int>ans;
    for (int col = 0; col < row; col++)
    {
        ans.push_back(findNCR(row-1,col));
    }
    return ans;
}

// Optimized of 2nd type of problem 
// Time complexity is O(N) and space complexity is O(1)
vector<int> findRowOptimized(int row){
    int ansEle = 1;
    vector<int>ans;
    ans.push_back(1); // push first element
    for (int col = 1; col < row; col++)
    {
        ansEle*=(row-col);
        ansEle/=col;
        ans.push_back(ansEle);
    }
    return ans;
}

// 3rd type of problem 
// give the whole pascal triangle in which no need to print space just give all rows 
// Brute force way 
// Time complexity is O(n^2) and space complexity is also O(n^2)
vector<vector<int>> findPascalTriangle(int maxRow){
    vector<vector<int>>ans;
    for (int i = 1; i <= maxRow; i++)
    {
        ans.push_back(findRowOptimized(i));
    }
    return ans;
}
int main()
{
//vector<int>arr={};
int row = 6;
int col = 4;
cout<<findNCR(row-1,col-1)<<endl;
// vector<int>ans = findRow(row);
vector<int>ans = findRowOptimized(row);
for(auto it : ans){
    cout<<it<<" ";
}
cout<<endl;

vector<vector<int>>PascalTriangle=findPascalTriangle(row);
cout<<endl<<"The pascal triangle"<<endl;
for(auto it : PascalTriangle){
    for(auto it2 : it){
        cout<<it2<<" ";
    }
    cout<<endl;
}
return 0;
}