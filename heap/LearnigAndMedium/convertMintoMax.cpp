#include<iostream>
#include<vector>
using namespace std;
// there are two solution to conversion 
// 1. to using another array (easy)
// 2. without using another array just convert that array
class Solution{
public:
    void swap(vector<int>&arr,int a,int b){
        int temp=arr[a];
        arr[a]=arr[b];
        arr[b]=temp;
    }
    void heapyDown(vector<int>&arr,int i,int N){
        int maxi=i;
        int left=2*i+1;
        int right=2*i+2;
        if(left<N && arr[left]>arr[maxi]){
            maxi=left;
        }
        if(right<N && arr[right]>arr[maxi]){
            maxi=right;
        }
        if(maxi!=i){
            swap(arr,i,maxi);
            heapyDown(arr,maxi,N);
        }
    }
    void convertMinToMaxHeap(vector<int> &arr, int N){
        for(int i=(N-1)/2;i>=0;i--){
            heapyDown(arr,i,N);
        }
    }
    
};
