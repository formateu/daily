class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        std::unordered_set<string> result;
        for (int i = 0; i < words.size(); ++i) {
            for (int j = 0; j < words.size(); ++j) {
                if (i == j) {
                    continue;
                }

                if (words[i].find(words[j]) != std::string::npos && !result.contains(words[j])) {
                    result.emplace(words[j]);
                }
            }
        }

        return std::vector<string>(result.begin(), result.end());
    }
};