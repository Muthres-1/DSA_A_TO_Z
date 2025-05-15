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

// Problem :- there is given k and an array and we need to find
//  that which element repeating in that array
// from 1 to k and in that array and which is repeating

// Brute force way

vector<int> findMissingAndRepeating(vector<int> arr, int length, int k)
{
    int missing = -1, repeating = -1;
    for (int i = 1; i < k + 1; i++)
    {
        int cnt = 0;
        for (int j = 0; j < length; j++)
        {
            if (i == arr[j])
            {
                cnt++;
            }
            if (cnt >= 2)
            {
                repeating = i;
                break;
            }
        }
        if (cnt == 0)
        {
            missing = i;
        }
        if (missing != -1 && repeating != -1)
        {
            break;
        }
    }
    return {repeating, missing};
}

// better than previous using hashing
// time complexity is O(2*n) and the space complexity is O(n)
vector<int> findMissingAndRepeatingBetter(vector<int> arr, int length, int k)
{
    vector<int> hashing(k + 1, 0);
    for (int i = 0; i < length; i++)
    {
        hashing[arr[i]]++;
    }
    int missing = -1, repeating = -1;
    for (int i = 1; i <= k; i++)
    {
        if (hashing[i] == 0)
        {
            missing = i;
        }
        if (hashing[i] >= 2)
        {
            repeating = i;
        }
        if (repeating != -1 && missing != -1)
        {
            break;
        }
    }
    return {repeating, missing};
}

// Optimal method using basic mathematics
// to avoid used extra space
// time complexity is O(n)  And space complexity is O(1)
// x = repeating , y = missing
vector<int> findMissingAndRepeatingOptimal1(vector<int> arr, long long length, int k)
{
    // s -sn
    // s2 -s2n
    long long sn = k * (k + 1) / 2;
    long long s2n = k * (k + 1) * (2 * k + 1) / 6;
    long long s = 0, s2 = 0;
    for (int i = 0; i < length; i++)
    {
        s += (arr[i]);
        s2 += (arr[i] * arr[i]);
    }
    long long val1 = s - sn;   // x + y =val1
    long long val2 = s2 - s2n; // x^2 - y^2 = val2
    val2 = val2 / val1;        // now val2 is equal to s + sn
    long long x = (val1 + val2) / 2;
    long long y = x - val1;
    return {int(x), int(y)};
}

// In this method we are using xor method 
// time complexity is O(4*n) and the space complexity is O(1)
vector<int> findMissingAndRepeatingOptimal2(vector<int> arr, long long n, int k)
{
    int xr = 0;
    for (int  i = 0; i < n; i++)
    {
        xr = xr ^ arr[i];
        xr = xr ^ (i+1);
    }
    // int bitNo = 0;
    // while (1)
    // {
    //     if ((xr & (1<<bitNo)) != 0)
    //     {
    //         break;
    //     }
    //     bitNo++;
    // }
    // Instead of that we can do as following 
    int number = xr& ~(xr-1); // this will generat the different bit easily in single step 
    int zero = 0;
    int one = 0;
    // seperating for array's element 
    for (int i = 0; i < n; i++)
    {
        // part of 1 club 
        // if (arr[i] & (1<<bitNo) != 0)
        // {
        //     one = one ^ arr[i] ;
        // }
        if (arr[i] &number != 0)
        {
            one = one ^ arr[i] ;
        }
        else{ // part of 0 club
            zero = zero^arr[i];
        }
        
    }
    // do for element from 1 to k
    for (int i = 1; i <= n; i++)
    {
        // part of 1 club 
        // if (i & (1<<bitNo) != 0)
        // {
        //     one = one ^ i;
        // }
        if (i & number != 0)
        {
            one = one ^ i;
        }
        else{ // part of 0 club
            zero = zero^i;
        }
        
    }
    // confirming 
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i]== zero)
        {
            cnt++;
        }
        
    }
    if (cnt == 2)
    {
        return {zero,one};
    }
    return {one , zero };
}
int main()
{
    int k = 5; // In general k is equal to length of array
    vector<int> arr = {1, 2, 4, 4, 5};
    // vector<int> ans = findMissingAndRepeating(arr, arr.size(), k);
    // vector<int> ans = findMissingAndRepeatingBetter(arr, arr.size(), k);
    // vector<int> ans = findMissingAndRepeatingOptimal1(arr, arr.size(), k);
    vector<int> ans = findMissingAndRepeatingOptimal2(arr, arr.size(), k);
    cout << "Repeating numbers is : " << ans[0];
    cout << endl
         << "Missing numbers is : " << ans[1] << endl;
    return 0;
}