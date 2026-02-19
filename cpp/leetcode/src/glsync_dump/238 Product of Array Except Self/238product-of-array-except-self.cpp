class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prefixProd(nums.size(), 1), suffixProd(nums.size(), 1);

        for (int i = 1; i < nums.size(); ++i) {
            prefixProd[i] = prefixProd[i-1] * nums[i-1];
        }

        for (int i = nums.size() - 2; i >= 0; --i) {
            suffixProd[i] = suffixProd[i+1] * nums[i+1];
        }

        for (int i = 0; i < nums.size(); ++i) {
            nums[i] = prefixProd[i] * suffixProd[i];
        }

        return nums;
    }
};