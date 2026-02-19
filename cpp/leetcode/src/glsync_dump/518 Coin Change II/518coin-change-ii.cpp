class Solution {
public:
    int change(int amount, vector<int>& coins) {
        std::vector<std::uint64_t> dp(amount + 1, 0);
        dp[0] = 1; 

        for (int c : coins) {
            for (int s = c; s <= amount; ++s) {
                dp[s] += dp[s - c];
            }
        }

        return dp[amount];
    }
};