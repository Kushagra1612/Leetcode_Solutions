class Solution {
public:
    int countHomogenous(string s) {
        long long res = 0;
        int left = 0;
        int mod = 1e9 + 7;

        for (int right = 0; right < s.length(); right++) {
            if (s[right] != s[left]) {
                left = right;
            }
            res += (right - left + 1);
            res %= mod;
        }

        return (int)res;
    }
};