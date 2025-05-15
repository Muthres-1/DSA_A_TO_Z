#include<iostream>
#include<map>
#include<vector>
using namespace std;

// Brute force approach
int singleElementInSA(vector<int>arr,int length){
    for (int i = 0; i < length; i++)
    {
        int num=arr[i];
        int count=0;
        for (int j = 0; i < length; j++)
        {
            if(arr[j]==num){
                count++;
            }
        }
        if (count==1)
        {
            return num;
        }
        
    }
    
}

// hashing 
// this won't work in case of negative numbers and large elements of array so we can use instead of map it will be much more better 
int singleElementInSA2(vector<int>arr,int length){
    int maxi=*max_element(arr.begin(),arr.end());
    vector<int>hashing(maxi+1,0);
    for (int i = 0; i < length; i++)
    {
        hashing[arr[i]]++;
    }
    for (int i = 0; i < length; i++)
    {
        if(hashing[arr[i]]==1){
            return arr[i];
        }
    }
    
}
// The time complexity for following O(nlog(m)) + O(n/2  +  1) where m is n/2 +1 and the space complexity is O(n/2  +  1)
int singleElementInSA3(vector<int>arr,int length){
    map<long long , int > mp;
    for (int i = 0; i < length; i++)
    {
        mp[arr[i]]++;
    }
    for(auto it : mp){
        if(it.second==1)return it.first;
    }
}
// Better approach approach 
int singleElementInSABetter(vector<int>arr,int length){
    int xor=0;
    for (int i = 0; i < length; i++)
    {
        xor=xor^arr[i];
    }
    return xor;
}
int singleElementInSABetter2(vector<int>arr,int length){
    if (length==1)
    {
        return arr[0];
    }    
    for(int i=0;i<length;i++){
        if(i==0){
            if(arr[0]!=arr[1])return arr[0];
        }
        else if (i==length-1)
        {
            if(arr[i]!=arr[i-1])return arr[i];
        }else{
            if(arr[i]!=arr[i-1] && arr[i]!=arr[i+1])return arr[i];
        }
    }
    return -1;
}

// Opimized Approach 

int singleElementInSAoptimized(vector<int>arr,int length){
if(length==1)return arr[0];
if(arr[0]!=arr[1])return arr[0];
if(arr[length-1]!=arr[length-2])return arr[length-1];
// now we can start from 1 to till length-2 and we don't need to worry about end points
int left=1,right=length-2;
while (left<=right)
{
    int mid=left+(right-left)/2;
    if(arr[mid]!=arr[mid-1] && arr[mid]!=arr[mid+1])return arr[mid];
    // check that we are on left half or right half 
    // first check for left half 
    if((mid%2==1 && arr[mid]==arr[mid-1]) || (mid%2 == 0 && arr[mid]==arr[mid+1])){// Its mean we are on left half so our element is right of this 
    left = mid+1; // eliminate the left half 
    }else{
        right=mid-1; // eliminate the right half 
    }
}
return -1;
}
int main()
{
vector<int>arr={1,1,2,2,3,3,4,5,5,6,6};
cout<<singleElementInSA(arr,arr.size())<<endl;
cout<<singleElementInSAoptimized(arr,arr.size())<<endl;
return 0;
}