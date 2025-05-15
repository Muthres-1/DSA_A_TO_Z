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
// Time complexity is O(n) and extra space complexity is O(1)
void leftRotationByOne(vector<int>&arr,int length){
int previous=arr[0];
for(int i=length-1;i>=0;i--){
int curr=arr[i];
arr[i]=previous;
previous=curr;
}
}
 
// right rotate by One time complexity is O(n) and space complexity is O(1)
void rightRotationByOne(vector<int>&arr,int length){
int previous=arr[length-1];
for(int i=0;i<length;i++){
int curr=arr[i];
arr[i]=previous;
previous=curr;
}

}
int main()
{
vector<int>arr={1,2,3,4,5,6};
int length=arr.size();
for(auto it : arr){
    cout<<it<<" ";
}
cout<<endl;
leftRotationByOne(arr,length);
for(auto it : arr){
    cout<<it<<" ";
}
cout<<endl;
rightRotationByOne(arr,length);
for(auto it : arr){
    cout<<it<<" ";
}
cout<<endl;
return 0;
}