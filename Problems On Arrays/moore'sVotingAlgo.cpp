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

// Majority element 
// In this algo we find the element who appears more than floor[length/2] times ,keep in mind more than not equal to

// Brute force approach
// I pick every element and check its frequency in entire array if it appears more than length/2 times then it 
// is the answer
// But this will take O(n^2) time which is more worst

// for more optimized this we can use hashing in which we run a for loop and count every elements frequency and at the
// end of function we iterate again for loop and find which element is more than length/2 and return that
// The time complexity is for this is O(nlog(n) + n) and space complexity is O(n)

// Optimized algorithm 

int mooresVotingAlgo(vector<int>&arr,int length){
    int cnt =0,el;
    for (int i = 0; i < length; i++)
    {
        if (cnt == 0)
        {
            cnt++;
            el = arr[i];
        }
        else if (arr[i]  == el)
        {
            cnt++;
        }
        else{
            cnt--;
        }
    }
    // Verify of appearing number more than length/2
    int cnt1=0;
    for (int i = 0; i < length; i++)
    {
        if (arr[i] == el)
        {
            cnt1++;
        }
        
    }
    if (cnt1> length/2)
    {
        return el;
    }
    return -1;
}
int main()
{
vector<int>arr={4,6,4,8,8,8,5,5,3,4,4,4,4,4};
cout<<mooresVotingAlgo(arr,arr.size())<<endl;
return 0;
}