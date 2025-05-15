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

// Brute force way
// The time complexity is O(n1log(n) + n2log(n)) + O(n1 + n2) and the space complexity is O(n1+n2) + O(n1 + n2)
vector<int> UnionOfTwoSA(vector<int>arr1,vector<int>arr2){
    set<int>st;
    for(auto it: arr1){
        st.insert(it);
    }
    for(auto it: arr2){
        st.insert(it);
    }
    vector<int>temp;
    for(auto it: st){
        temp.push_back(it);
    }
    return temp;
}

// Optimized way 

// The time complexity is O(n1+ n2) And the extra space complexity is O(n1+n2)
vector<int> UnionOfTwoSAOptimized(vector<int>arr1,vector<int>arr2){
    int n1=arr1.size();
    int n2=arr2.size();
    int i=0,j=0;
    vector<int>unionArr;
    while (i<n1 && j<n2)
    {
        if(arr1[i] <= arr2[j]){
            if (unionArr.size() == 0 || unionArr.back() != arr1[i] )
            {
                unionArr.push_back(arr1[i]);
            }
            i++;
        }
        else{
            if (unionArr.size() == 0 || unionArr.back() != arr2[j])
            {
                unionArr.push_back(arr2[j]);
            }
            j++;
        }
    }
    while (i<n1)
    {
        if( unionArr.size() == 0 || arr1[i]!=unionArr.back()){
            unionArr.push_back(arr1[i]);
        }
        i++;
    }
    while (j<n2)
    {
        if( unionArr.size() == 0 || arr2[j]!=unionArr.back()){
            unionArr.push_back(arr2[j]);
        }
        j++;
    }
    
    return unionArr;
}
int main()
{
vector<int>arr1={1,2,2,3,4,4,5};
vector<int>arr2={2,3,5,6,6,7,8,9,9};
// vector<int> temp = UnionOfTwoSA(arr1,arr2);
vector<int> temp = UnionOfTwoSAOptimized(arr1,arr2);
for(auto it : temp){
    cout<<it<<" ";
}
cout<<endl;
return 0;
}