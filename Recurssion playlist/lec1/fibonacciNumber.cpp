#include<iostream>
using namespace std;

int f(int n){
    if(n<=1){
        return n;
    }
    return f(n-1) + f(n-2);
}
// The time complexity for this is O(2^n)


int main()  
{
int n;
cin>>n;
cout<<f(n)<<endl;
return 0;
}
