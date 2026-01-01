class Solution {
public:
    int minOperations(vector<int>& nums) {
        int count = 0;
        for (int i = 0; i < nums.size() - 2; ++i) {
            if (nums[i] == 0) {
                ++count;
                nums[i] ^= 1;
                nums[i+1] ^= 1;
                nums[i+2] ^= 1;
            }
        }

        int sum = std::accumulate(nums.begin(), nums.end(), 0);
        if (sum == nums.size()) {
            return count;
        }

        return -1;
    }
};