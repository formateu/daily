class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int state = 0;
        int max = 0, current = 0;
        for (int i = 0, j = 0; i < nums.size();) {
            while (j < nums.size() && (state & nums[j]) == false) {
                state = state | nums[j];
                ++current;
                if (j < nums.size()) {
                    ++j;
                }
            }
            max = std::max(max, current);

            state &= ~nums[i];
            ++i;
            --current;
        }

        return max;
    }
};