#include<iostream>
using namespace std;
int maxPoints(int arr[],int k,int n){
    int sum=0,maxSum=0,l=k-1,r=n-1;
    for(int i=0;i<k;i++){
        sum+=arr[i];
    }
    maxSum=sum;
    while(l>=0){
        sum-=arr[l];
        l--;
        sum+=arr[r];
        r--;
        maxSum=max(maxSum,sum);
    }
    return maxSum;
}
int main() {
    int arr[] = {6,2,3,4,7,2,1,7,1}; // Example array
    int k = 4;                // Sum threshold
    int n = sizeof(arr) / sizeof(arr[0]); // Calculate the size of the array

    cout << maxPoints(arr, k, n) << endl; // Output the result
    return 0;
}