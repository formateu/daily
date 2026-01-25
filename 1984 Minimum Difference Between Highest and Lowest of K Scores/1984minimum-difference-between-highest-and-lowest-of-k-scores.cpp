class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        if (k == 1) return 0;

        std::sort(nums.begin(), nums.end());
        int result = std::numeric_limits<int>::max();

        for (int i = 0; i < nums.size() - k + 1; ++i) {
            int currentResult = nums[i+k-1] - nums[i];
            if (currentResult < result) result = currentResult;
        }

        return result;
    }
};