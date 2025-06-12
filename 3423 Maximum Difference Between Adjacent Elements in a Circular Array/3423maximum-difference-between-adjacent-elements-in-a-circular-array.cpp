class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int maxDiff = 0;
        for (int i = 0, j = 1; j < nums.size(); ++i, ++j) {
            const int diff = std::abs(nums[i] - nums[j]);
            if (diff > maxDiff) {
                maxDiff = diff;
            }
        }

        const int diff = std::abs(nums[0] - nums[nums.size() -1]);
        if (diff > maxDiff) {
            maxDiff = diff;
        }

        return maxDiff;
    }
};