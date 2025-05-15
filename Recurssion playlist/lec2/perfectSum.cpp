#include<iostream>
using namespace std;

class Solution{

	public:
	int perfectSum(int arr[], int n, int sum)
	{
        if(n<=0){
            return (sum==0)?1:0;
        }
        if(sum<0)
        {
            return 0;
        }
        int count=0;
        count=perfectSum(arr,n-1,sum-arr[n-1])+perfectSum(arr,n-1,sum);       
        return count;
    }	  
    // another method
    int perfectSum2(int arr[], int n, int sum)
	{
        if(n<=0){
            return (sum==0)?1:0;
        }
        if(sum<0)
        {
            return 0;
        }
        int count=0;
        if(arr[n-1]<=sum){
            count+=perfectSum2(arr,n-1,sum-arr[n-1]);
        }
        count+=perfectSum2(arr,n-1,sum);       
        return count;
    }
    // using bit manipulation 
        int perfectSum3(int arr[], int n, int sum) {
        int count = 0;
        int numSubsets = 1 << n; // 2^n possible subsets
        
        for (int mask = 0; mask < numSubsets; ++mask) {
            int subsetSum = 0;
            for (int i = 0; i < n; ++i) {
                if (mask & (1 << i)) { // Check if i-th element is included
                    subsetSum += arr[i];
                }
            }
            if (subsetSum == sum) {
                ++count;
            }
        }
        return count;
    }
};


int main(){
    Solution s;
    int arr[]={1,3,5,2};
    cout<<s.perfectSum(arr,4,3)<<endl;
    return 0;
}