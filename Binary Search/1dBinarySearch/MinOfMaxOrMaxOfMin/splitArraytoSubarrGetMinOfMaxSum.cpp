#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

// This problem is similar to the book allocation 

int canWeAllocate(vector<int>arr,int size,int length){
    int countStudents=1,lastTotalPage=0;
    for (int i = 0; i < length; i++) 
    {
        if(arr[i]+lastTotalPage<=size){
           lastTotalPage+=arr[i];
        }
        else{
            countStudents++;
            lastTotalPage=arr[i];
        }
    }
    return countStudents;
}
// This is Optimized Approach
int bookAllocationOptimized(vector<int>arr,int length,int students){
    if(students<1 || students>length)return -1;
    int max=*max_element(arr.begin(),arr.end());
    int total=accumulate(arr.begin(),arr.end(),0);    
    int low=max,high=total;
    int ans=INT_MAX;
    while (low<=high)
    {
        int mid= low+(high-low)/2;
        int allotedStudents=canWeAllocate(arr,mid,length);
        if (allotedStudents==students)
        {
            ans=min(ans,mid);
            high=mid-1;
        }
        else if(allotedStudents<students)// Not possible because we need to allocate only to exjact same equal to students
        {
            high=mid-1;// iss case me bhi not possible because we are checking with greater than not equal to 
        }else{
            low=mid+1;
        }
    }
    return low;
}

int splitArrayIntoSubArr(vector<int>arr,int k,int length){
 return bookAllocationOptimized(arr,length,k);
}
int main()
{
vector<int>arr={10,20,30,40};
int k;
cin>>k;
cout<<splitArrayIntoSubArr(arr,k,arr.size())<<endl;
return 0;
}