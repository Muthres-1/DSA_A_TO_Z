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

bool isArmstrong(int num){
int a=num;
int sum=0;
while (num!=0)
{
    int remainder=num%10;
    sum+=remainder*remainder*remainder;
    num/=10;
}
return a==sum?true:false;
}
int main()
{
//vector<int>arr={};
int num;
cin>>num;
cout<<isArmstrong(num)<<endl;
return 0;
}