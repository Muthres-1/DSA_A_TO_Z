#include<iostream>
using namespace std;

// In this we find peak assuming that before the starting array is -infinite and after completing the array also -infinite
int findPeak(int arr[],int length){
for(int i=0;i<length;i++){
    if((i==0 || arr[i]>arr[i-1]) && (i==length-1 || arr[i]>arr[i+1])){
        return i;
    }
}
return -1;
}

// Optimized form

int findPeakOptimized(int arr[],int length){
  if(length==1)return 0;
  if(arr[0]>arr[1])return 0;
  if(arr[length-1]>arr[length-2])return length-1;
  int left=1,right=length-2;
  while (left<=right)
  {
    int mid=left+(right-left)/2;
    if(arr[mid]>arr[mid-1] && arr[mid]> arr[mid+1]){
        return mid;
    }
    else if (arr[mid]>arr[mid-1]){
        left=mid+1;
    }
    else{
        right=mid-1;
    }    
  }
  return -1;  
}
int main()
{
int arr[]={1,2,3,4,5,6,7,8,5,1};
int length=10;
// cout<<findPeak(arr,length)<<endl;
// cout<<findPeakOptimized(arr,length)<<endl;
return 0;
}