#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <stack>
#include <queue>
#include <list>
#include <set>
#include <map>
using namespace std;

// Brute force approach
// Time complexity is O(n*n) and the space complexity is O(1)
bool findMissingNumber(vector<int> arr, int k)
{
    for (int i = 1; i <= k; i++)
    {
        int flag = 0;
        for (int j = 0; j < k - 1; j++) // because only one number is missing so if we count from 1 to then there should be exjact k-1 element inside array
        {
            if (i != arr[j])
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            return i;
        }
    }
}

// The time complexity is O(2*n) and the space complexity is O(n)
int findMissingNumberBetter(vector<int>arr,int k){
    vector<int>hashing(k+1,0);
    for (int i = 0; i < k-1; i++)
    {
        hashing[arr[i]]++;
    }
    for (int i = 1; i <= k+1; i++)
    {
        if(hashing[i]==0){
            return i;
        }
    }
    return -1;
}

// Better solution
// Time complexity is O(n) and space complexity is O(1)
int findMissingNumberBetter2(vector<int>arr,int k){
    int total = k*(k+1)/2;
    int sum=0;
    for (int i = 0; i < k-1; i++)
    {
        sum+=arr[i];
    }
    return total-sum;
}

// Better solution 

int findMissingNumberBetter4(vector<int>arr,int k){
    int xor1=0;
    int xor2=0;
    for (int i = 0; i <= k-2; i++)
    {
        xor1=xor1^(i+1);
        xor2=xor2^arr[i];
    }
    xor1=xor1^k;
    return xor1^xor2;
}
// This is much more better because it won't show ever overflow situation
int findMissingNumberBetter4(vector<int>arr,int k){
    int xor1=0;
    for (int i = 1; i <= k; i++)
    {
        xor1=xor1^i;
    }
    int xor2=0;
    for (int i = 0; i <= k-2; i++)
    {
        xor2=xor2^arr[i];
    }
    return xor1^xor2;
}
// Optimal solution 
// 

int main()
{
    // vector<int>arr={};

    return 0;
}