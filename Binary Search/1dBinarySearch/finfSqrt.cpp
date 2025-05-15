#include<iostream>
using namespace std;
// Brute Force Approach
int findSqrt(int target){
    if(target==0)return 0;
    int ans=1;
    for (int i = 1; i < target; i++)
    {   
        if (i*i<=target)
        {
            ans=i;
        }else{
            break;
        }
    }
    return ans;
}
    
// Optimizes=d Approach
int findSqrtOptimize(int target){
if(target==0)return 0;    
int left=1;
int right=target;
int ans=1;
while (left<=right)
{
    int mid=left+(right-left)/2;
    if (mid*mid<=target)
    {
        ans=mid;
        left=mid+1;
    }else{
        right=mid-1;
    }   
}
return ans;
}
int main()
{
int target;
cin>>target;
cout<<findSqrt(target)<<endl;
cout<<findSqrtOptimize(target)<<endl;
return 0;
} 