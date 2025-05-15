#include<iostream>
#include<vector>
using namespace std;
int main()
{
    // Iterators
    // Iterator is just an pointer pointing to something 
vector<int>arr={1,2,3,4};
vector<int>::iterator it=arr.begin(); // it is an iterator of type vector<int>
it++;
cout<<*(it)<<endl;// output 2
it=arr.end();
it--;
cout<<*(it)<<endl; // output 4

for (auto it = arr.begin(); it!=arr.end(); it++)
{
    cout<<*(it)<<endl;
}
for (vector<int>::iterator it = arr.begin(); it!=arr.end(); it++)
{
    cout<<*(it)<<endl;
}
for (auto it:arr)
{
    cout<<it<<endl;// Very Important here we didn't use the asterisk to find the value 
}

arr.erase(arr.begin()+1); // Keep in mind that pop_back() function just delete the last element of the vector 
arr.erase(arr.begin(),arr.begin()+2);// This will delete the 2 elements arr.begin() to arr.begin()+1 ,it won't delete arr.begin()+2

arr.insert(arr.begin()+2,100);// it will add 100 at arr.begin()+2 or can say after begin()+1
arr.insert(arr.begin()+1,2,10);// it will add two 10 just after arr.begin()
//If I want to swap two vectors then 
vector<int>v;
arr.swap(v);
v.insert(v.begin(),arr.begin(),arr.end());// It will add arr vector at starting of v 

v.clear(); // it will erase entire vector v
cout<<v.empty()<<endl; // it will give the output such as true or false such that 
// if v is empty then it will give true otherwise give false
v.push_back(2);

return 0;
}