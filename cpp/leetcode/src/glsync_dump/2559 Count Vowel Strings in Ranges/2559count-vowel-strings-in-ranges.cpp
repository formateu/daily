class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        std::unordered_set<char> vowels{'a', 'e', 'i', 'o', 'u'};
        std::vector<int> rangeCount(words.size(), 0);
        std::vector<int> result(queries.size(), 0);
        for (int i = 0; i < words.size(); ++i) {
            const auto &word = words[i];
            if (vowels.contains(word.front()) && vowels.contains(word.back())) {
                rangeCount[i] = 1;
            }
            
            if (i != 0) {
                rangeCount[i] += rangeCount[i-1];
            }
        }

        for (int i = 0; i < queries.size(); ++i) {
            const auto &l = queries[i][0];
            const auto &r = queries[i][1];
            result[i] = rangeCount[r];
            if (l != r) {
                if (l > 0) {
                    result[i] -= rangeCount[l-1];
                }
            } else if (l > 0) {
                result[i] -= rangeCount[l-1];
            }
        }

        return result;
    }
};