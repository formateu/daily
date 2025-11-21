class Solution {
public:
    int countPalindromicSubsequence(string s) {
        if (s.size() < 3) {
            return 0;
        }

        std::array<int, 26> l{}, r{};
        std::array<std::array<bool, 26>, 26> m{}; 
        for (char c: s) {
            ++r[c - 'a'];
        }

        ++l[s[0] - 'a'];
        --r[s[0] - 'a'];


        int result = 0;
        for (int i = 1; i < s.size(); ++i) {
            --r[s[i] - 'a'];
            for (int j = 0 ; j < l.size(); ++j) {
                if (l[j] > 0 && r[j] > 0 && m[j][s[i] - 'a'] == false) {
                    m[j][s[i] - 'a'] = true;    
                    ++result;
                }
            }
            ++l[s[i] - 'a'];
        }

        return result;
    }
};