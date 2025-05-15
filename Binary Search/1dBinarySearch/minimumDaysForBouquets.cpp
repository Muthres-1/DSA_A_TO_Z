#include<iostream>
#include<vector>
using namespace std;

pair<int,int> findMaxiAndMin(vector<int>arr){
    int maxi=-1e9,mini=1e9;
    for(int i=0;i<arr.size();i++){
        maxi=max(maxi,arr[i]);
        mini=min(mini,arr[i]);
    }
    return {maxi,mini};
}

bool IsPossible(int day,vector<int>arr,int m,int k){
    int a=k,b=m;
    for (int i = 0; i < arr.size(); i++)
    {
        if(a==0){
            b--;
            a=k;
        }
        if(day>=arr[i]){
           a--; 
        }else{
            a=k;
        }        
    }
    if(a==0){
        b--;
        a=k;
    }
    if(b==0){
        return true;
    } 
    return false;
}
int DayForBouquets(vector<int>arr,int m,int k){
    if(m*k>arr.size())return -1; // This is only impossible case 
    pair<int,int>a=findMaxiAndMin(arr);
    int right=a.first;
    int left=a.second;
    int ans=right;
    while (left<=right)
    {
        int mid=left+(right-left)/2;
        if(IsPossible(mid,arr,m,k)){
            ans=mid;
            right=mid-1;
        }else{
            left=mid+1;
        }
    }
    return ans;    
}
int main()
{
vector<int>arr={1,10,3,10,2};
int m,k;// m=no of bouquets,n=no of adjacent flowers
cin>>m>>k;
cout<<DayForBouquets(arr,m,k)<<endl;
return 0;
}