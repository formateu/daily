class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        if (nums.size() == 1) {
            return 1;
        }
        
        std::sort(nums.begin(), nums.end());

        int result = 0;
        for (int i = 0, j = 1; j < nums.size();) {
            while (j < nums.size() && nums[j] - nums[i] <= k) {
                ++j;
            }
            ++result;
            i = j;
        }

        return result;
    }
};