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
// Brute force way
// the time complexity is O(n^2)  and the space complexity is O(1)
// int longestConsecutiveSeq(vector<int>arr,int length){
//     int longest = 1;
//     for (int i = 0; i < length; i++)
//     {
//         int x  = arr[i];
//         int count=1;
//         while (linearSearch(arr,x+1)==true)
//         {
//             x+=1;
//             count++;
//         }
//         longest = max(longest,count);
//     }
//     return longest;
// }
// Better solution
// The time complexity is O(nlog(n) + n) and the space complexity is O(1)
// In the following we count in length duplicates also like 1 1 2 2 3 4 7 then length is 6
int longestConsecutiveSeq(vector<int> arr, int length)
{
    sort(arr.begin(), arr.end());
    int curr = 1;
    int previous = arr[0];
    int count = 1;
    int maxCount = 1;
    while (curr < length)
    {
        if (arr[curr] != previous + 1 && arr[curr] != previous)
        {
            count = 1;
            previous = arr[curr];
        }
        else
        {
            count++;
            previous = arr[curr];
            maxCount = max(maxCount, count);
        }
        curr++;
    }
    return maxCount;
}
// Better solution
int longestConsecutiveSeq2(vector<int> arr, int length)
{
    sort(arr.begin(), arr.end());
    int curr = 1;
    int previous = arr[0];
    int count = 1;
    int maxCount = 1;
    while (curr < length)
    {
        if (arr[curr] != previous + 1 && arr[curr] != previous)
        {
            count = 1;
            previous = arr[curr];
        }
        else if (arr[curr] == previous)
        {
            curr++;
            continue;
        }
        else
        {
            count++;
            previous = arr[curr];
            maxCount = max(maxCount, count);
        }
        curr++;
    }
    return maxCount;
}

// In both above solution we are destorting array which interviewer not like
// Optimal solution
// The time complexity is O(3n) assuming that set dataStructure doesn't take O(1) and space complexity is O(n)
int longestConsecutiveSeqOptimal(vector<int> arr, int length)
{
    if (length == 0)
    {
        return 0;
    }
    int longest = 1;
    unordered_set<int> st;
    for (int i = 0; i < length; i++)
    {
        st.insert(arr[i]);
    }
    for (auto it : st)
    {
        int a = it - 1;
        if (st.find(a) == st.end())
        {
            int cnt = 1;
            int x = it;
            while (st.find(x + 1) != st.end())
            {
                x += 1;
                cnt += 1;
            }
            longest = max(longest, cnt);
        }
    }
    return longest;
}
int main()
{
    vector<int> arr = {102, 4, 100, 1, 101, 3, 2, 1, 1};
    // cout << longestConsecutiveSeq2(arr, arr.size()) << endl;
    cout << longestConsecutiveSeqOptimal(arr, arr.size()) << endl;
    return 0;
}