#include<iostream>
#include<vector>
using namespace std;

// Brute force solution 
double medianOfTwoSorted(vector<int>arr1,vector<int>arr2){
    int l1=arr1.size();
    int l2=arr2.size();
    vector<int>arr;
    int i=0,j=0;
    while (i<l1 && j<l2)
    {
        if(arr1[i]<=arr2[j]){
            arr.push_back(arr1[i]);
            i++;
        }else{
            arr.push_back(arr2[j]);
            j++;
        }
    }
    while (i<l1)
    {
        arr.push_back(arr1[i]);
        i++;
    }
    while (j<l2)
    {
        arr.push_back(arr2[j]);
        j++;
    }
       
    int l=l1+l2;
    if(l%2 == 1){
        return double(arr[l/2]);
    }
    else{
        return double((arr[l/2] + arr[(l/2)-1])/2);
    }
    return 0;
}

// Optimizing We don't need to use an extra space 
double medianOfTwoSortedOptimized(vector<int>arr1,vector<int>arr2){
    int l1=arr1.size();
    int l2=arr2.size();
    int l=l1+l2;
    int ind1=l/2,ind2=(l/2)-1;
    int i=0,j=0,ele1,ele2,count=0;
    while (i<l1 && j<l2)
    {
        if(arr1[i]<=arr2[j]){
            if(count==ind1){
                ele1=arr1[i];
                break;
            }
            if(count==ind2)ele2=arr1[i];
            i++;
        }else{
            if(count==ind1){
                ele1=arr1[i];
                break;
            }
            if(count==ind2)ele2=arr1[i];
            j++;
        }
        count++;
    }
    while (i<l1)
    {
        if(ind1 !=-1 && ind2 != -1)break;
        if(count==ind1){
                ele1=arr1[i];
                break;
        }
        if(count==ind2)ele2=arr1[i];
        i++;
    }
    while (j<l2)
    {
        if(ind1 !=-1 && ind2 != -1)break;
        if(count==ind1){
                ele1=arr1[i];
                break;
        }
        if(count==ind2)ele2=arr1[i];
        j++;
    }
       
    if(l%2 == 1){
        return double(ele2);
    }
    else{
        return double((ele1 + ele2)/2);
    }
    return 0;
}

// More Optimized Solution 
double medianOfTwoSortedMoreOptimized(vector<int>arr1,vector<int>arr2){
        int n1=arr1.size();
        int n2= arr2.size();
        if(n1>n2)return medianOfTwoSortedMoreOptimized(arr2,arr1);
        int low=0,high=n1;
        int left=(n1+n2+1)/2;
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
                if(n%2 == 1)return max(l1,l2);
                return double((max(l1,l2)+min(r1,r2))/2);
            }
            else if(l1>r2) high=mid1-1;
            else{
                low=mid1+1;
            }
        }
        return 0;        
}

int main()
{
vector<int>arr1={1,3,4,7,10,12};
vector<int>arr2={2,3,6,15};
// cout<<medianOfTwoSorted(arr1,arr2)<<endl;
cout<<medianOfTwoSortedOptimized(arr1,arr2)<<endl;
cout<<medianOfTwoSortedMoreOptimized(arr1,arr2)<<endl;
return 0;
}