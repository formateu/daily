class Solution {
public:
    string longestPalindrome(string s) {
        int max = 1;
        std::string result(1, s[0]);

        for (int i = 0; i < s.size(); ++i) {
            int l = i-1;
            int r = i+1;
            if (l >= 0 && r < s.size() && s[l] == s[r]) {
                while (l >= 0 && r < s.size() && s[l] == s[r]) {
                    --l;
                    ++r;
                }
                if (r - l + 1 > max) {
                    result = s.substr(l+1, r -l - 1);
                    max = r - l + 1;
                }
            }

            l = i;
            r = i+1;
            if (l >= 0 && r < s.size() && s[l] == s[r]) {
                while (l >= 0 && r < s.size() && s[l] == s[r]) {
                    --l;
                    ++r;
                }
                if (r - l + 1 > max) {
                    result = s.substr(l+1, r -l - 1);
                    max = r - l + 1;
                }
            }
        }

        return result;
    }
};