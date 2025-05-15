#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


    int characterReplacement(string s, int k) {
        int maxLen = 0;
        int n = s.length();
        // Check all possible substrings
        for (int i = 0; i < n; i++) {
            int count[26] = {0}; // Frequency array for characters A-Z
            int maxCount = 0; // Maximum frequency of a character in the current substring

            for (int j = i; j < n; j++) {
                count[s[j] - 'A']++; // Increment the frequency of the current character
                maxCount = max(maxCount, count[s[j] - 'A']); // Update maxCount
                
                // Calculate the number of characters to replace
                int windowSize = j - i + 1; // Current substring length
                int replacementsNeeded = windowSize - maxCount;

                // If replacements needed are within the allowed limit, update maxLen
                if (replacementsNeeded <= k) {
                    maxLen = max(maxLen, windowSize);
                }
            }
        }
        return maxLen;
    }
    int characterReplacement2(string s, int k) {
        int maxLen = 0;
        int n = s.length();

        // Check all possible substrings
        for (int i = 0; i < n; i++) {
            int count[26] = {0}; // Frequency array for characters A-Z
            int maxCount = 0; // Maximum frequency of a character in the current substring

            for (int j = i; j < n; j++) {
                count[s[j] - 'A']++; // Increment the frequency of the current character
                maxCount = max(maxCount, count[s[j] - 'A']); // Update maxCount
                
                // Calculate the number of characters to replace
                int windowSize = j - i + 1; // Current substring length
                int replacementsNeeded = windowSize - maxCount;

                // If replacements needed are within the allowed limit, update maxLen
                if (replacementsNeeded <= k) {
                    maxLen = max(maxLen, windowSize);
                }
                else{
                    break;
                }
            }
        }
        return maxLen;
    }

int characterReplacement2(string s, int k) {
        int maxLen = 0;
        int maxCount = 0;  // Max count of a single character in the current window
        unordered_map<char, int> charCount; // Count of characters in the current window
        int left = 0;

        for (int right = 0; right < s.length(); ++right) {
            charCount[s[right]]++;
            maxCount = max(maxCount, charCount[s[right]]); // Update the maxCount
            
            // If the current window size minus the maxCount is greater than k,
            // shrink the window from the left
            while ((right - left + 1) - maxCount > k) {
                charCount[s[left]]--;
                left++;
            }
            
            // Calculate the maximum length of valid substring
            maxLen = max(maxLen, right - left + 1);
        }
        return maxLen;
    }

int characterReplacement3(string s, int k) {
        int maxLen = 0;
        int maxCount = 0;  // Max count of a single character in the current window
        unordered_map<char, int> charCount; // Count of characters in the current window
        int left = 0;

        for (int right = 0; right < s.length(); ++right) {
            charCount[s[right]]++;
            maxCount = max(maxCount, charCount[s[right]]); // Update the maxCount
            
            // If the current window size minus the maxCount is greater than k,
            // shrink the window from the left
            if((right - left + 1) - maxCount > k) {
                charCount[s[left]]--;
                left++;
            }
            
            // Calculate the maximum length of valid substring
            maxLen = max(maxLen, right - left + 1);
        }
        return maxLen;
    }
int main() {
    
    string s = "AABABBA";
    int k = 1;
    cout <<characterReplacement(s, k) << endl; // Output: 4
    return 0;
}
