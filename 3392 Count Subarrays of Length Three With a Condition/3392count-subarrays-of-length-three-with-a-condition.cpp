class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int result = 0;
        for (int i = 0; i < nums.size() - 2; ++i) {
            if (static_cast<double>(nums[i] + nums[i+2]) == nums[i+1]/2.0) {
                ++result;
            }
        }

        return result;
    }

};