#include <iostream>
using namespace std;

int LargestSum(int arr[], int n, int k) {
    int sum = 0;
    int LargestSum=0;
    int l = 0,r=k-1;
    for(int i=0;i<k;i++){
        sum+=arr[i];
    }
    LargestSum=sum;
    while(r<n-1){
        sum-=arr[l];
        l++;
        r++;
        sum+=arr[r];
        LargestSum=max(LargestSum,sum);
    }
    return LargestSum;
}

int main() {
    int arr[] = {1, 2, 3, 4}; // Example array
    int k = 2;                // Sum threshold
    int n = sizeof(arr) / sizeof(arr[0]); // Calculate the size of the array

    cout << LargestSum(arr, n, k) << endl; // Output the result
    return 0;
}
