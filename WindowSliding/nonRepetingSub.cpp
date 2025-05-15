#include<bits/stdc++.h>
using namespace std;

int solve(string str) {
  if(str.size()==0)
      return 0;
  int maxans = INT_MIN;
  for (int i = 0; i < str.length(); i++) 
  {
    unordered_set < int > set;
    for (int j = i; j < str.length(); j++) 
    {
      if (set.find(str[j]) != set.end()) // if element if found so mark it as ans and break from the loop
      {
        // maxans = max(maxans, j - i);
        break;
      }
      maxans=max(maxans,j-i+1);
      set.insert(str[j]);
    }
  }
  return maxans;
}

int better(string str){
    int maxAns=0;
    int l=0,r=0;
    int n=str.length();
    unordered_set<int>s;
    while (r<n)
    {
        if(s.find(str[r])!=s.end()){
            maxAns=max(maxAns,r-l);
            while (l<r && str[l]!=str[r])
            {
                s.erase(str[l]);
                l++;
            }
            l++;            
        }
        maxAns=max(maxAns,r-l+1);
        s.insert(str[r]);
        r++;
    }
    return maxAns;
}

int lengthofLongestSubstring(string s) {
      vector < int > mpp(256, -1);

      int left = 0, right = 0;
      int n = s.size();
      int len = 0;
      while (right < n) {
        if (mpp[s[right]] != -1)
          left = max(mpp[s[right]] + 1, left);
        mpp[s[right]] = right;
        len = max(len, right - left + 1);
        right++;
      }
      return len;
}
int main() {
  string str = "abba";
  cout << "The length of the longest substring without repeating characters is " << better(str);
  return 0;
}