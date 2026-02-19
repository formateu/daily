class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        std::vector<int> dp(nums.size(), 1), prev(nums.size(), -1);
        int maxi = 0;
        std::sort(nums.begin(), nums.end());

        for (int i = 1; i < nums.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    prev[i] = j;
                }

                if (dp[i] > dp[maxi]) {
                    maxi = i;
                }
            }
        }

        std::vector<int> result;
        while (maxi != -1) {
            result.emplace_back(nums[maxi]);
            maxi = prev[maxi];
        }

        return result;
    }   
};