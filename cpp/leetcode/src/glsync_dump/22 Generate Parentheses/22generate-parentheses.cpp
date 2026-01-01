class Solution {
public:
    vector<string> generateParenthesis(int n) {
        std::vector<std::vector<std::string>> dp(n + 1);
        dp[0] = {""};

        for (int i = 1; i <= n; ++i) {
            std::vector<std::string> curr;
            for (int k = 0; k < i; ++k) {
                for (const std::string& left : dp[k]) {
                    for (const std::string& right : dp[i - 1 - k]) {
                        curr.emplace_back("(" + left + ")" + right);
                    }
                }
            }
            dp[i] = std::move(curr);
        }

        return dp[n];
    }
};