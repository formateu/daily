class Solution {
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        constexpr int MOD = 1'000'000'007;
        const int N = grid.size() + 1, M = grid[0].size() + 1;
        std::vector dp(N, std::vector<std::vector<int>>(M, std::vector<int>(k, 0)));

        dp[1][1][grid[0][0] % k] = 1;

        for (int i = 1; i < N; ++i) {
            for (int j = 1; j < M; ++j) {
                for (int r = 0; r < k; ++r) {
                    const int mod = (r + (grid[i-1][j-1] % k)) % k;
                    dp[i][j][mod] = (dp[i][j][mod] + dp[i-1][j][r]) % MOD;
                    dp[i][j][mod] = (dp[i][j][mod] + dp[i][j-1][r]) % MOD;
                }
            }
        }
        return dp[N-1][M-1][0];
    }
};