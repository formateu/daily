class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        std::sort(nums.begin(), nums.end());
        std::vector<std::vector<int>> result(nums.size() / 3, std::vector<int>(3, 0));

        for (int i = 0; i < nums.size(); i += 3) {
            if (nums[i+2] - nums[i] <= k) {
                result[i/3][0] = nums[i];
                result[i/3][1] = nums[i+1];
                result[i/3][2] = nums[i+2];
            } else {
                return {};
            }
        }

        return result;
    }
};