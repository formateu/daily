class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        const int N = nums1.size();
        const int M = nums2.size();

        std::vector<std::vector<int>> dp(N, std::vector<int>(M, std::numeric_limits<int>::min()));

        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                int prod = nums1[i] * nums2[j];

                int bestPair = prod;
                if (i > 0 && j > 0) {
                    bestPair = prod + std::max(0, dp[i-1][j-1]);
                }

                int best = bestPair;
                if (i > 0) best = std::max(best, dp[i-1][j]);
                if (j > 0) best = std::max(best, dp[i][j-1]);

                dp[i][j] = best;
            }
        }

        return dp[N-1][M-1];
    }
};