class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int result = 0;
        for (int i = 0; i < words.size() - 1; ++i) {
            for (int j = i + 1; j < words.size(); ++j) {
                if (words[j].starts_with(words[i]) && words[j].ends_with(words[i])) {
                    ++result;
                }
            }
        }

        return result;
    }
};