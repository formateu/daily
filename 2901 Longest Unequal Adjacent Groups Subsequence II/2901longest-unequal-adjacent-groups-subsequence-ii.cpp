class Solution {
public:
    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        if (words.size() < 2) {
            return words;
        }

        std::vector<std::pair<int, int>> dp(words.size(), {0, -1});
        int max = -1, maxI = -1;

        for (int i = 1; i < dp.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (groups[i] != groups[j] && hammingDistanceOk(words[j], words[i])) {
                    if (dp[j].first >= dp[i].first) {
                        dp[i].first = dp[j].first + 1;
                        dp[i].second = j;
                    }
                }
            }
            if (dp[i].first > max) {
                max = dp[i].first;
                maxI = i;
            }
        }

        if (maxI == -1) {
            return {};
        }

        std::vector<std::string> result(max+1);
        for (int curr = maxI, i = max; i >= 0; --i) {
            result[i] = std::move(words[curr]);
            curr = dp[curr].second;
        }

        return result;
    }

private:
    bool hammingDistanceOk(const std::string &s1, const std::string &s2) {
        if (s1.size() != s2.size()) {
            return false;
        } 

        int result = 0;
        for (int i = 0; i < s1.size(); ++i) {
            if (s1[i] != s2[i]) {
                ++result;
                if (result > 1) {
                    return false;
                }
            }
        }

        return result == 1;
    }
};