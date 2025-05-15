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


// Brute force way
// normal sorting in which time complexity is used O(nlog(n))  extra space complexity is O(n)

// Better solution 
// The time complexity is O(2*n)   and the space complexity is O(1)
void BetterSorting(vector<int>&arr,int length){
    int count0=0,count1=0,count2=0;
    for (int i = 0; i < length; i++)
    {
        if (arr[i] == 0)
        {
            count0++;
        }
        else if (arr[i] == 1)
        {
            count1++;
        }
        else{
            count2++;
        }
    }
    for (int i = 0; i < count0; i++)
    {
        arr[i] = 0;
    }
    
    for (int i = count0; i < count1 + count0; i++)
    {
        arr[i] = 1;
    }
    
    for (int i = count0 + count1; i < count0 + count1 + count2; i++)
    {
        arr[i] = 2;
    } 
    
}

// Optimized algorithm named Dutch National Flag Algorithm
// The time  complexity is O(n)  And space complexity is O(1)

void DutchNationalFlagAlgo(vector<int>&arr,int length){
    int low=0,mid=0,high=length-1;
    while (mid <= high)
    {
        if (arr[mid] == 0)
        {
            swap(arr[low],arr[mid]);
            low++;
            mid++;
        }
        else if (arr[mid] == 1)
        {
            mid++;
        }
        else{
            swap(arr[mid],arr[high]);
            high--;
        }
    }
    
}

int main()
{
vector<int>arr={2,1,2,0,2,0,0,1,1,0};
BetterSorting(arr,arr.size());
// DutchNationalFlagAlgo(arr,arr.size());
for(auto it : arr){
    cout<<it<<" ";
}
cout<<endl;
return 0;
}