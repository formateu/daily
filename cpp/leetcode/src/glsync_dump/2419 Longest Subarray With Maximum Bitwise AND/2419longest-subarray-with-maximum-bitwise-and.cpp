class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int max = 0, result = 0;
        for (int i : nums) {
            if (i > max) {
                max = i;
            }
        }

        for (int i = 0; i < nums.size();) {
            int curr = 0;
            while (i < nums.size() && nums[i] == max) {
                ++curr;
                ++i;
            }
            result = std::max(result, curr);
            if (curr == 0) ++i;
        }

        return result;
    }
};