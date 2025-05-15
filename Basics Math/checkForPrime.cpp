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

// A number is prime if it have exjactly two factors 
bool isPrime(int num){
    if(num==1)return 0;
    int count=0;
    for (int i = 2; i*i<=num; i++)
    {
        if(num%i == 0)
        {
            count+=1;
        }        
    }
    return count==1?true:false;
}
int main()
{
//vector<int>arr={};
int num;
cin>>num;
cout<<isPrime(num)<<endl;
return 0;
}