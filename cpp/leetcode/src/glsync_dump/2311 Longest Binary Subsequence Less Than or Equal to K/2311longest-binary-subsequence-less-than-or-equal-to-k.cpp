class Solution {
public:
    int longestSubsequence(string s, int k) {
        int result = 0;
        long long value = 0, current = 1;
        for (int i = s.size() - 1; i >= 0; --i) {
            if (s.size() - 1 - i <= 31) {
                if (s[i] == '1' && value + current <= k) {
                    value += current;
                    ++result;
                }
                current *= 2;
            }
            if (s[i] == '0') {
                ++result;
            }
        }

        return result;
    }
};