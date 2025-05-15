#include<unordered_map>
#include<unordered_set>
#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
#include<math.h>
#include<stack>
#include<queue>
#include<list>
#include<set>
#include<map>
using namespace std;

int LongestSubArrWithSumK(vector<int>arr,int length,int k){
    int maxLen=0;
    for (int i = 0; i < length; i++)
    {
        for (int j = i; j < length; j++)
        {
            int sum=0;
            for (int k = i; k <= j; k++)
            {
                sum+=arr[k];
            }
            if (sum==k && maxLen < j-i+1)
            {
                maxLen=j-i+1;
            }            
        }        
    }
    return maxLen;    
}
int LongestSubArrWithSumK2(vector<int>arr,int length,int k){
    int maxLen=0;
    for (int i = 0; i < length; i++)
    {
        for (int j = i; j < length; j++)
        {
            int sum=0;
            sum+=arr[k];
            if (sum==k && maxLen < j-i+1)
            {
                maxLen=j-i+1;
            }            
        }        
    }
    return maxLen;    
}

// Better way
// The following code is correct but only for positives so for that we need to change slight in following 
int longestSubArrWithSumKBetter(vector<int>arr,int length,int k){
    map<long long,int>mp;
    long long sum=0;
    int mxLen=0;
    for (int i = 0; i < length; i++)
    {
        sum+=arr[i];
        if(sum==k){
            mxLen=max(mxLen,i+1);
        }
        long long rem=sum-k;
        if (mp.find(rem)!=mp.end())
        {
            int len = i-mp[rem];
            mxLen=max(mxLen,len);
        }
        mp[sum]=i;
    }
    return mxLen;
}
// Better way
// This code still have issue for that who have positive and negative elements in array
int longestSubArrWithSumKBetter2(vector<int>arr,int length,int k){
    map<long long,int>mp;
    long long sum=0;
    int mxLen=0;
    for (int i = 0; i < length; i++)
    {
        sum+=arr[i];
        if(sum==k){
            mxLen=max(mxLen,i+1);
        }
        long long rem=sum-k;
        if (mp.find(rem)!=mp.end())
        {
            int len = i-mp[rem];
            mxLen=max(mxLen,len);
        }
        if (mp.find(sum) == mp.end())
        {
            mp[sum]=i;
        }
    }
    return mxLen;
}

// Optimized solution
// This will work for all positive and negative as well 
// Time complexity is O(2*n)  And space complexity is O(1)
// This type of method is called as prefix sum 
int longestSubArrWithSumKOptimized(vector<int>arr,int length,int k){
    int left = 0, right = 0;
    long long sum = arr[0];
    int mxLen=0;
    while (right < length)
    {
        while (left <= right && sum>k)
        {
            sum-=arr[left];
            left++;
        }
        if (sum == k)
        {
            mxLen = max(mxLen,right-left+1);
        }
        right++;
        if (right < length)
        {
            sum+=arr[right];
        }
        
    }
    return mxLen;
}
int main()
{
//vector<int>arr={};

return 0;
}