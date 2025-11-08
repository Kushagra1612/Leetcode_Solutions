#include <string>
#include <unordered_set>
#include <algorithm>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        if (s.empty()) {
            return 0;
        }

        std::unordered_set<char> charSet;
        int maxLen = 0;
        int left = 0;

        for (int right = 0; right < s.length(); ++right) {
            while (charSet.find(s[right]) != charSet.end()) {
                charSet.erase(s[left]);
                left++;
            }

            charSet.insert(s[right]);
            maxLen = std::max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};