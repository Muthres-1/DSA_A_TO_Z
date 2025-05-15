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

// Majority elements should be more than floor of n/3, those all would be final answer 
// Brute force as earlier in majority element that we will pick each element and check its occuring time 
// And the better also same as earlier using hashing but putting every time each element inside hash 
// come with more cost so if an element is occured greater than floor(n/3) then we won't put 
// again that element if that occuring still , mean only add in final answer when only equal to floor(n/3)
// map<int,int>hashing

// Important here at max two answer possible more than two answer is not possible 
// Optimal answer 
vector<int> majorityElementOptimal(vector<int>arr,int length){
int cnt1 =0,el1=INT_MIN,cnt2 =0,el2=INT_MIN;
    for (int i = 0; i < length; i++)
    {
        if (cnt1 == 0 && arr[i] != el2)
        {
            cnt1++;
            el1 = arr[i];
        }
        else if (cnt2 == 0 && arr[i] != el1)
        {
            cnt2++;
            el2 = arr[i];
        }
        else if (arr[i]  == el1)
        {
            cnt1++;
        }
        else if (arr[i]  == el2)
        {
            cnt2++;
        }
        else{
            cnt1--;
            cnt2--;
        }
    }
    // Verify of appearing number more than length/2
    vector<int>ans;
    cnt1=0;
    cnt2=0;
    for (int i = 0; i < length; i++)
    {
        if (arr[i] == el1)
        {
            cnt1++;
        }
        if (arr[i] == el2)
        {
            cnt2++;
        }
        
    }
    if (cnt1> length/3)
    {
        ans.push_back(el1);
    }
    if (cnt1> length/3)
    {
        ans.push_back(el2);
    }
    sort(ans.begin(),ans.end());
    return ans;
}
int main()
{
vector<int>arr={2,4,1,1,1,5,5,5};
vector<int>ans = majorityElementOptimal(arr,arr.size());
for(auto it : ans){
    cout<<it<<" ";
}
cout<<endl;
return 0;
}