class Solution {
public:
    int possibleStringCount(string word, int k) {
        constexpr int MOD = 1'000'000'007;
        std::vector<int> groups;
        for (int i = 0; i < word.size();) {
            int j = i+1;
            while (j < word.size() && word[i] == word[j]) {
                ++j;
            }

            groups.emplace_back(j-i);
            i = j;
        }

        long long result = 1;
        for (int i = 0; i < groups.size(); ++i) {
            result = (result * groups[i]) % MOD;
        }

        if (groups.size() >= k) {
            return result;
        }

        std::vector<int> dp1(k, 0), dp2(k, 0), prefix(k);
        dp1[0] = 1;
        const int last = std::min(static_cast<int>(groups.size()), k);
        for (int i = 1; i <= last; ++i) {
            const auto &prev_dp = (i % 2) ? dp1 : dp2;
            auto &dp = (i % 2) ? dp2 : dp1;
            dp[0] = 0;
            const int r = groups[i-1];
            prefix[0] = prev_dp[0];
            for (int j = 1; j < k; ++j) {
                prefix[j] = prefix[j-1] + prev_dp[j];
                if (prefix[j] >= MOD) {
                    prefix[j] -= MOD;
                }
            }
            int64_t window = 0;
            for (int j = 1; j < k; ++j) {
                window += prev_dp[j-1];
                if (j-1-r >= 0) window -= prev_dp[j-1-r];
                if (window >= MOD) window -= MOD;
                else if (window < 0) window += MOD;
                dp[j] = int(window);
            }
        }

        int bad = 0;
        const auto &dp = (last % 2) ? dp2 : dp1;
        for (int i = 0; i < k; ++i) {
            bad = (bad + dp[i]) % MOD;
        }

        result -= bad;
        if (result < 0) {
            result += MOD;
        }

        return result;
    }
};