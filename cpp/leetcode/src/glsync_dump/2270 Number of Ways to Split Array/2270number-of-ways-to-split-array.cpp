// #include <cstdint>

class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        std::int64_t lSum = 0;
        std::int64_t rSum = std::accumulate(nums.begin(), nums.end(), static_cast<std::int64_t>(0));

        int result = 0;
        for (int i = 0; i < nums.size() - 1; ++i) {
            lSum += nums[i];
            rSum -= nums[i];
            if (lSum >= rSum) {
                ++result;
            }
        }
        
        return result;
    }
};