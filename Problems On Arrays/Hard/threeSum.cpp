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

// Give all unique triplex whose summation is equal to zero and in that combination duplicate
// should not available and also should not be such kind for example  1 1 -2 here one is occuring twice and in array 1 is
// appearing only one

// Brute force way
// the time complexity of following algorithm O(n^3 + log(no of unique triplex))  And the space complexity is O(2*no of unique triplex)
vector<vector<int>> triplet(vector<int> arr, int length)
{
    set<vector<int>> st;
    for (int i = 0; i < length; i++)
    {
        for (int j = i + 1; j < length; j++)
        {
            for (int k = j + 1; k < length; k++)
            {
                if (arr[i] + arr[j] + arr[k] == 0)
                {
                    vector<int> temp = {arr[i], arr[j], arr[k]};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
            }
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}

// Better Solution
// this will use hashing for arr[k] = - ( arr[i] + arr[j] )
// the time complexity is near about O(n^2(log(m)) ) and the space
// complexity is O(n) + O(2*no. of unique triples) , m = this is varying in hashSet
vector<vector<int>> tripletBetter(vector<int> arr, int length)
{
    set<vector<int>> st;
    for (int i = 0; i < length; i++)
    {
        set<int> hashSet;
        for (int j = i + 1; j < length; j++)
        {
            int third = -(arr[i] + arr[j]);
            if (hashSet.find(third) != hashSet.end())
            {
                vector<int> temp = {arr[i], arr[j], third};
                sort(temp.begin(), temp.end());
                st.insert(temp);
            }
            hashSet.insert(arr[j]);
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}

// Optimal Solution
// We want to get rid of st
// The algorithm is two pointer approach
// the time complexity is O(nlog(n) + n*n)  and the space complexity is O(no of unique element)
vector<vector<int>> tripletOptimal(vector<int> arr, int length)
{
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());
    for (int i = 0; i < length; i++)
    {
        if (i > 0 && arr[i] == arr[i - 1])
            continue;
        int j = i + 1;
        int k = length - 1;
        while (j < k)
        {
            int sum = arr[i] + arr[j] + arr[k];
            if (sum < 0)
            {
                j++;
            }
            else if (sum > 0)
            {
                k--;
            }
            else
            {
                vector<int> temp = {arr[i], arr[j], arr[k]};
                ans.push_back(temp);
                j++;
                k--;
                while (j < k && arr[j] == arr[j - 1])
                    j++;
                while (j < k && arr[k] == arr[k + 1])
                    k--;
            }
        }
    }
    return ans;
}
int main()
{
    vector<int> arr = {-1, 0, 1, 2, -1, -4};
    // vector<vector<int>>ans=triplet(arr,arr.size());
    // vector<vector<int>> ans = tripletBetter(arr, arr.size());
    vector<vector<int>> ans = tripletOptimal(arr, arr.size());
    for (auto it : ans)
    {
        for (auto it1 : it)
        {
            cout << it1 << " ";
        }
        cout << endl;
    }
    return 0;
}