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

int maxiConsecutiveOnes(vector<int>arr){
    int maxi=INT_MIN;
    int count=0;
    for (int i = 0; i < arr.size(); i++)
    {
        if(arr[i]==1){
            count++;
            if(maxi<count)maxi=count;
        }
        else{
            count=0;
        }
    }
    return maxi;
}
int main()
{
//vector<int>arr={};

return 0;
}