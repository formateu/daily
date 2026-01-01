class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        // const std::unordered_set<char> allowedSet(allowed.begin(), allowed.end());
        int result = 0;
        for (const auto &word: words) {
            int counter = 0;
            for (const auto &c: word) {
                if (allowed.contains(c)) {
                    ++counter;
                }
            }

            if (counter == word.size()) {
                ++result;
            }
        }

        return result;
    }
};

static const int kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();