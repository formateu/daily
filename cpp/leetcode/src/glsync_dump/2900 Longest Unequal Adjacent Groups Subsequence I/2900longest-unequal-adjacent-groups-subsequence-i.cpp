class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        std::vector<string> result;
        result.emplace_back(words[0]);
 
        for (int i = 1; i < groups.size(); ++i) {
            if (groups[i] != groups[i-1]) {
                result.emplace_back(std::move(words[i]));
            }
        }

        return result;
    }
};