#include<iostream>
#include<string>
#include<vector>
using namespace std;

void swap(int i,int j,string& arr){
    int temp = arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
}
void helper(int i,int j,string& arr){
    if (i>=j)
    {
        return;
    }
    swap(i,j,arr);
    helper(i+1,j-1,arr);
}
   

void reverseString(string& s){
helper(0,s.length()-1,s);
}
int main()
{
//vector<int>arr={};
string s;
cin>>s;
string a= s;
reverseString(a);
if(a==s){
    cout<<"String is Palindrome"<<endl;
}
else{
    cout<<"String is not Palindrome"<<endl;
}
return 0;
}


// we can use another approach in which we will compare i th element with n-1-i th element using recursion and if we get mismatch then we can comment as false 