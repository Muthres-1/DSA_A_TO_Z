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
// Problem :- Number of subArr whose elements Xor is equal to k
// Brute force way
// Time complexity is O(n^3) and the space complexity is O(1)
int NumberOfSubArrXorK(vector<int> arr,int length, int target){
    int cnt=0;
    for (int i = 0; i < length; i++)
    {
        for (int j = i; j < length; j++)
        {
            int Xor = 0;
            for (int k = i; k <= j; k++)
            {
                Xor=Xor^arr[k];
            }
            if (Xor == target)
            {
                cnt++;
            }
            
        }
        
    }
    return cnt;
}
// Better way
// Time complexity is O(n^2) and the space complexity is O(1)
int NumberOfSubArrXorKBetter(vector<int> arr,int length, int target){
    int cnt=0;
    for (int i = 0; i < length; i++)
    {
        int Xor = 0;
        for (int j = i; j < length; j++)
        {
            Xor=Xor^arr[j];
            if (Xor == target)
            {
                cnt++;
            }
            
        }
        
    }
    return cnt;
}

// Optimal way
// O(n*log(n)) and if we use unordered_map then O(n) for best and average and for worst O(n*2) and the space comeplexity O(N)
// Very Important solution of prefix sum
int NumberOfSubArrXorKOptimal(vector<int> arr, int length, int target)
{
  map<int,int>mpp;
  mpp[0]=1;   
  int preXor = 0 , cnt =0;
  for (int i = 0; i < length; i++)
  {
    preXor^=arr[i];
    int remove = preXor^target;
    cnt+=mpp[remove];
    mpp[preXor]+=1;
  }
  return cnt;
}
int main()
{
vector<int>arr={4,2,2,6,4};
int k;
cin>>k;
cout<<NumberOfSubArrXorK(arr,arr.size(),k)<<endl;
cout<<NumberOfSubArrXorKBetter(arr,arr.size(),k)<<endl;
cout<<NumberOfSubArrXorKOptimal(arr,arr.size(),k)<<endl;
return 0;
}