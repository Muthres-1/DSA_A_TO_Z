#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<list>
#include<set>
using namespace std;
int main()
{
// This contain only sorted not unique element 
multiset<int>ms;
// Everything similar as set just not unique element 
ms.insert(1);
ms.insert(2);
ms.insert(3);
ms.insert(1);
ms.insert(2);
ms.insert(2);
ms.insert(1); // {1,1,1,2,2,2,3}

ms.erase(1); // it will all 1 and if we want to delete a specific add then pass address 
// similar to vector


return 0;
}