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
while (num!=0)
{
    cout<<num%10<<" ";
    num/=10;
}

return 0;
}