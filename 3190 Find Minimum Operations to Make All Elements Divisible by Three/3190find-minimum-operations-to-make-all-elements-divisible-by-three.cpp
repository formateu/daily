class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int result = 0;
        for (int i = 0; i < nums.size(); ++i) {
            result += std::min((nums[i] % 3), 3 - (nums[i] % 3));
        }

        return result;
    }
};