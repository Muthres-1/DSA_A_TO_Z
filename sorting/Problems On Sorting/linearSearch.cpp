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

int linearSearch(vector<int>arr,int length,int k){
    for (int i = 0; i < length; i++)
    {
        if(arr[i]==k){
            return i;
        }
    }
    return -1;
}
int main()
{
vector<int>arr={1,2,3,4,6,8,5,0};
int k;
cin>>k;
cout<<linearSearch(arr,arr.size(),k)<<endl;
return 0;
}