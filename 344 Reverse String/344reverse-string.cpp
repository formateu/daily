class Solution {
public:
    void reverseString(vector<char>& s) {
        for (int i = 0; i < s.size() / 2; ++i) {
            int mirrorPosition = s.size() - i - 1;
            char cache = s[mirrorPosition];
            s[mirrorPosition] = s[i];
            s[i] = cache;
        }
    }
};