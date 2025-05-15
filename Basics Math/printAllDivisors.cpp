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
// Brute force way
void printAllDivisors(int num){
    for (int i = 1; i <= num; i++)
    {
        if(num%i==0)cout<<i<<" ";
    }
    cout<<endl;
}

// Optimized way
void printAllDivisorsOptimized(int num){
    for (int i = 1; i*i<=num; i++)
    {
        if(num%i == 0)
        {
            cout<<i<<" ";
            if(num/i != i)cout<<num/i<<" ";
        }
        
    }
    cout<<endl;   
}
int main()
{
//vector<int>arr={};
int num;
cin>>num;
printAllDivisors(num);
printAllDivisorsOptimized(num);
return 0;
}