class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int result = 0;
        for (const auto &word: words) {
            if (word.starts_with(pref)) {
                ++result;
            }
        }

        return result;
    }
};