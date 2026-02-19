class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        std::array<int, 3> dp{std::numeric_limits<int>::min()}, temp{};
        dp[0] = 0;
        
        for (int num : nums) {
            temp = dp;
            
            for (int i = 0; i < 3; i++) {
                if (dp[i] != std::numeric_limits<int>::min()) {
                    int newSum = dp[i] + num;
                    int remainder = newSum % 3;
                    temp[remainder] = max(temp[remainder], newSum);
                }
            }
            
            dp = temp;
        }
        
        return dp[0]; // maksymalna suma podzielna przez 3
    }
};