#include<iostream>
#include<vector>
using namespace std;
int main()
{
    // pair
pair<int,int>a={3,4};
cout<<a.first<<" "<<a.second<<endl;
pair<int,pair<int,int>>b={3,{4,5}};
cout<<b.first<<" "<<b.second.first<<" "<<b.second.second<<endl;

// array of pair
pair<int,int>arr[]={{3,4},{3,2},{1,9},{5,1}};
cout<<arr[3].first<<" "<<arr[3].second<<endl;
// Arrays are static in nature 
// while vectors are dynamic in nature

// Vectors
vector<int>v={1,2,34,6};
v.push_back(1);
v.pop_back();
v.emplace_back(4);

// ✅ 1. push_back()
// Takes an existing object and copies or moves it into the vector.

// You must construct the object before passing it in.
// std::vector<std::pair<int, std::string>> v;
// v.push_back(std::make_pair(1, "Muthres"));  // object created outside, then moved/copied in
// ✅ 2. emplace_back()
// Constructs the object in-place directly at the end of the vector.

// It calls the constructor of the object using the arguments you provide.

// Faster and avoids unnecessary copies/moves.
// v.emplace_back(1, "Muthres");  // constructs pair<int, string> directly in vector

for (int i = 0; i < v.size(); i++)
{
    cout<<v[i]<<" ";
}

// vector of pair
vector<pair<int,int>>vec={{2,4}};
vec.push_back({3,4});
vec.push_back({5,7});
vec.push_back({1,9});
cout<<endl;
for (auto a = vec.begin(); a != vec.end(); a++) {
        cout << a->first << " " << a->second << endl;
}

cout<<vec[0].first<<" " << vec.at(0).first<<" "<< vec.back().first;
vec.erase(vec.begin());
cout<<" "<<vec.at(0).first;

vec.erase(vec.begin(),vec.begin()+1); // vec.erase(startingPointer,EndPointer+1);

// vec.insert(iteratorPosition,value);
// vec.insert(startingPosition,times,val);
// vec.insert();
// vec.insert(vec.begin(), startingPointer,Endpointer);
// cout<<vec.size();
// v1.swap(v2); // here v1 and v2 are vectors
// Vec.clear() // it will clear vector,its mean delete all elements from this vec vector
// cout<<vec.empty(); it will return boolean value that vector is empty or not?

// vector of 5 length and initialize to 0
// vector<int>ve(5,0);
// vector<int>ve(5);
// // vector same as ve
// vector<int>ve2(ve);
return 0;
}

// 🔁 Quick Analogy
// Expression	Meaning	Example
// *ptr	Dereference the pointer	(*it).first
// ptr->member	Shortcut for (*ptr).member	it->first

// 💡 When to Use * and When to Use ->
// ✅ Use * when:
// You want to dereference a pointer or an iterator to get the actual object.

// vector<pair<int, int>> vec = {{1, 2}, {3, 4}};
// auto it = vec.begin();  // it is an iterator (like a pointer)

// // *it gives the pair<int, int>
// cout << (*it).first << " " << (*it).second << endl;
// ✅ Use -> when:
// You want to access a member of the object pointed to by a pointer or iterator — it's a shortcut for (*it).member.


// cout << it->first << " " << it->second << endl;  // same as above, cleaner
// 🔧 Quick Comparison
// You Have...	You Use...	Example
// Pointer p	*p	Get the object
// Pointer p	p->member	Access member of the object
// Iterator it	*it	Get the value
// Iterator it	it->member	Access member of the object

// 🧠 Visual Example
// Imagine this code:

// struct Student {
//     int id;
//     string name;
// };

// vector<Student> students = {{1, "Muthres"}, {2, "Golu"}};
// auto it = students.begin();  // it is like a pointer to Student
// Syntax	What it means
// *it	The actual Student object
// (*it).id	Accessing id from Student
// it->id	Same as above (shortcut)

// ✅ Tip: Use -> when working with iterators—it’s cleaner and preferred.