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
int main()
{
vector<int>arr={1,3,4,5,69};
auto it = arr.begin();
for (; it != arr.end(); it++)
{
    cout<<*it<<endl;
}

// vector<int>::iterator it=arr.rend();
// But arr.rend() returns a reverse iterator, not a regular (forward) iterator.

// So you're trying to assign a reverse_iterator to a iterator, which is type mismatch.

// ✅ Fix:
// Use reverse_iterator instead of iterator:

// vector<int>::reverse_iterator it = arr.rend();
// Or with C++11 and above (recommended for simplicity):

auto it2 = arr.rend();
// first reverse array and after that the it2 will point to the next to end of the last element of reversed array
cout<<*it2<<endl;
cout<<*(--it2)<<endl;
it2++;
cout<<*(++it2)<<endl;

auto it3 = arr.rbegin();
// reverse array and after that this will point to the first element of reversed array
cout<<*it3<<" "<<*(--it3)<<" "<<*(++it3)<<endl;

return 0;
}