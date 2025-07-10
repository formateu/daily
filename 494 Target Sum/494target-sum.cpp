class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int maxSum = 0;
        for (int num : nums) {
            maxSum += abs(num);
        }
        int n = nums.size();
        int W = 2 * maxSum + 1;
        int idx = maxSum + target;
        if (idx < 0 || idx >= W) return 0;

        std::vector<int> dp_prev(W, 0), dp_cur(W, 0);

        dp_prev[maxSum + nums[0]] += 1;
        dp_prev[maxSum - nums[0]] += 1;

        for (int k = 1; k < n; ++k) {
            int x = nums[k];
            std::fill(dp_cur.begin(), dp_cur.end(), 0);

            for (int s = 0; s < W; ++s) {
                int ways = dp_prev[s];
                if (!ways) continue;
                if (s + x < W)      dp_cur[s + x] += ways;
                if (s - x >= 0)     dp_cur[s - x] += ways;
            }
            dp_prev.swap(dp_cur);
        }

        return dp_prev[idx];
    }
};