class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = std::accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 != 0) {
            return false;
        } 

        sum /= 2;
        std::vector<bool> dp(sum + 1, false);
        dp[0] = true;
        for (int num : nums) {
            for (int currSum = sum; currSum >= num; --currSum) {
                dp[currSum] = dp[currSum] || dp[currSum - num];
                if (dp[sum]) return true;
            }
        }
        return dp[sum];
    }
};