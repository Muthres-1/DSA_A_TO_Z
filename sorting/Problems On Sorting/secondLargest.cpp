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

// Brute force approach 
int kThLargestElement(vector<int>arr,int length){
    if (length<=1)
    {
        return -1;
    }    
    sort(arr.begin(),arr.end());
    int largestInd=length-1;    
    int secondLargest=length-1;
    while (secondLargest>0)
    {
        secondLargest--;
       if(arr[secondLargest]!=arr[largestInd]) return arr[secondLargest];
    }
    return -1;
}

// Optimized Solution 
// Time complexity is O(n)
int kThLargestElementOptimized(vector<int>arr,int length){
    if (length<=1)
    {
        return -1;
    }    
    int largestEle=arr[0];    
    int secondLargest=INT_MIN;
    for (int i = 1; i < length; i++)
    {
        if(arr[i]>largestEle){
            secondLargest=largestEle;
            largestEle=arr[i];
        }
        else if (arr[i] > secondLargest && arr[i] < largestEle)
        {
            secondLargest=arr[i];
        }        
    }
    return secondLargest;
}
int main()
{
vector<int>arr={7,7};
cout<<kThLargestElement(arr,arr.size())<<endl;
cout<<kThLargestElementOptimized(arr,arr.size())<<endl;
return 0;
}