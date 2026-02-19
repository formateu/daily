class Solution {
public:
    int findLHS(vector<int>& nums) {
        std::unordered_map<int, int> freq;
        for (const auto &n: nums) {
            if (!freq.contains(n)) {
                freq.emplace(n, 1);
            } else {
                ++freq[n];
            }
        }

        int result = 0;
        for (const auto &[k, v] : freq) {
            if (freq.contains(k+1)) {
                result = std::max(result, freq[k] + freq[k+1]);
            }
        }

        return result;
    }
};