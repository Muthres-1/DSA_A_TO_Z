#include<iostream>
#include<vector>
using namespace std;

// Brute Force 
int longestOnes(vector<int>& nums,int k) {
int n=nums.size();
int maxLen=0;
for(int i=0;i<n;i++){
    int count=k;
    for(int j=i;j<n;j++){
        if(count==0 && nums[j]==0){
        maxLen=max(maxLen,j-i);
        break;
      }
      if(nums[j]==0){
        count--;
      }        
      maxLen=max(maxLen,j-i+1);  
    }
}
return maxLen;
}

// Optimization
int Optimized(vector<int>&nums,int k){
    int n=nums.size();
    int maxLen=0;
    int l=0,r=0;
    int count=k;
    while(r<n){ 
        if (nums[r] == 0) {
            count--;
        }
        while (count < 0) {
            if (nums[l] == 0) {
                count++; 
            }
            l++; 
        }
        maxLen = max(maxLen, r - l + 1);
        r++;
    }
return maxLen;
}
int MoreOptimized(vector<int>&nums,int k){
    int n=nums.size();
    int maxLen=0;
    int l=0,r=0;
    int count=k;
    while(r<n){ 
        if (nums[r] == 0) {
            count--;
        }
        if(count < 0) {
            if (nums[l] == 0) {
                count++; 
            }
            l++; 
        }
        maxLen = max(maxLen, r - l + 1);
        r++;
    }
return maxLen;
}
int main()
{
vector<int> nums={0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1};
int k=3;
cout<<longestOnes(nums,k)<<endl;
return 0;
}