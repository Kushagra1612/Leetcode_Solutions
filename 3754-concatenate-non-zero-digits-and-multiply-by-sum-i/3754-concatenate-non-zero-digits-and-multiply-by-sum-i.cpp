class Solution {
public:
    long long sumAndMultiply(int n) {
        string s = to_string(n);

        long long sum = 0;
        long long x = 0;

        for (char c : s) {
            int digit = c - '0';

            if (digit == 0)
                continue;

            x = x * 10 + digit;
            sum += digit;
           
        }

        return x * sum;
    }
};