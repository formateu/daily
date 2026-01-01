class Solution {
public:
    int longestPalindrome(string s) {
        unordered_set<char> occ;
        int len = 0;

        for (const auto &c : s) {
            if (occ.contains(c)) {
                occ.erase(c);
                len += 2;
            } else {
                occ.emplace(c);
            }
        }

        if (!occ.empty()) {
            ++len;
        }

        return len;
    }
};