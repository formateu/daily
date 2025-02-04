class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int maxSum = 0, currentSum = nums[0];
        for (int i = 0, j = 1; j < nums.size(); ++i, ++j) {
            if (nums[i] < nums[j]) {
                currentSum += nums[j];
            } else {
                maxSum = std::max(currentSum, maxSum);
                currentSum = nums[j];
            }
        }

        return std::max(currentSum, maxSum);
    }
};