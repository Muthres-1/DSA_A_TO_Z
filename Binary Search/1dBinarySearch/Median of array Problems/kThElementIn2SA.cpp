#include<iostream>
#include<vector>
using namespace std;

// This is showing wrong answer in the case of k=1 so we seperate its case but still didn't check that
// remaining is correct or not 
double medianOfTwoSortedMoreOptimized(vector<int>arr1,vector<int>arr2,int left){
        if(left==1){
            return min(arr1[0],arr2[0]);
        }
        int n1=arr1.size();
        int n2= arr2.size();
        if(n1>n2)return medianOfTwoSortedMoreOptimized(arr2,arr1,left);
        int low=max(0,left-n2),high=min(left,n1);
        int n=n1+n2;
        while (low<=high)
        {
            int mid1=(low+high)>>1;
            int mid2=left-mid1;
            int l1=INT_MAX,l2=INT_MAX;
            int r1=INT_MAX,r2=INT_MAX;
            if(mid1<n1)r1=arr1[mid1];
            if(mid2<n2)r2=arr2[mid2];
            if(mid1-1>=0)l1=arr1[mid1-1];
            if(mid2-1>=0)l2=arr2[mid2-1];
            if(l1<=r2 && l2 <= r1){
                return max(l1,l2);
            }
            else if(l1>r2) high=mid1-1;
            else{
                low=mid1+1;
            }
        }
        return 0;        
}
int kThElementInTwoSA(vector<int>arr1,vector<int>arr2,int k){
    return medianOfTwoSortedMoreOptimized(arr1,arr2,k);
}
int main()
{
vector<int>arr1={1,3,4,7,10,12};
vector<int>arr2={2,3,6,15};
int k;
cin>>k;
cout<<kThElementInTwoSA(arr1,arr2,k)<<endl;
return 0;
}

