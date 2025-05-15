#include<bits/stdc++.h>
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


int main(){
int arr[]= {4,6,7,8};
int k=15;
int n=4;
cout<<countNoOfSubarraysWithSumLessEqualThanK(arr,n,k)-countNoOfSubarraysWithSumLessEqualThanK(arr,n,k-1);
return 0;
}