#include<iostream>
#include<vector>
#include<set>
#include<unordered_map>
using namespace std;
// Problem boils down to finding the maximum length of subArr such that in that there
// is two type of numbers
int totalFruits(vector<int> &arr) {
    int n=arr.size();
    int ans=0;
    for(int i=0;i<n;i++){
        set<int> s;
        for(int j=i;j<n;j++){
        s.insert(arr[j]);
        if(s.size()>2){
          break;
        }         
        ans=max(ans,j-i+1);
        }
    }
    return ans;
}

// Optimized answer

int Optimized(vector<int>&arr){
    int n = arr.size();
    unordered_map<int, int> fruitCount; // To count the frequency of each fruit type
    int l = 0, r = 0;
    int maxFruits = 0;
    while (r < n) {
        fruitCount[arr[r]]++;
        while (fruitCount.size() > 2) {
            fruitCount[arr[l]]--;
            if (fruitCount[arr[l]] == 0) {
                fruitCount.erase(arr[l]);  
            }
            l++;
        }
        maxFruits = max(maxFruits, r - l + 1);
        r++;
    }
    return maxFruits;    
}
// More Optimized answer
int Optimized(vector<int>&arr){
    int n = arr.size();
    unordered_map<int, int> fruitCount; // To count the frequency of each fruit type
    int l = 0, r = 0;
    int maxFruits = 0;
    while (r < n) {
        fruitCount[arr[r]]++;
        if(fruitCount.size() > 2) {
            fruitCount[arr[l]]--;
            if (fruitCount[arr[l]] == 0) {
                fruitCount.erase(arr[l]);  
            }
            l++;
        }
        maxFruits = max(maxFruits, r - l + 1);
        r++;
    }
    return maxFruits;    
}
int main()
{
vector<int> arr={2, 1, 2};
cout<<totalFruits(arr)<<endl;
return 0;
}