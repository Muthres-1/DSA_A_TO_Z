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

// Problem : - we have to merge two sorted array without using any extra space and after that we need to divide them to
// those array and if any element is related to array1 before merging then after merging it may possible in array2

// Brute force way
// the time complexity is O(2*(n1+n2)) And the space complexity is O(n1+n2)
void merge(vector<int> &arr1, vector<int> &arr2)
{
    int n1 = arr1.size();
    int n2 = arr2.size();
    vector<int> arr;
    int left = 0, right = 0, index = 0;
    while (left < n1 && right < n2)
    {
        if (arr1[left] <= arr2[right])
        {
            arr.push_back(arr1[left]);
            left++;
        }
        else
        {
            arr.push_back(arr2[right]);
            right++;
        }
        index++;
    }
    while (left < n1)
    {
        arr.push_back(arr1[left]);
        left++;
        index++;
    }
    while (right < n2)
    {
        arr.push_back(arr2[right]);
        right++;
        index++;
    }
    for (int i = 0; i < index + 1; i++)
    {
        if (i < n1)
        {
            arr1[i] = arr[i];
        }
        else
        {
            arr2[i - n1] = arr[i];
        }
    }
}

// Better way 
// We want to get rid of extra space that we are using 
// Time complexity is O(min(m,n) + nlog(n) + mlog(m)) and the space complexity is O(1)
void mergeBetter(vector<int>&arr1,vector<int>&arr2){
    int n = arr1.size();
    int m = arr2.size();
    int left =n-1;
    int right = 0;
    while (left >= 0 && right< m)
    {
        if (arr1[left] >arr2[right])
        {
            swap(arr1[left],arr2[right]);
            left--;
            right++;
        }
        else{
            break;
        }
        
    }
    sort(arr1.begin(),arr1.end());
    sort(arr2.begin(),arr2.end());
}

// better method 2
// this method called as gap method which comes from shell sort technique
// the time complexity is O(log2(m+n) + O(n+m)) and the space complexity is O(1)
void swapIfGreater(vector<int>&arr1,vector<int>&arr2,int ind1,int ind2){
    if (arr1[ind1] > arr2[ind2])
    {
        swap(arr1[ind1],arr2[ind2]);
    }
    
}
void gapMethodToSorting(vector<int>&arr1,vector<int>&arr2){
    int n = arr1.size();
    int m = arr2.size();
    int totalLength= n+m;
    int gap = ceil(double(totalLength)/double(2));
    while (gap>0)
    {
        int left = 0;
        int right = left + gap;
        while (right < totalLength)
        {
            // when left is in arr1 and right is in arr2
            if (left < n && right >= n)
            {
                
            }
            else if (left >= n)// when both left and right are in second array
            {
                swapIfGreater(arr2,arr2,left-n,right-n);
            }
            else{// when both are in first array 
                swapIfGreater(arr1,arr1,left,right);
            }
            left++;
            right--;
        }
        if (gap == 1)
        {
            break;
        }
        else{
            gap= ceil(double(gap)/double(2));
        }
        
    }
    
}
int main()
{
    // vector<int>arr={};
    
    return 0;
}