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

// Problem :- if we add four different element from array then sum of them is equal to target
// Brute foece way
// the time complexity is O(n^4) and the space complexity is O(2*no of set of four elements)
vector<vector<int>> fourSum(vector<int> arr, int length, int target)
{
    set<vector<int>> st;
    for (int i = 0; i < length; i++)
    {
        for (int j = i + 1; j < length; j++)
        {
            for (int k = j + 1; k < length; k++)
            {
                for (int l = k + 1; l < length; l++)
                {
                    long long sum = arr[i] + arr[j];
                    sum += arr[k];
                    sum += arr[l]; // we did to secure overflow case
                    if (sum == target)
                    {
                        vector<int> temp = {arr[i], arr[j], arr[k], arr[l]};
                        sort(temp.begin(), temp.end());
                        st.insert(temp);
                    }
                }
            }
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}

// Better solution
// the time complexity is near about O((n^2)*(log(m)) ) and the space
// complexity is O(n) + O(2*no. of unique four elements) , m = this is varying in hashSet
vector<vector<int>> fourSumBetter(vector<int> arr, int length, int target)
{
    set<vector<int>> st;
    for (int i = 0; i < length; i++)
    {
        for (int j = i + 1; j < length; j++)
        {
            set<int> hashSet;
            for (int k = j + 1; k < length; k++)
            {
                long long forth = (arr[i] + arr[j]);
                forth += arr[k];
                forth = target - forth;
                if (hashSet.find(forth) != hashSet.end())
                {
                    vector<int> temp = {arr[i], arr[j], arr[k], int(forth)};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
                hashSet.insert(arr[k]);
            }
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}

// Optimal Solution
// We want to get rid of st
// The algorithm is two pointer approach
// the time complexity is O(nlog(n) + n*n*n)  and the space complexity is O(no of element in set)
vector<vector<int>> fourSumOptimal(vector<int> arr, int length, int target)
{
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());
    for (int i = 0; i < length; i++)
    {
        if (i > 0 && arr[i] == arr[i - 1])
            continue;
        for (int j = i + 1; j < length; j++)
        {
            if (j != i + 1 && arr[j] == arr[j - 1])
                continue;

            int k = j + 1;
            int l = length - 1;
            while (k < l)
            {
                long long sum = arr[i] + arr[j];
                sum+=arr[k];
                sum+=arr[l];
                if (sum < target)
                {
                    k++;
                }
                else if (sum > target)
                {
                    l--;
                }
                else
                {
                    vector<int> temp = {arr[i], arr[j], arr[k],arr[l]};
                    ans.push_back(temp);
                    k++;
                    l--;
                    while (k < l && arr[k] == arr[k - 1])
                        k++;
                    while (k < l && arr[l] == arr[l + 1])
                        l--;
                }
            }
        }
    }
    return ans;
}

int main()
{
    vector<int> arr = {1, 0, -1, 0, -2, 2};
    int target;
    cin >> target;
    // vector<vector<int>> ans = fourSum(arr, arr.size(), target);
    // vector<vector<int>> ans = fourSumBetter(arr, arr.size(), target);
    vector<vector<int>> ans = fourSumOptimal(arr, arr.size(), target);
    for (auto it : ans)
    {
        for (auto it1 : it)
        {
            cout << it1 << " ";
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}