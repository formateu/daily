class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        std::vector<int> dp(k*k, 0);
        int res = 0;
        for (int num : nums) {
            num %= k;
            for (int prev = 0; prev < k; ++prev) {
                dp[prev*k + num] = dp[num*k + prev] + 1;
                res = max(res, dp[prev*k + num]);
            }
        }
        return res;
    }
};