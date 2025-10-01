class Solution {
private:
    const int MOD = 1e9 + 7;

    long long modularPower(long long base, long long exp) {
        long long result = 1;
        base %= MOD;

        while (exp > 0) {
            if (exp & 1) {
                result = (result * base) % MOD;
            }
            base = (base * base) % MOD;
            exp >>= 1;
        }
        return result;
    }

public:
    int countGoodNumbers(long long n) {
        long long count_of_fives = (n + 1) / 2;
        long long count_of_fours = n / 2;

        long long part1 = modularPower(5, count_of_fives);
        long long part2 = modularPower(4, count_of_fours);

        return (int)((part1 * part2) % MOD);
    }
};