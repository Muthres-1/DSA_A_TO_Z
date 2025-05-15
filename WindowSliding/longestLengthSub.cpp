#include <iostream>
using namespace std;
// Longest subarray whose sum<=k and return the maximum length
// Brute Force Approach 
int longestSubarray(int arr[], int n, int k) {
    int maxlen = 0;
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            sum += arr[j];
            if (sum <= k) {
                maxlen = max(maxlen, j - i + 1);
            } else {
                break; // Early exit since adding more will only increase the sum
            }
        }
    }
    return maxlen;
}

// Optimize Solution 

int BetterSolution(int arr[],int n,int k){
    int maxlen=0;
    int l=0,r=0;
    int sum=0;
    while(r<n){
        sum+=arr[r];
        while(sum>k){
                sum-=arr[l];
                l++;
            }
        if(sum<=k){
            maxlen=max(maxlen,r-l+1);
            r++;
        }
        
    }
    return maxlen;
}
// Further more optimization 

int Optimize(int arr[],int n,int k){
    int maxlen=0;
    int l=0,r=0;
    int sum=0;
    while(r<n){
        sum+=arr[r];
        if(sum>k){
                sum-=arr[l];
                l++;
            }
        if(sum<=k){ 
            maxlen=max(maxlen,r-l+1);
        }
        r++;
        
    }
    return maxlen;
}

int main() {
    int arr[] = {1, 1,2, 3, 5};
    int k = 5;
    int n = sizeof(arr) / sizeof(arr[0]); // Calculate the size of the array
    cout << longestSubarray(arr, n, k) << endl;
    cout << BetterSolution(arr, n, k) << endl;
    cout << Optimize(arr, n, k) << endl;
    return 0;
}
