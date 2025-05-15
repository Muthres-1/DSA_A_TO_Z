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
int main()
{
//vector<int>arr={};
int num;
cin>>num;

// Another method
cout<<int(abs(log10(double(num)))+1)<<endl;

// Method 1
int count=0;
while (num!=0)
{
    count++;
    num/=10;
}
cout<<count<<endl;

// The time complexity in both cases is O(log10(n))
return 0;
}