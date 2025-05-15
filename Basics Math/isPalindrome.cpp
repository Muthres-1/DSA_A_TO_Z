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

bool isPalindrome(int num){
int a=num;
int revNum=0;
while (num!=0)
{
    int remainder=num%10;
    revNum=(revNum*10) + remainder;
    num/=10;
}
return a==revNum?true:false;
}
int main()
{
//vector<int>arr={};
int num;
cin>>num;
cout<<isPalindrome(num)<<endl;
return 0;
}