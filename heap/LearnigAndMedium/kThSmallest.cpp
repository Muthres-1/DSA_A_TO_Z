#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
  public:
    // arr : given array
    // k : find kth smallest element and return using this function
    int kthSmallest(vector<int> &arr, int k) {
        // code here
         priority_queue<int,vector<int>, greater<int>> minHp(arr.begin(), arr.end());
         for(int i=0;i<k-1;i++){
            minHp.pop();
         }
         return minHp.top(); 
    }
};

int main()
{

return 0;
}