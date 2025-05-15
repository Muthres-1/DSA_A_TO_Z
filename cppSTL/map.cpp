#include<unordered_map>
#include<unordered_set>
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
int main()
{
    // it is array of key value pairs where 
    // It stores unique key in sorted order
// It store values in the format of key value pair here key can be anything and similar value also can be anything 
map<int,string>mp;
map<int,int>mp1;
map<string,string>mp2;
map<pair<int,int>,string>mp3;
mp[1]="muthres";
mp2["gurjar"]="muthres";
mp3[{1,2}]="jeetram";
mp1.insert({4,5});// {key,value}
mp.emplace(make_pair(2, "dil"));
for (auto it: mp)
{
    cout<<it.first<<" "<<it.second<<endl;
}

auto it=mp.find(2);// it not found give mp.end()
it = mp.lower_bound(3);// if not found give mp.end()
// same as upper_bound

return 0;
}