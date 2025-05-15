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

// The time complexity O(n) And the space complexity is O(n) 
vector<int> leadersInArr(vector<int>arr,int length){
    vector<int>ans;
    int leader=arr[length-1];
    ans.push_back(leader);
    for (int i = length-2; i >= 0; i--)
    {
        if (arr[i] >= leader)
        {
            leader=arr[i];
            ans.push_back(leader);
        }
        
    }
    return ans;
}
int main()
{
vector<int>arr={10,22,12,3,0,6};
vector<int>ans = leadersInArr(arr,arr.size());
for(auto it : ans){
    cout<<it<<" ";
}
cout<<endl;
return 0;
}
