class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int result = -1;
        int prefixMin = nums[0];

        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > prefixMin) {
                if (const int diff = nums[i] - prefixMin; diff > result) {
                    result = diff;
                }
            } else {
                prefixMin = nums[i];
            }
        }

        return result;
    }
};