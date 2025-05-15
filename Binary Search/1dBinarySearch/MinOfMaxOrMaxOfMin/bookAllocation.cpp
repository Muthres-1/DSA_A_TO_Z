#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
// This is kind of min of Max question 
// And also in question given that we need to allocate all books to students,neither more students and nor less students
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
// This is Brute force approach 
int bookAllocation(vector<int>arr,int length,int students){ 
    if(students<1 || students>length)return -1;
    int max=*max_element(arr.begin(),arr.end());// because everyOne should get at least one book according to given condition
    int total=accumulate(arr.begin(),arr.end(),0);    
    int low=max,high=total;
    for(int i=max;i<=total;i++){
        if(canWeAllocate(arr,i,length)==students){
            return i;
        }
    }
    return -1;
}
// This is Optimized Approach
// In this code my doubt is that when we do canWeAllocate(arr,mid,length)==students low =mid-1 in that case this gives wrong answer
// because it miss to allocate the last book and then shows the answer , so how it is giving here correct answer 
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

int main()
{
vector<int>arr={25,46,28,49,24};
int students;
cin>>students;
cout<<bookAllocation(arr,arr.size(),students)<<endl;
cout<<bookAllocationOptimized(arr,arr.size(),students)<<endl;
return 0;
} 