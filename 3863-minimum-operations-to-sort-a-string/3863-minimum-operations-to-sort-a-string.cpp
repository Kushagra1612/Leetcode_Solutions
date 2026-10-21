
class Solution {
public:
    int minOperations(string s) {
        int n = s.length();

        string sorted = s;
        sort(sorted.begin(), sorted.end());

        if (s == sorted) return 0;

        if (n == 2) return -1;

        char minChar = sorted[0];
        char maxChar = sorted[n - 1];

        if (s[0] == minChar || s[n - 1] == maxChar) {
            return 1;
        }

        bool uniqueMax = true;
        bool uniqueMin = true;

        for (int i = 1; i < n; i++) {
            if (s[i] >= s[0]) {
                uniqueMax = false;
            }
        }

        for (int i = 0; i < n - 1; i++) {
            if (s[i] <= s[n - 1]) {
                uniqueMin = false;
            }
        }

        if (uniqueMax && uniqueMin) {
            return 3;
        }

        return 2;
    }
};
