#include<iostream>
using namespace std;

// We check for Three conditions >,=,<
int findInd(int target,int arr[],int length){
    int left=0;
    int right=length-1;
    while (left<=right)
    {
        int mid=left+(right-left)/2;// to resolve overflow problem
        if(arr[mid]==target){
            return mid;
        }
        else if (arr[mid]>target)
        {
            right=mid-1;
        }
        else{
            left=mid+1;// Here if we do just left=mid then it stuck into infinite loop when we check target = arr[length-1]
        }
        
    }
    
    return -1;
}
int main()
{
    int arr[]={1,2,3,4};
    int target;
    cin>>target;
    cout<<findInd(target,arr,4)<<endl;
return 0;
}