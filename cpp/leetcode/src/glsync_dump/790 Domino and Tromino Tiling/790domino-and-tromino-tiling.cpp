class Solution {
public:
    int numTilings(int n) {
        static constexpr int MOD = 1'000'000'007;
        if (n == 1) return 1;
        if (n == 2) return 2;

        std::array<std::array<long long, 2>, 3> dp = {{
            {{0, 0}},
            {{0, 1}},
            {{2, 2}}
        }};

        for (int i = 3; i <= n; ++i) {
            int idx = i % 3;
            int i1  = (i - 1) % 3;
            int i2  = (i - 2) % 3;

            auto &P = dp[idx][0];
            auto &F = dp[idx][1];

            P = (2 * dp[i2][1] + dp[i1][0]) % MOD;
            F = (dp[i1][1] + dp[i2][1] + dp[i1][0]) % MOD;
        }

        return int(dp[n % 3][1]);
    }
};