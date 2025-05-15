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

// Space Complexity = O(Auxilary space(space to solve the problem for example stack space while recurssion)) + O(Input space(space that we need to store the input))
// C=a+b here to store c we use space that is called as Auxilary space and while storing a and b is called input space


// Two things in Recurssion
// first --> backtracking and non-backtracking part 
// second thing recurssion function type --> parametrized (f(sum+i,i-1)) or (f(sum+i,i+i)) and functional recursion(f(i-1)+i) or (f(i+1)+i)  here example is given assuming example summation of first n number

// parametrized way
void helper(int i, int sum){
    if (i<=0)
    {
        cout<<sum<<endl;
        return ;
    }
    helper(i-1,sum+i);
}
void sum(int n){
    helper(n,0);
}

// functional recursion

int helper2(int i){
    if(i<=0){
        return 0;
    }
    return i+helper2(i-1);
}
void sum2(int n){
    cout<<helper2(n)<<endl;
}
int main()
{
int n;
cin>>n;
sum(n);
sum2(n);
return 0;
}