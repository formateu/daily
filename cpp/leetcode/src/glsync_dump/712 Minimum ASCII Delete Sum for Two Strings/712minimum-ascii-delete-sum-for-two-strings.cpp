class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        const int N = static_cast<int>(s1.size());
        const int M = static_cast<int>(s2.size());
        std::vector<std::vector<int>> dp(N+1, std::vector<int>(M+1, 0));

        for (int i = N - 1; i >= 0; --i) {
            dp[i][M] = dp[i+1][M] + static_cast<int>(s1[i]);
        }

        for (int j = M - 1; j >= 0; --j) {
            dp[N][j] = dp[N][j+1] + static_cast<int>(s2[j]);

        }

        for (int i = N-1; i >= 0; --i) {
            for (int j = M-1; j >= 0; --j) {
                if (s1[i] == s2[j]) {
                    dp[i][j] = dp[i+1][j+1];
                } else {
                    dp[i][j] = std::min(dp[i+1][j] + static_cast<int>(s1[i]), dp[i][j+1] + static_cast<int>(s2[j]));
                }

            }
        }

        return dp[0][0];
    }
};