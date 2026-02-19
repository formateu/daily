class Solution {
public:
    int numOfWays(int n) {
        constexpr int MOD = 1'000'000'007;

        long long a = 6; // ABA
        long long b = 6; // ABC

        for (int i = 2; i <= n; ++i) {
            long long na = (3*a + 2*b) % MOD;
            long long nb = (2*a + 2*b) % MOD;
            a = na;
            b = nb;
        }

        return (a + b) % MOD;
    }
};