#include <iostream>
using namespace std;

int countNoOfSubarraysWithSumLessEqualThanK(int arr[], int n, int k) {
    int count = 0;
    int sum = 0;
    int l = 0,r=0;

    while(r<n){
        sum += arr[r];
        while (sum > k && l <= r) {
            sum -= arr[l];
            l++;
        }
         count += (r - l + 1);
        r+=1;
    }
    return count;
}


int main() {
    int arr[] = {1, 2, 3, 4}; // Example array
    int k = 5;                // Sum threshold
    int n = sizeof(arr) / sizeof(arr[0]); // Calculate the size of the array

    cout << countNoOfSubarraysWithSumLessEqualThanK(arr, n, k) << endl; // Output the result
    return 0;
}
