#include <iostream>
#include <set>
#include <string>
#include<unordered_map>
using namespace std;
// Brute force 
int lengthOfLongestSubstringKDistinct(string s, int k) {
    int n = s.length();
    int maxLen = 0;
    for (int i = 0; i < n; i++) {
        set<char> distinctChars; 
        for (int j = i; j < n; j++) {
            distinctChars.insert(s[j]); 
            if (distinctChars.size() > k) {
                break; 
            }
            maxLen = max(maxLen, j - i + 1); 
        }
    }
    
    return maxLen;
}

// Optimized answer

int lengthOfLongestSubstringKDistinct(string s, int k) {
    int n = s.length();
    if (n == 0 || k == 0) return 0;    
    unordered_map<char,int>charCount;
    int left = 0, right = 0, maxLen = 0;
    while (right < n) {
        charCount[s[right]]++;
        while (charCount.size() > k) {
            charCount[s[left]]--;
            if (charCount[s[left]] == 0) {
                charCount.erase(s[left]); 
            }
            left++; 
        }        
        maxLen = max(maxLen, right - left + 1);  
        right++; 
    }
    
    return maxLen;
}
// more ptimized answer

int lengthOfLongestSubstringKDistinct(string s, int k) {
    int n = s.length();
    if (n == 0 || k == 0) return 0;    
    unordered_map<char,int>charCount;
    int left = 0, right = 0, maxLen = 0;
    while (right < n) {
        charCount[s[right]]++;
        if(charCount.size() > k) {
            charCount[s[left]]--;
            if (charCount[s[left]] == 0) {
                charCount.erase(s[left]); 
            }
            left++; 
        }        
        maxLen = max(maxLen, right - left + 1);  
        right++; 
    }
    
    return maxLen;
}


int main() {
    string s = "eceba";
    int k = 2;
    cout << "Brute Force: Longest Substring Length = " << lengthOfLongestSubstringKDistinct(s, k) << endl;
    return 0;
}
