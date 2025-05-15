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
// The time complexity is O(n1*n2) and the space complexity is O(n2)
vector<int> IntersectionOfTwoSA(vector<int> a, vector<int> b)
{
    int n1 = a.size();
    int n2 = b.size();
    vector<bool>vis(n2,0);
    vector<int>ans;
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < n2; j++)
        {
            if (a[i] == b[j] && vis[j] == 0)
            {
                ans.push_back(a[i]);
                vis[j]=1;
                break;
            }
            if(b[j] > a[i])break;
            
        }
    }
    return ans;
}

// Optimized way

// The time complexity is O(n1+ n2) And the extra space complexity is O(1)
vector<int> IntersectionOfTwoSAOptimized(vector<int> a, vector<int> b)
{
    int n1 = a.size();
    int n2 = b.size();
    int i=0,j=0;
    vector<int>ans;
    while (i<n1 && j<n2)
    {
        if(a[i] < b[j]){
            i++;
        }
        else if (a[i]>b[j])
        {
            j++;
        }
        else{
            ans.push_back(a[i]);
            i++;
            j++;
        }
    }
    return ans;
}
int main()
{
    vector<int> arr1 = {1, 2, 2, 3, 4, 4, 5};
    vector<int> arr2 = {2, 3, 5, 6, 6, 7, 8, 9, 9};
    // vector<int> temp = IntersectionOfTwoSA(arr1, arr2);
    vector<int> temp = IntersectionOfTwoSAOptimized(arr1, arr2);
    for (auto it : temp)
    {
        cout << it << " ";
    }
    cout << endl;
    return 0;
}