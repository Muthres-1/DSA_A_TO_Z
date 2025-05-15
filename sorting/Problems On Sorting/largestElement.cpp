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
// Brute force is to sort first and then return end of array element 

// Optimized solution 
// Time complexity is O(n) 
int largestElement(vector<int>arr,int length){
    if (length==0)
    {
        return -1;
    }    
    int maxInd=0;
    for (int i = 1; i < length; i++)
    {
        if(arr[i]>arr[maxInd]){
            maxInd=i;
        }
    }
    return arr[maxInd];    
}
int main()
{
vector<int>arr={2,1,6,4,3,8};
cout<<largestElement(arr,arr.size())<<endl;
return 0;
}