#include <iostream>
#include <string>
#include <set>
#include<unordered_map>
using namespace std;

int countSubstringsBruteForce(string s) {
    int n = s.length();
    int count = 0;
    for (int i = 0; i < n; i++) {
        set<char> charSet;
        for (int j = i; j < n; j++) {
            charSet.insert(s[j]);
            if (charSet.size() == 3) {
                count++;
            }
        }
    }

    return count;
}
int countSubstringsBruteForce2(string s) {
    int n = s.length();
    int count = 0;
    for (int i = 0; i < n; i++) {
        set<char> charSet;
        for (int j = i; j < n; j++) {
            charSet.insert(s[j]);
            if (charSet.size() == 3) {
               count+=n-j;
               break;
            }
        }
    }

    return count;
}

int countSubstringsOptimized3(string s) {
        int n = s.length();
        if (n < 3) return 0;
        int count = 0;
        int charCount[3] = {0};  
        int left = 0;  
        for (int right = 0; right < n; right++) {
            charCount[s[right] - 'a']++; 
            while (charCount[0] > 0 && charCount[1] > 0 && charCount[2] > 0) {
               count += (n - right); 
                charCount[s[left] - 'a']--;
                left++;
            }
        }
        return count;
}
// In above if we replce inside while loop with if condition then if will give wrong answer 
// in this case "aaacb"
int countSubstringsOptimized4(string s) {
       int n = s.length();
        int count = 0;
        int lastIndex[3] = {-1, -1, -1};         
        for (int right = 0; right < n; right++) {
            lastIndex[s[right] - 'a'] = right;
            if (lastIndex[0] != -1 && lastIndex[1] != -1 && lastIndex[2] != -1) {
                int minIndex = min({lastIndex[0], lastIndex[1], lastIndex[2]});
                count += (minIndex + 1);
            }
        }
        return count;
}


int main() {
    string s = "abcabc";
    cout << "Brute Force: " << countSubstringsBruteForce(s) << endl;
    return 0;
}
