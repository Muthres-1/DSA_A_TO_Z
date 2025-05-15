#include<unordered_map>
#include<unordered_set>
#include<iostream>
#include<string>
#include<vector>
#include<math.h>
#include<stack>
#include<queue>
#include<list>
#include<set>
#include<map>
#include<bits/stdc++.h>
using namespace std;
int main()
{
int n=2;
cout<<__builtin_popcount(n)<<endl; // this function return set bits in binary repesentation of any number 

// If number is long long then this function become __builtin_popcountll()
long long num=1234544342544253;
cout<<__builtin_popcountll(num)<<endl;

// next_permutations :- this function return premutations according dictionary order 
string s="123";
do
{
    cout<<s<<endl;
} while (next_permutation(s.begin(),s.end()));

// max element in more than 2
int a[]={3,2,4,1,5,7,8,9};
int maxi=*max_element(a,a+8); // don't forget to use * at the starting of the function  
cout<<maxi<<endl;
int mini=*min_element(a,a+8); // don't forget to use * at the starting of the function  
cout<<mini<<endl;
return 0;
}