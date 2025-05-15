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

// Brute force approach 
// The time complexity is O(2*n) And the space complexity is O(n);
void reArrange(vector<int>&arr,int length){
    vector<int>pos;
    vector<int>neg;
    for (int i = 0; i < length; i++)
    {
        if (arr[i] < 0)
        {
            neg.push_back(arr[i]);
        }
        else{
            pos.push_back(arr[i]);
        }
    }
    
    // Positive number allocation
    for (int i = 0; i < length/2; i++)
    {
        arr[2*i] = pos[i];
    }
    // Negative number allocation 
    for (int i = 0; i < length/2; i++)
    {
        arr[2*i + 1] = neg[i];
    }    
    
}

// Better solution 
// The time complexity is O(n) and the space complexity is O(n)
void reArrangeBetter(vector<int>&arr,int length){
    vector<int>ans(length,0);
    int posInd=0,negInd=1;
    for (int i = 0; i < length; i++)
    {
        if (arr[i] > 0)
        {
            ans[posInd]=arr[i];
            posInd+=2;
        }
        else{
            ans[negInd]=arr[i];
            negInd+=2;
        }
        
    }
    arr=ans;
}

// the both above solution won't work when number of negative is not equal to number of positives
// The time complexity is O(2*n) And the space complexity is O(n) 
void reArrangeBetter2Solution(vector<int>&arr,int length){
    vector<int>pos,neg;
    for (int i = 0; i < length; i++)
    {
        if (arr[i]<0)
        {
            neg.push_back(arr[i]);
        }
        else{
            pos.push_back(arr[i]);
        }
    }
    if (pos.size() > neg.size())
    {
        for (int i = 0; i < neg.size(); i++)
        {
            arr[2*i] = pos[i];
            arr[2*i+1] = neg[i];
        }
        int index = neg.size()*2;
        for (int i = neg.size() ; i < pos.size(); i++)
        {
            arr[index] = pos[i];
            index++;
        }
        
    }
    else{
        for (int i = 0; i < pos.size(); i++)
        {
            arr[2*i] = pos[i];
            arr[2*i+1] = neg[i];
        }
        int index = pos.size()*2;
        for (int i = pos.size() ; i < neg.size(); i++)
        {
            arr[index] = neg[i];
            index++;
        }
    }
    
}
int main()
{
vector<int>arr={3,1,-3,-5,6,-8,8,1};
// reArrange(arr,arr.size());
// reArrangeBetter(arr,arr.size());
reArrangeBetter2Solution(arr,arr.size());
for(auto it: arr){
    cout<<it<<" ";
}
cout<<endl;
return 0;
}