#include<iostream>
using namespace std;

// Brute force approach
long long f(int i,int N){
    long long ans=1;
    while (N>=1)
    {
        if(N%2==1)
        {
            ans*=i;
            N=N-1;
        }else{
            i=i*i;
            N=N/2;
        }
    }
    return ans;    
    // i^N
}

int findNthRoot(int target,int N){
    if(target==1 || N==1)return target;
    for (int i = 0; i < target; i++)
    {
        long long a=f(i,N);
        if(a==target)return i;
        else if (a>target)
        {
            break;
        }
               
    }
    return -1;
    
}

// Optimization of approach
int findNthRootOptimized(int target,int N){
    if(target==1 || N==1)return target;
    int left=1,right=target;
    while (left<=right)
    {
        int mid=left+(right-left)/2;
        long long a=f(mid,N);
        if(a==target){
            return mid;
        }
        else if (a>target)
        {
            right=mid-1;
        }
        else{
            left=mid+1;
        }
        
    }
    return -1;    
}
// The above function is correct but there is a problem when target 10^9 and N=10 in such big 
// the value of f((10^9)/2,N) is in overflow case so that's why it will show wrong answer in such cases 
// So we need to modify our f function.
// To resolve that overflow case we run the following function 
// return 1 if i^N==target
// return 0 if i^N < target
// return 2 if i^N > target
int func(int i,int N,int target){
    long long ans=1;
    for (int j = 0; i < N; i++)
    {
        ans=ans*i;
        if(ans==target)return 1;
        else if (ans>target)
        {
            return 2;
        }else{
            return 0;
        }
        
    }
    
}
// Optimization of approach
int findNthRootOptimized(int target,int N){
    if(target==1 || N==1)return target;
    int left=1,right=target;
    while (left<=right)
    {
        int mid=left+(right-left)/2;
        int a=func(mid,N,target);
        if(a==1){
            return mid;
        }
        else if (a==2)
        {
            right=mid-1;
        }
        else{
            left=mid+1;
        }
        
    }
    return -1;    
}

int main()
{
int target;
int N;
cin>>N>>target;
// cout<<f(2,3)<<endl;
cout<<findNthRoot(target,N)<<endl;
return 0;
}