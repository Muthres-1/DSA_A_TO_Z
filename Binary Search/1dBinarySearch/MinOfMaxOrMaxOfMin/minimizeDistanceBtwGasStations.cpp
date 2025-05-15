#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// Brute force approach 
// Time complexity= O(k*n + n)
long double minimizeDistanceBtwGasStations(vector<int>arr,int k){
    int n=arr.size();
    vector<int>howMany(n-1,0);
    for (int gasStation = 0; gasStation < k; gasStation++)
    {
        long double maxSection =-1;
        int maxInd=-1;
        for (int i = 0; i < n-1; i++)
        {
            long double diff=arr[i+1]-arr[i];
            long double sectionLength=diff/(long double)(howMany[i]+1);
            if(maxSection<sectionLength){
                maxSection=sectionLength;
                maxInd=i;
            }
        }
        howMany[maxInd]++;
    }
    long double maxAns=-1;
    for (int i = 0; i < n-1; i++)
    {
        long double diff=arr[i+1]-arr[i];
        long double sectionLength=diff/(long double)(howMany[i]+1);
        maxAns=max(maxAns,sectionLength);
    }
    return maxAns;
}

// Optimized approach 
// Time complexity= O(nlog(n) + k*log(n)),space complexity=O(n-1)
long double minimizeDistanceBtwGasStationsOpitmized(vector<int>arr,int k){
int n=arr.size();
vector<int>howMany(n-1,0);
priority_queue<pair<long double,int>>pq;
for (int i = 0; i < n-1; i++)
{
    pq.push({arr[i+1]-arr[i],i});
}
for (int  gasStation = 0; gasStation < k; gasStation++)
{
    auto tp=pq.top();
    pq.pop();
    int sectionInd=tp.second;
    howMany[sectionInd]++;
    long double diff=arr[sectionInd+1]-arr[sectionInd];
    long double newSection = diff/(long double)(howMany[sectionInd]+1);
    pq.push({newSection,sectionInd});
}
return pq.top().first;
}

int minimizeDistanceBtwGasStationsFurtherOptimized(vector<int>arr,int k){

}
int main()
{
vector<int>arr={1,13,17,23};
int k;
cin>>k;
cout<<minimizeDistanceBtwGasStations(arr,k)<<endl;
cout<<minimizeDistanceBtwGasStationsOpitmized(arr,k)<<endl;
return 0;
}


