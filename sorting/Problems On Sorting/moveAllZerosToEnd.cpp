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

// Brute force way
// Time complexity is O(2*n) and best case time complexity is O(n) and extra space complexity is O(n-k) where k is number of zeros in array
void moveAllZerosToEnd(vector<int>&arr,int length){
vector<int>temp;
int a=0;
for(auto it : arr){
    if(it!=0){
        temp.push_back(it);
        a++;
    }
}
if(!a){// when all elements are zeros
    return ;
}
for (int i = 0; i < length; i++)
{
    if (i<temp.size())
    {
        arr[i]=temp[i];
    }
    else{
        arr[i]=0;
    }
}

}

// Optimized way
// The time complexity is O(n) and extra space complexity is O(1)
void moveAllZerosToEndOptimized(vector<int>&arr,int length){
    int j=-1;
    for (int i = 0; i < length; i++)
    {
        if(arr[i]==0){
            j=i;
            break;
        }
    }
    for (int i = j+1; i < length; i++)
    {
        if (arr[i]!=0)
        {
            int temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
            j++;
        }   
    }        
}
int main()
{
vector<int>arr={0,1,2,0,2,0,3,4,0,7,8,4,0};
// vector<int>arr={0,0,0,0,0};
for(auto it : arr){
    cout<<it<<" ";
}
cout<<endl;
// moveAllZerosToEnd(arr,arr.size());
moveAllZerosToEndOptimized(arr,arr.size());
for(auto it: arr){
    cout<<it<<" ";
}
return 0;
}