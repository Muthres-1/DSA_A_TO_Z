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

bool isArraySorted(vector<int>arr,int length){
    for (int i = 1; i < length; i++)
    {
        if(arr[i]>=arr[i-1]){

        }else{
            return false; 
        }
    }
    return true;    
}
int main()
{
vector<int>arr={};
cout<<isArraySorted(arr,arr.size())<<endl;
return 0;
}
