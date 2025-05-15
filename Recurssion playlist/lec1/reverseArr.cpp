#include<iostream>
#include<string>
#include<vector>
using namespace std;

void swap(int i,int j,vector<int>&arr){
    int temp = arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
}
void helper(int i,int j,vector<int>&arr){
    if (i>=j)
    {
        return;
    }
    swap(i,j,arr);
    helper(i+1,j-1,arr);
}
void reverseArr(vector<int>&arr){
    helper(0,arr.size()-1,arr);
}

// We can do this via help of single variable i  as following 
// if(i>=n/2)return
// swap(i,n-1-i,arr);
// f(i+1,arr);

int main()
{
vector<int>arr={1,2,3,4,9,2,6};
reverseArr(arr);
for (auto it = arr.begin(); it != arr.end(); it++)
{
    cout<<*it<<" ";
}

return 0;
}