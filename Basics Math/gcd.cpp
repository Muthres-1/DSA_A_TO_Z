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

// Brute force approach
// 1st approach
// Greatest Common divisor
int gcd(int num1,int num2){
int num=num1>num2?num2:num1;
int gcd=1;
for (int i = 1; i <= num; i++)
{
    if (num1%i == 0 && num2%i == 0)
    {
        gcd=i;
    }
    
}
return gcd;
}

// 2nd approach
int gcdOptimized(int num1,int num2){
int num=num1>num2?num2:num1;
for (int i = num; i >=1; i--)
{
    if (num1%i == 0 && num2%i == 0)
    {
        return i;
    }
    
}
return -1;
}

// Euclidean Algorithm
// gcd(n1,n2)=gcd(n1-n2,n2) where n1>n2
int EuclideanAlgo(int num1,int num2){
while (num1>0 && num2>0)
{
    if(num1>num2){
        num1=num1-num2;
    }else{
        num2-=num1;
    }
}
if(num1==0)return num2;
else return num1;
}
int EuclideanAlgoOptimized(int num1,int num2){
while (num1>0 && num2>0)
{
    if(num1>num2){
        num1%=num2;
    }else{
        num2%=num1;
    }
}
if(num1==0)return num2;
else return num1;
}
// The time complexity is reduced to O(loga(min(b,c))) ,a is not fix because everytime we are changing a and b
int main()
{
//vector<int>arr={};
int num1,num2;
cin>>num1>>num2;
cout<<gcd(num1,num2)<<endl;
cout<<gcdOptimized(num1,num2)<<endl;
cout<<EuclideanAlgo(num1,num2)<<endl;
cout<<EuclideanAlgoOptimized(num1,num2)<<endl;
return 0;
}