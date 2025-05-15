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
// Time complexity is O(nlog(n) + 2*n)  And the time complexity is O(n) 
vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>>&arr,int length){
    sort(arr.begin(),arr.end());
    vector<vector<int>>ans;
    for (int i = 0; i < length; i++)
    {
        int start = arr[i][0];
        int end   = arr[i][1];
        if (!ans.empty() && end <=ans.back()[1])
        {
            continue;
        }
        for (int j = i+1; j < length; j++)
        {
            if (arr[j][0] <= end)
            {
                end = max(end,arr[j][1]);
            }
            else{
                break;
            }
        }
        ans.push_back({start,end});
    }
    return ans;
}
// Optimal Solution  
// Time complexity is O(nlog(n) + n)  And the time complexity is O(n) 
vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>>&arr,int length){
    sort(arr.begin(),arr.end());
    vector<vector<int>>ans;
    for (int i = 0; i < length; i++)
    {
        if(ans.empty() || arr[i][0] > ans.back()[1]){
            ans.push_back(arr[i]);
        }
        else{
            ans.back()[1]= max(ans.back()[1],arr[i][1]);
        }
    }
    return ans;
}
int main()
{
vector<int>arr={};

return 0;
}