class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // std::unordered_map<char, int> freq;
        std::array<int, 128> freq;

        int l = 0;
        int result = 0;
        int sum = 0;
        for (int r = 0; r < s.size(); ++r) {
            ++sum;
            ++freq[s[r]];

            while (freq[s[r]] > 1) {
                --sum;
                --freq[s[l]];
                ++l;
            }

            result = std::max(sum, result);
        }

        return result;
    }
};